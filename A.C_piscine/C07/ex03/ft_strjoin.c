/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 19:45:27 by ilymegy           #+#    #+#             */
/*   Updated: 2023/02/22 19:45:30 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	dest_size;

	i = 0;
	dest_size = ft_strlen(dest);
	while (src[i])
	{
		dest[dest_size] = src[i];
		dest_size += 1;
		i += 1;
	}
	dest[dest_size] = '\0';
	return (dest);
}

int	ft_strs_size(int size, char **strs, char *sep)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (i < size)
	{
		len += ft_strlen(strs[i]);
		len += ft_strlen(sep);
		i += 1;
	}
	len -= ft_strlen(sep);
	return (len + 1);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	char	*str;

	i = 0;
	if (size >= 1)
	{
		str = (char *)malloc(sizeof(char) * (ft_strs_size(size, strs, sep)
					+ 1));
		if (!str)
			return (NULL);
		str[0] = 0;
		while (i < size)
		{
			ft_strcat(str, strs[i]);
			if (i < size - 1)
				ft_strcat(str, sep);
			i++;
		}
		return (str);
	}
	str = ((char *)malloc(sizeof(char)));
	*str = 0;
	return (str);
}

// int	main(void)
// {
// 	char *argv[4];
// 	argv[0] = "lol";
// 	argv[1] = "pouic";
// 	argv[2] = "";
// 	argv[3] = "youpiiii";

// 	char *res;

// 	res = ft_strjoin(4, argv, "1234");
// 	// lol1234pouic12341234youpiiii
// 	printf("%s\n", res);
// 	free(res);
// }