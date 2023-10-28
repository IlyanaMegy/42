/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeaude <pabeaude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 15:55:56 by pabeaude          #+#    #+#             */
/*   Updated: 2022/12/06 13:13:27 by pabeaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while (big[i])
	{
		j = 0;
		while ((i + j) < len && little[j] == big[i + j]
			&& little[j] && big[i + j])
		{
			j++;
		}
		if (little[j] == '\0')
			return ((char *)&big[i]);
		i++;
	}
	return (NULL);
}
/*
int	main()
{
	if (ft_strnstr("sylvannat", "anna", 2) == NULL)
	{
		printf("C NUL");
		return(0);
	}

	printf("result %s\n", ft_strnstr("sylvannat", "anna", 2));
}
*/
