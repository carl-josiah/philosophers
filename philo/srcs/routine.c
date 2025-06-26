/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 12:31:12 by ccastro           #+#    #+#             */
/*   Updated: 2025/06/26 19:11:59 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while ((philo->info->philo_died == 0 || philo->info->meals_finished == 0)
		&& philo->info->stop_simulation)
	{
		philo_thinking(philo);
		if (!philo_eating(philo))
			return (NULL);
		if (!philo_sleeping(philo))
			return (NULL);
	}
	return (NULL);
}
