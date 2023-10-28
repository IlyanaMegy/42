/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeaude <pabeaude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:47:53 by pabeaude          #+#    #+#             */
/*   Updated: 2023/09/21 17:39:56 by pabeaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_b.h"
#include <errno.h>

int	open_enter(char **argv)
{
	int	fd_infile;

	fd_infile = fileopen(argv[1], 0);
	if (fd_infile >= 0)
	{
		if (dup2(fd_infile, 0) == -1)
			perror("pipex");
		close(fd_infile);
		return (2);
	}
	else
	{
		perror(argv[1]);
		fd_infile = fileopen(NULL, 3);
		if (dup2(fd_infile, 0) == -1)
			perror("pipex");
		close(fd_infile);
		return (3);
	}
}

int	begin(int argc, char **argv)
{
	if (ft_strcmp(argv[1], "here_doc") == 0)
	{
		if (argc < 6)
			exit(write(2, "Error\nUse here_doc LIMITER cmd1 cmd2 outfile\n", 45));
		here_doc(argv);
		return (3);
	}
	else
		return (open_enter(argv));
}

void	end(int argc, char **argv)
{
	int	fd_outfile;

	if (ft_strcmp(argv[1], "here_doc") == 0)
	{
		fd_outfile = fileopen(argv[argc - 1], 2);
		if (dup2(fd_outfile, 1) == -1)
			perror("pipex");
		if (fd_outfile != -1)
			close(fd_outfile);
	}
	else
	{
		fd_outfile = fileopen(argv[argc - 1], 1);
		if (dup2(fd_outfile, 1) == -1)
			perror("pipex");
		if (fd_outfile != -1)
			close(fd_outfile);
	}
}

void	exec_path(char *cmd, char **env)
{
	char	**s_cmd;

	s_cmd = ft_split(cmd, ' ');
	if (execve(cmd, s_cmd, env) < 0)
	{
		write(2, "command not found: \n", 21);
		ft_putendl_fd(s_cmd[0], 2);
		ft_free_pipex(s_cmd);
		exit(127);
	}
}

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] - s2[i] != 0)
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}
