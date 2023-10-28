/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 17:42:51 by ilymegy           #+#    #+#             */
/*   Updated: 2023/10/10 17:42:53 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	exec(char *cmd, char **env)
{
	char	**s_cmd;
	char	*path;

	s_cmd = ft_split(cmd, ' ');
	path = get_path(s_cmd[0], env);
	if (execve(path, s_cmd, env) == -1)
	{
		ft_putstr_fd("Pipex: command not found: ", 2);
		ft_putendl_fd(s_cmd[0], 2);
		ft_free_tab(s_cmd);
		exit(127);
	}
}

void	child(char **av, int *p_fd, char **env, int i)
{
	int	fd;

	if (i == 0)
	{
		fd = open_file(av[1], 0);
		
		dup2(p_fd[1], 1);
		dup2(fd, 0);
		close(p_fd[0]);
		close(fd);
		if (env)
			exec(av[2], env);
	}
	fd = open_file(av[4], 1);
	
	dup2(p_fd[0], 0);
	dup2(fd, 1);
	close(p_fd[1]);
	close(fd);
	if (env)
		exec(av[3], env);
}

int	main(int ac, char **av, char **env)
{
	int		p_fd[2];
	pid_t	pid[2];
	int		i;
	int		err;

	if (ac != 5)
		exit_handler("__ERROR_ARGS__:\nInvalid number of args.\n");
	if (pipe(p_fd) == -1)
		exit_handler("__ERROR_PIPE__:\nError pipe.\n");
	i = -1;
	while (++i < 2)
	{
		pid[i] = fork();
		if (pid[i] == -1)
			exit_handler("__ERROR_FORK__:\nError fork.\n");
		if (!pid[i])
			child(av, p_fd, env, i);
	}
	i = -1;
	close(p_fd[0]);
	close(p_fd[1]);
	while (++i < 2)
		waitpid(pid[i], &err, WUNTRACED);
	return (0);
}
