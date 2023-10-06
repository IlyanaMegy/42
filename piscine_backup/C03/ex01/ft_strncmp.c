/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 21:49:26 by ilymegy           #+#    #+#             */
/*   Updated: 2023/02/13 21:49:28 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	int	i;

	i = 0;
	if (s1[i] && s2[i])
	{
		while (s1[i] && s2[i] && (n > 1))
		{
			if (s1[i] - s2[i])
				return (s1[i] - s2[i]);
			++i;
			--n;
		}
		return (s1[i] - s2[i]);
	}
	return (s1[i] - s2[i]);
}
