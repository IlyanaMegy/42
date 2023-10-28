/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_b.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeaude <pabeaude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 12:08:21 by pabeaude          #+#    #+#             */
/*   Updated: 2023/09/21 17:38:45 by pabeaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_B_H
# define PIPEX_B_H

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
void	end(int argc, char **argv);
void	here_doc_put_in(char **argv, int *p_fd);
void	here_doc(char **argv);
void	linkpipe(char *cmd, char **env);
void	exec_path(char *cmd, char **env);
char	*find_path(char **env);
char	*get_exec(char *cmd, char **env);
int		fileopen(char *file, int option);
int		open_enter(char **argv);
int		begin(int argc, char **argv);
int		ft_strcmp(const char *s1, const char *s2);

#endif
