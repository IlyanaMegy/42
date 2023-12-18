/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <apayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 13:59:28 by apayet            #+#    #+#             */
/*   Updated: 2022/05/23 15:25:40 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*ft_memcpy(void	*dest, const void *src, size_t n)
{
	unsigned int	i;
	unsigned char	*p_src;
	unsigned char	*p_dest;

	i = 0;
	if (!dest && !src)
		return ((void *)0);
	p_src = (unsigned char *)src;
	p_dest = (unsigned char *)dest;
	while (i < n)
	{
		ft_memset(&p_dest[i], p_src[i], 1);
		i++;
	}
	return (dest);
}
