/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 18:07:00 by ilymegy           #+#    #+#             */
/*   Updated: 2023/02/19 18:07:03 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# include <stdlib.h>
# include <unistd.h>

extern void	g_aff_table(void);
extern int	g_check_entry(int argc, char *str);
extern void	g_convert_to_array(char *str);
extern int	g_len_str(char *str);
extern int	compt_up(int pos);
extern int	compt_down(int pos);
extern int	compt_left(int pos);
extern int	compt_right(int pos);
extern int	check_height_neighbors(int pos);
extern int	check_height_clues(int pos);
extern int	check_full_height(void);
extern int	resolve_towerdoku(void);

extern int	*g_table;
extern int	*g_clues_list;
#endif
