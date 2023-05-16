/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:56:36 by ilymegy           #+#    #+#             */
/*   Updated: 2023/05/16 15:56:40 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ptr_len(uintptr_t num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

void	print_ptr(uintptr_t num)
{
	if (num >= 16)
	{
		print_ptr(num / 16);
		print_ptr(num % 16);
	}
	else
	{
		if (num <= 9)
			p_char(num + '0');
		else
			p_char(num - 10 + 'a');
	}
}

int	p_ptr(unsigned long long ptr)
{
	int print_length;

	print_length = 0;
	print_length += write(1, "0x", 2);
	if (ptr == 0)
		print_length += write(1, "0", 1);
	else
	{
		print_ptr(ptr);
		print_length += ptr_len(ptr);
	}
	return (print_length);
}
