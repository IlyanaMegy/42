/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 11:46:11 by ilymegy           #+#    #+#             */
/*   Updated: 2023/02/10 11:53:49 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	n;

	n = 0;
	while (str[n] != '\0')
	{
		++n;
	}
	return (n);
}

// int main()
// {
// 	char	my_str[] = "hello world !";
// 	printf("len of %s = %d\n", my_str, ft_strlen(my_str));
// 	return 0;
// }