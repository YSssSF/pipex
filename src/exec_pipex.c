/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aoun <yel-aoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 14:31:02 by yel-aoun          #+#    #+#             */
/*   Updated: 2022/06/16 15:33:32 by yel-aoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_check_access(char *arg, int n)
{
	if (n == 0)
	{
		if (access(arg, R_OK) == -1)
		{
			perror("zsh : 0");
			exit(1);
		}
	}
	if (n == 1)
	{
		if (access(arg, W_OK) == -1)
		{
			perror("zsh : 1");
			exit(1);
		}
	}
	if (n == 2)
	{
		if (access(arg, F_OK) == -1)
		{
			perror("zsh : 2");
			exit(1);
		}
	}
}

char	*find_path(char **env)
{
	char	*save;
	int		i;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
			save = env[i];
		i++;
	}
	save = ft_substr(save, 5, ft_strlen(save) - 5);
	return (save);
}

char	*get_cmd(char *c_args, char **env)
{
	char	*path;
	char	**split_path;
	char	*cmd;
	int		i;

	i = 0;
	path = find_path(env);
	split_path = ft_split(path, ':');
	while (split_path[i])
	{
		cmd = ft_strjoin(split_path[i], c_args);
		if (access(cmd, X_OK) == 0)
			return (cmd);
		i++;
	}
	perror("zsh");
	exit(1);
}
