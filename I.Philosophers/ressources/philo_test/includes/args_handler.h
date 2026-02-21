/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_handler.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <apayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 16:24:44 by apayet            #+#    #+#             */
/*   Updated: 2022/05/24 12:53:44 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARGS_HANDLER_H
# define ARGS_HANDLER_H

void	ft_set_args(int ac, char **av, char **envp);
char	**ft_get_envp(void);
char	**ft_get_av(void);
int		ft_get_ac(void);
int		ft_check_args(void);
int		ft_check_av_only_allowed_char(void);
int		ft_is_argc(void);

#endif