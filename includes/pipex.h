/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aoun <yel-aoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 13:43:54 by yel-aoun          #+#    #+#             */
/*   Updated: 2022/06/16 15:31:28 by yel-aoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

void	execute_cmd1(char **av, char **env, int pipe_id[2]);
void	execute_cmd2(char **av, char **env, int pipe_id[2]);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char *s, char c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_substr(char *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *str);
void	ft_check_access(char *arg, int n);
char	*get_cmd(char *c_args, char **env);
void	ft_error(void);

#endif