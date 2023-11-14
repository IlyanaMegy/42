/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 19:29:59 by ilymegy           #+#    #+#             */
/*   Updated: 2023/02/20 19:30:02 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	float	sqrt;
	float	temp;

	sqrt = nb / 2;
	temp = 0;
	if (nb < 0)
		return (0);
	while (sqrt != temp)
	{
		temp = sqrt;
		sqrt = (nb / temp + temp) / 2;
	}
	if ((int)temp - temp != 0)
		return (0);
	return (sqrt);
}
