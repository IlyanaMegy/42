/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <apayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 16:18:03 by apayet            #+#    #+#             */
/*   Updated: 2022/05/24 11:40:20 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_set_args(int ac, char **av, char **envp)
{
	t_data	*data;

	data = ft_get_data_addr((t_data *)0);
	data->args.ac = ac;
	data->args.av = av;
	data->args.envp = envp;
}
