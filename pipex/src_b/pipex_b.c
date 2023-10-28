/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeaude <pabeaude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:49:14 by pabeaude          #+#    #+#             */
/*   Updated: 2023/09/22 13:57:56 by pabeaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_b.h"
#include <errno.h>

void	here_doc_put_in(char **argv, int *p_fd)
{
	char	*ret;

	close(p_fd[0]);
	while (1)
	{
		ret = get_next_line(0);
		if (ft_strncmp(ret, argv[2], ft_strlen(argv[2])) == 0
			&& ft_strlen(argv[2]) == strlen(ret) - 1)
		{
			get_next_line(-99);
			free(ret);
			close(p_fd[1]);
			exit(0);
		}
		ft_putstr_fd(ret, p_fd[1]);
		free(ret);
	}
}

void	here_doc(char **argv)
{
	int		p_fd[2];
	pid_t	pid;

	if (pipe(p_fd) == -1)
		exit(0);
	pid = fork();
	if (pid == -1)
		exit(0);
	if (!pid)
		here_doc_put_in(argv, p_fd);
	else
	{
		close(p_fd[1]);
		if (dup2(p_fd[0], 0) == -1)
			perror("pipex");
		close(p_fd[0]);
		wait(NULL);
	}
}

void	linkpipe(char *cmd, char **env)
{
	int		p_fd[2];
	pid_t	pid;

	if (pipe(p_fd) == -1)
		exit(0);
	pid = fork();
	if (pid == -1)
		exit(0);
	if (!pid)
	{
		close(p_fd[0]);
		if (dup2(p_fd[1], 1) == -1)
			perror("pipex");
		close(p_fd[1]);
		if (cmd[0] == '/')
			exec_path(cmd, env);
		make_exec(cmd, env);
	}
	else
	{
		close(p_fd[1]);
		if (dup2(p_fd[0], 0) == -1)
			perror("pipex");
		close(p_fd[0]);
	}
}

int	main(int argc, char **argv, char **env)
{
	int		i;
	pid_t	pid;

	if (argc < 5)
	{
		write(2, "use |infile cmd cmd outfile| arguments\n", 39);
		return (0);
	}
	i = begin(argc, argv);
	while (i < argc - 2)
		linkpipe(argv[i++], env);
	end(argc, argv);
	pid = fork();
	if (!pid)
	{
		if (argv[argc - 2][0] == '/')
			exec_path(argv[argc - 2], env);
		make_exec(argv[argc - 2], env);
	}
	while (wait(NULL) > 0)
		;
	return (0);
}
