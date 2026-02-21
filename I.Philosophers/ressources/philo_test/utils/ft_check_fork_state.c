/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_fork_state.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <apayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 17:20:15 by apayet            #+#    #+#             */
/*   Updated: 2022/07/28 13:03:25 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

/**
 * @brief This function check and count	 how many fork is taken at the end 
 * 			of the pthread_join
 * 
 */
void	ft_check_fork_state(void)
{
	t_clist	*alst;
	t_philo	*philo;
	int		fork_taken;

	fork_taken = 0;
	alst = ft_get_philo_clist_addr((t_clist *)0);
	if (alst == (t_clist *)0)
		return ;
	while (alst->is_last != 1)
	{
		philo = (t_philo *)alst->content;
		if (philo->left_hand)
			fork_taken += 1;
		if (philo->right_hand)
			fork_taken += 1;
		alst = alst->next;
	}
	philo = (t_philo *)alst->content;
	if (philo->left_hand)
		fork_taken += 1;
	if (philo->right_hand)
		fork_taken += 1;
}
