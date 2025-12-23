/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_thread_philo.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <alex-rdc@live.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 14:39:42 by apayet            #+#    #+#             */
/*   Updated: 2022/08/04 10:47:50 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static void	eating_sub_routine(void *element, t_philo *philo)
{
	check_death_before_action(philo, ACTION_DEFAULT);
	if (is_one_philo_has_died())
		return ;
	ft_take_fork_priority(element, philo);
	if (is_one_philo_has_died())
	{
		drop_mutex_taken(philo);
		return ;
	}
	ft_eating(element);
	if (is_one_philo_has_died())
	{
		drop_mutex_taken(philo);
		return ;
	}
	set_launch_timestamp(philo);
	check_death_before_action(philo, ACTION_EAT);
	drop_mutex_taken(philo);
}

static void	*routine(void *element, t_philo *philo)
{
	while (1)
	{
		eating_sub_routine(element, philo);
		check_death_before_action(philo, ACTION_DEFAULT);
		if (is_one_philo_has_died())
			return (NULL);
		ft_sleeping(element);
		check_death_before_action(philo, ACTION_SLEEP);
		if (is_one_philo_has_died())
			return (NULL);
		ft_thinking(element);
		check_death_before_action(philo, ACTION_THINK);
		if (is_one_philo_has_died())
			return (NULL);
		if (is_end_of_dinner(philo))
			return (NULL);
	}
}

/**
 * @brief			This is the first time the dinner start 
 * 						A delay is setted for right taking of the fork
 * @param element 	This is the philo, 
 * 						the function need to have a (void *) 
 * 						inside parameters of the pthread  create
 * @return void* 	The return value, for now just setted by NULL ((void *)0)
 */
static void	*init_routine(void *element)
{
	t_philo	*philo;

	philo = (t_philo *)element;
	set_launch_timestamp(philo);
	philo->left_hand = ft_get_left_fork(philo->id);
	philo->right_hand = ft_get_right_fork(philo->id);
	philo->left_fork_taken = 0;
	philo->right_fork_taken = 0;
	if (ft_get_data_addr((void *)0)->nbr_of_philo == 1)
		return (alone_philo_routine(element));
	routine(element, philo);
	return (NULL);
}

/**
 * @brief this functionn create the thread of each philo
 * 
 */
void	ft_create_thread_philo_even(void)
{
	t_clist	*philo_clst;
	t_philo	*el;
	int		id;

	id = 0;
	philo_clst = ft_get_philo_clist_addr((t_clist *)0);
	while (philo_clst->is_last != 1)
	{
		el = (t_philo *)philo_clst->content;
		if (id % 2 == 0)
			pthread_create(&(el->thread_id), NULL, &init_routine, el);
		philo_clst = philo_clst->next;
		id++;
	}
	el = (t_philo *)philo_clst->content;
	if (id % 2 == 0)
		pthread_create(&(el->thread_id), NULL, &init_routine, el);
}

/**
 * @brief this functionn create the thread of each philo
 * 
 */
void	ft_create_thread_philo(void)
{
	t_clist	*philo_clst;
	t_philo	*el;
	int		id;

	id = 0;
	ft_get_data_addr((t_data *)0)->program_started = ft_get_timestamp();
	philo_clst = ft_get_philo_clist_addr((t_clist *)0);
	while (philo_clst->is_last != 1)
	{
		el = (t_philo *)philo_clst->content;
		if (id % 2 != 0)
			pthread_create(&(el->thread_id), NULL, &init_routine, el);
		philo_clst = philo_clst->next;
		id++;
	}
	el = (t_philo *)philo_clst->content;
	if (id % 2 != 0)
		pthread_create(&(el->thread_id), NULL, &init_routine, el);
	ft_create_thread_philo_even();
}
