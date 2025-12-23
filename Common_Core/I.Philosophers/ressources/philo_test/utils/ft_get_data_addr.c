/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_data_addr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <apayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 15:09:53 by apayet            #+#    #+#             */
/*   Updated: 2022/05/25 10:44:17 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

t_data	*ft_get_data_addr(t_data *p_data)
{
	static t_data	*data = (t_data *)0;

	if (p_data != (t_data *)0)
		data = (t_data *)p_data;
	return (data);
}
