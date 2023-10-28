/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeaude <pabeaude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 09:47:40 by pabeaude          #+#    #+#             */
/*   Updated: 2022/12/06 13:02:14 by pabeaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*mem;

	if (size && nmemb > SIZE_MAX / size)
		return (NULL);
	mem = malloc(size * nmemb);
	if (!mem)
		return (NULL);
	ft_bzero(mem, nmemb * size);
	return (mem);
}
/*
int	main(void)
{
	//printf("%s\n", (char *)calloc(10, sizeof(char)));
	//printf("%s\n", (char *)ft_calloc(10, sizeof(char)));

	int		test_overflow;

	test_overflow = (int)(2147483647 * 2147483647);

	printf("result %d\n",test_overflow );

	return (0);
}
*/
