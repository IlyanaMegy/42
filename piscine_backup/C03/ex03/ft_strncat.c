/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 22:16:20 by ilymegy           #+#    #+#             */
/*   Updated: 2023/02/13 22:16:22 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	int				x;
	unsigned int	y;

	x = 0;
	while (dest[x])
		++x;
	y = 0;
	while (src[y] && (nb >= 1))
	{
		dest[x + y] = src[y];
		++y;
		--nb;
	}
	dest[x + y] = '\0';
	return (dest);
}
