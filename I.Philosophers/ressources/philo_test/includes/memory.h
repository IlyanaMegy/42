/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <apayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 12:30:35 by apayet            #+#    #+#             */
/*   Updated: 2022/05/23 15:31:57 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEMORY_H
# define MEMORY_H

void	*ft_memset(void *b, int c, size_t len);
void	*ft_memcpy(void	*dest, const void *src, size_t n);
void	ft_init_struct(void);

#endif