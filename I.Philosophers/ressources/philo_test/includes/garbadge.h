/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbadge.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <apayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 12:23:45 by apayet            #+#    #+#             */
/*   Updated: 2022/05/25 16:21:32 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GARBADGE_H
# define GARBADGE_H

void	*ft_malloc(t_data *data, int size, int nbr);
void	ft_free_all_ref(void);

#endif