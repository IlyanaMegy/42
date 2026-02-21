/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_arc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <apayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 15:07:08 by apayet            #+#    #+#             */
/*   Updated: 2022/05/23 15:26:20 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

char	*ft_strdup_arc(const char *s1)
{
	t_data	*data;
	char	*res;
	size_t	len;

	data = (t_data *)ft_get_data_addr((t_data *)0);
	len = ft_strlen((char *)s1);
	res = (char *) ft_malloc(data, sizeof(*res), len + 1);
	if (!res)
		return ((char *)0);
	ft_memcpy(res, s1, len + 1);
	return (res);
}
