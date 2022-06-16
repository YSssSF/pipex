/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aoun <yel-aoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 13:44:20 by yel-aoun          #+#    #+#             */
/*   Updated: 2022/06/16 17:52:17 by yel-aoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/pipex.h"

void	ft_check_error(int i)
{
	if (i == -1)
	{
		perror("invalid fork");
		exit (0);
	}
}

int	ft_check_execute(char *arg)
{
	if (access(arg, X_OK) == -1)
		return (0);
	return (1);
}

void	execute_cmd1(char **av, char **env, int pipe_id[2])
{
	int		fd;
	char	*cmd;
	char	**c_args;

	ft_check_access(av[1], 2);
	ft_check_access(av[1], 0);
	c_args = ft_split(av[2], ' ');
	if (ft_check_execute(c_args[0]))
		cmd = c_args[0];
	else
	{
		cmd = ft_strjoin("/", c_args[0]);
		cmd = get_cmd(cmd, env);
	}
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		ft_error();
	close(pipe_id[0]);
	dup2(fd, 0);
	dup2(pipe_id[1], 1);
	close(pipe_id[1]);
	close(fd);
	if (execve(cmd, c_args, env) == -1)
		ft_error();
}

void	execute_cmd2(char **av, char **env, int pipe_id[2])
{
	int		fd;
	char	*cmd;
	char	**c_args;

	fd = open(av[4], O_CREAT | O_RDWR | O_TRUNC, 0600);
	if (fd == -1)
		ft_error();
	ft_check_access(av[4], 2);
	c_args = ft_split(av[3], ' ');
	if (ft_check_execute(c_args[0]))
		cmd = c_args[0];
	else
	{
		cmd = ft_strjoin("/", c_args[0]);
		cmd = get_cmd(cmd, env);
	}
	close(pipe_id[1]);
	dup2(fd, 1);
	dup2(pipe_id[0], 0);
	close(pipe_id[0]);
	close(fd);
	if (execve(cmd, c_args, env) == -1)
		ft_error();
}

int	main(int ac, char **av, char **env)
{
	int	id;
	int	id2;
	int	pipe_id[2];

	if (ac != 5)
		return (0);
	if (pipe(pipe_id) == -1)
		return (0);
	id = fork();
	ft_check_error(id);
	if (id == 0)
		execute_cmd1(av, env, pipe_id);
	id2 = fork();
	ft_check_error(id2);
	if (id2 == 0)
		execute_cmd2(av, env, pipe_id);
	close(pipe_id[0]);
	close(pipe_id[1]);
	while (wait(NULL) != -1)
	{
	}
	return (0);
}
