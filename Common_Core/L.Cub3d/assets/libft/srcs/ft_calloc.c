/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltorkia <ltorkia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 12:23:22 by ltorkia           #+#    #+#             */
/*   Updated: 2023/05/06 12:23:22 by ltorkia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (size != 0 && nmemb * size / size != nmemb)
		return (0);
	ptr = (void *)malloc(nmemb * size);
	if (!ptr)
		return (0);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}
