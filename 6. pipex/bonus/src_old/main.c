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

void	here_doc_put_in(char **av, int *p_fd)
{
	char	*ret;
	t_gnl	*clear;

	close(p_fd[0]);
	while (1)
	{
		clear = malloc(sizeof(t_gnl));
		if (!clear)
			return ;
		ret = get_next_line(0, 0, &clear);
		if (ft_strncmp(ret, av[2], ft_strlen(av[2])) == 0)
		{
			free(ret);
			free(clear->content);
			free(clear);
			exit(0);
		}
		ft_putstr_fd(ret, p_fd[1]);
		free(ret);
	}
}

void	here_doc(char **av)
{
	int		p_fd[2];
	pid_t	pid;

	if (pipe(p_fd) == -1)
		exit_handler("__ERROR_PIPE__:\nError pipe.\n");
	pid = fork();
	if (pid == -1)
		exit_handler("__ERROR_FORK__:\nError fork.\n");
	if (!pid)
		here_doc_put_in(av, p_fd);
	else
	{
		close(p_fd[1]);
		if (dup2(p_fd[0], 0) == -1)
			exit_handler("__ERROR_PIPE__:\nError pipe.\n");
		close(p_fd[0]);
		wait(NULL);
	}
}

void	do_pipe(int *i, int *p_fd, char *cmd, char **env)
{
	if (!i[0])
	{
		if (dup2(p_fd[1], 1) == -1)
			exit_handler("__ERROR_PIPE__:\nError pipe.\n");
		close(p_fd[1]);
		
	}
	else if ()
	{
		if (dup2(p_fd[1], 1) == -1)
			exit_handler("__ERROR_PIPE__:\nError pipe.\n");
	}
	else
	{
		transfert(p_fd);
		close(p_fd[1]);
		close(p_fd[0]);
	}
	exec(cmd, env);
}

int	main(int ac, char **av, char **env)
{
	int		j;
	int i[3];
	pid_t	pid[10000];
	int		p_fd[3];

	if (ac < 5)
		exit_handler("__ERROR_ARGS__:\nInvalid number of args.\n");
	j = open_it(ac, av);
	p_fd[2] = dup(STDIN_FILENO);
	while (i < ac - 3)
	{
		if (pipe(p_fd) == -1)
			exit_handler("__ERROR_PIPE__:\nError pipe.\n");
		pid[i[0]] = fork();
		if (pid[i[0]] == -1)
			exit_handler("__ERROR_FORK__:\nError fork.\n");
		else if (pid[i[0]] == 0)
			do_pipe(pid, p_fd, av[j++], env);
	}
	pid = fork();
	close_it(ac, av);
	if (!pid)
		exec(av[ac - 2], env);
	while (wait(NULL) > 0)
		;
	return (0);
}
