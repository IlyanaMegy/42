/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_b_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeaude <pabeaude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:31:49 by pabeaude          #+#    #+#             */
/*   Updated: 2023/09/21 17:40:23 by pabeaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_b.h"
#include <errno.h>

void	ft_free_pipex(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

char	*find_path(char **env)
{
	int		i;

	i = 0;
	while (ft_strncmp("PATH", env[i], 4))
		i++;
	return (env[i] + 5);
}

int	fileopen(char *file, int option)
{
	int	fd;

	if (option == 0)
		return (open(file, O_RDONLY, 0644));
	if (option == 1)
		fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (option == 2)
		fd = open(file, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (option == 3)
		return (open("/tmp/pipextmp", O_RDONLY | O_CREAT, 0644));
	if (fd < 0)
		perror(file);
	return (fd);
}

char	*get_exec(char *cmd, char **env)
{
	int		i;
	char	*exec;
	char	*path_part;
	char	**path;
	char	**s_cmd;

	i = -1;
	path = ft_split(find_path(env), ':');
	s_cmd = ft_split(cmd, ' ');
	while (path[++i])
	{
		path_part = ft_strjoin(path[i], "/");
		exec = ft_strjoin(path_part, s_cmd[0]);
		free(path_part);
		if (access(exec, F_OK | X_OK) == 0)
		{
			ft_free_pipex(path);
			ft_free_pipex(s_cmd);
			return (exec);
		}
		free(exec);
	}
	ft_free_pipex(path);
	ft_free_pipex(s_cmd);
	return (cmd);
}

void	make_exec(char *cmd, char **env)
{
	char	**s_cmd;
	char	*path;

	s_cmd = ft_split(cmd, ' ');
	path = get_exec(s_cmd[0], env);
	if (execve(path, s_cmd, env) < 0)
	{
		write(2, "command not found: ", 20);
		ft_putendl_fd(s_cmd[0], 2);
		ft_free_pipex(s_cmd);
		exit(0);
	}
}
