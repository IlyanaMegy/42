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

	// close(p_fd[0]);
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

// void	here_doc(char **av)
// {
// 	here_doc_put_in(av, p_fd);
// 	close(p_fd[1]);
// 	if (dup2(p_fd[0], 0) == -1)
// 		exit_handler("__ERROR_PIPE__:\nError pipe.\n");
// 	close(p_fd[0]);
// 	wait(NULL);
// }

void	do_pipe(int *i, int *p_fd, char **av, char **env)
{
	int	j;
	int fd_in;

	if (!i[0])
	{
		j = 2;
		fd_in = open_file(av[1], 0);
		if (dup2(fd_in, 0) == -1)
			exit_handler("__ERROR_PIPE__:\nError pipe.\n");
		close(fd_in);
		// j = open_it(i[1], av, p_fd);
		if (dup2(p_fd[1], 1) == -1)
			exit_handler("__ERROR_PIPE__:\nError pipe.\n");
	}
	else if (i[0] == i[1] - 4)
	{
		close_it(i[1], av);
		if (dup2(p_fd[2], 0) == -1)
			exit_handler("__ERROR_PIPE__:\nError pipe.\n");
	}
	else
	{
		dup2(p_fd[2], 0);
		dup2(p_fd[1], 1);
	}
	close(p_fd[1]);
	close(p_fd[0]);
	close(p_fd[2]);
	exec(av[i[0] + j], env);
}

int	main(int ac, char **av, char **env)
{
	int		i[3];
	pid_t	pid[10000];
	int		p_fd[3];

	if (ac < 5)
		exit_handler("__ERROR_ARGS__:\nInvalid number of args.\n");
	i[0] = -1;
	i[1] = ac;
	p_fd[2] = dup(STDIN_FILENO);
	while (++i[0] < ac - 3)
	{
		if (pipe(p_fd) == -1)
			exit_handler("__ERROR_PIPE__:\nError pipe.\n");
		pid[i[0]] = fork();
		if (pid[i[0]] == -1)
			exit_handler("__ERROR_FORK__:\nError fork.\n");
		if (pid[i[0]] == 0)
			do_pipe(i, p_fd, av, env);
		transfert(p_fd);
	}
	close(p_fd[2]);
	i[0] = -1;
	while (++i[0] < ac - 3)
		waitpid(pid[i[0]], &i[2], 0);
	return (0);
}
