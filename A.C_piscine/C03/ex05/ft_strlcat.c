/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 11:12:05 by ilymegy           #+#    #+#             */
/*   Updated: 2023/02/14 11:12:06 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	len(char *str)
{
	int	n;

	n = 0;
	while (str[n] != '\0')
	{
		++n;
	}
	return (n);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	int				x;
	unsigned int	len_dest;
	unsigned int	len_src;

	len_dest = len(dest);
	len_src = len(src);
	if (size)
	{
		if (size < len_dest)
			len_src += size;
		else
			len_src += len_dest;
		x = 0;
		while (src[x] && (len_dest + x) < size - 1)
		{
			dest[len_dest + x] = src[x];
			++x;
		}
		dest[len_dest + x] = '\0';
		return (len_src);
	}
	return (len_src);
}
