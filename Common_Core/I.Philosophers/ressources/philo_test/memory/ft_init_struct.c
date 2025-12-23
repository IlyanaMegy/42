/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <apayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 15:28:35 by apayet            #+#    #+#             */
/*   Updated: 2022/05/25 10:44:04 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_init_struct(void)
{
	t_data	*data;

	data = ft_get_data_addr((t_data *)0);
	if (!data)
		return ;
	ft_memset((void *)data, 0, sizeof(t_data));
}
