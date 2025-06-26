/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 12:31:12 by ccastro           #+#    #+#             */
/*   Updated: 2025/06/26 13:54:44 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

void	*philo_routine(void *arg)
{
	t_philo	*philo;
	int		is_philo_dead;
	int		is_meals_finished;
	int		is_sim_done;

	philo = (t_philo *)arg;
	is_philo_dead = philo->info->philo_died;
	is_meals_finished = philo->info->meals_finished;
	is_sim_done = philo->info->stop_simulation;
	while (!(is_philo_dead || is_meals_finished) && is_sim_done)
	{
		philo_thinking(philo);
		if (!philo_eating(philo))
			return (0);
		if (!philo_sleeping(philo))
			return (0);
	}
	return (NULL);
}
