/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeaude <pabeaude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 11:45:07 by pabeaude          #+#    #+#             */
/*   Updated: 2023/09/21 17:40:45 by pabeaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"
#include <errno.h>

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
	if (!s_cmd[0])
		write(2, "command not found: \n", 21);
	path = get_exec(s_cmd[0], env);
	if (execve(path, s_cmd, env) < 0)
	{
		write(2, "command not found: \n", 21);
		ft_putendl_fd(s_cmd[0], 2);
		ft_free_pipex(s_cmd);
		exit(127);
	}
}

int	child2(char **argv, int *p_fd, char **env)
{
	int		outfile;
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		close(p_fd[1]);
		outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (outfile < 0)
		{
			perror(argv[4]);
			close(p_fd[0]);
			exit(0);
		}
		if (dup2(outfile, 1) == -1)
			perror("pipex");
		if (dup2(p_fd[0], 0))
			perror("pipex");
		close(p_fd[0]);
		close(outfile);
		if (argv[3][0] == '/')
			exec_path(argv[3], env);
		make_exec(argv[3], env);
	}
	return (pid);
}

int	child(char **argv, int *p_fd, char **env)
{
	int		infile;
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		close(p_fd[0]);
		infile = open(argv[1], O_RDONLY, 0644);
		if (infile < 0)
		{
			perror(argv[1]);
			close (p_fd[1]);
			exit(0);
		}
		if (dup2(infile, 0) == -1)
			perror("pipex");
		close(infile);
		if (dup2(p_fd[1], 1) == -1)
			perror("pipex");
		close(p_fd[1]);
		if (argv[2][0] == '/')
			exec_path(argv[2], env);
		make_exec(argv[2], env);
	}
	return (pid);
}

int	main(int argc, char **argv, char **env)
{
	int	p_fd[2];
	int	pids[2];

	if (argc != 5)
		return (write(2, "use |infile cmd cmd outfile| arguments\n",
				39));
	if (pipe(p_fd) == -1)
		return (write(2, "error with opening the pipes\n", 29));
	pids[0] = child(argv, p_fd, env);
	pids[1] = child2(argv, p_fd, env);
	close(p_fd[0]);
	close(p_fd[1]);
	waitpid(pids[0], NULL, 0);
	waitpid(pids[1], NULL, 0);
}
