/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 23:32:38 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/05/29 11:06:30 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../../inc/pushswap.h"

t_ps	*ft_pslstnew(int content)
{
	t_ps	*pointer;

	pointer = (t_ps *)malloc(sizeof(t_ps));
	if (!(pointer))
		end_prog("", 1);
	pointer->content = content;
	pointer->next = NULL;
	pointer->prev = NULL;
	return (pointer);
}
