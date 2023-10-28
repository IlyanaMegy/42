/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeaude <pabeaude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 12:30:44 by pabeaude          #+#    #+#             */
/*   Updated: 2023/09/21 17:38:37 by pabeaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <sys/wait.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "../libft/libft.h"

void	ft_free_pipex(char **tab);
void	make_exec(char *cmd, char **env);
void	exec_path(char *cmd, char **env);
char	*find_path(char **env);
char	*get_exec(char *cmd, char **env);
int		child(char **argv, int *p_fd, char **env);
int		child2(char **argv, int *p_fd, char **env);

#endif
