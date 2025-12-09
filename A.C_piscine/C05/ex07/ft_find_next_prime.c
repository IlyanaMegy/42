/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 10:46:36 by ilymegy           #+#    #+#             */
/*   Updated: 2023/02/21 10:46:38 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	c;
	int	i;

	i = 1;
	c = 0;
	while (i <= nb)
	{
		if (nb % i == 0)
			++c;
		++i;
	}
	if (c > 2)
		return (0);
	return (1);
}

int ft_find_next_prime(int nb)
{
	if (nb <= 1)
		return (0);
	while (!ft_is_prime(nb))
		++nb;
	return (nb);
}