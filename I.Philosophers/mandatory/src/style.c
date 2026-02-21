/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   style.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilymegy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 12:41:31 by ilymegy           #+#    #+#             */
/*   Updated: 2023/11/19 12:41:34 by ilymegy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

void	set_msg_and_colors(t_main *main)
{
	main->c.blue = "\e[0;34m";
	main->c.cyan = "\e[0;38;5;44m";
	main->c.pink = "\e[0;38;5;199m";
	main->c.purple = "\033[0;35m";
	main->c.green = "\e[0;32m";
	main->c.red = "\033[0;31m";
	main->c.reset = "\e[0m";
	main->a.die = "died";
	main->a.eat = "is eating";
	main->a.sleep = "is sleeping";
	main->a.think = "is thinking";
	main->a.fork = "has taken a fork";
	main->err.nb_args = "Invalid number of args.";
	main->err.arg1 = "No philosopher here.";
	main->err.arg2 = "Time to die is null.";
	main->err.arg3 = "Time to eat is null.";
	main->err.arg4 = "Time to sleep is null.";
	main->err.arg5 = "Philosophers need to eat at least one time.";
}
