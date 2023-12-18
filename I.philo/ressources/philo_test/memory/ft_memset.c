/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <apayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 12:29:54 by apayet            #+#    #+#             */
/*   Updated: 2022/05/23 15:25:35 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned int	i;
	unsigned char	*pb;

	i = 0;
	pb = (unsigned char *) b;
	while (i < len)
	{
		pb[i] = (unsigned char)c;
		i++;
	}
	return (b);
}
