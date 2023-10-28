/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeaude <pabeaude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 14:50:39 by pabeaude          #+#    #+#             */
/*   Updated: 2023/09/21 17:40:59 by pabeaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

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
