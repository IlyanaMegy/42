/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 15:29:48 by ilymegy           #+#    #+#             */
/*   Updated: 2023/10/03 15:29:50 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pushswap.h"

void	swap_it(int *xp, int *yp)
{
	int	temp;

	temp = *xp;
	*xp = *yp;
	*yp = temp;
}

/*
** function to perform selection sort.
*/
void	quick_sort(int *arr, int n)
{
	int	i;
	int	j;
	int	min_idx;

	i = 0;
	while (i < n - 1)
	{
		min_idx = i;
		j = i + 1;
		while (j < n)
		{
			if (arr[j] < arr[min_idx])
				min_idx = j;
			j++;
		}
		swap_it(&arr[min_idx], &arr[i]);
		i++;
	}
}
