/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 11:15:20 by ccastro           #+#    #+#             */
/*   Updated: 2025/07/07 14:45:41 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

static int	philo_eating(t_philo *philo);
static int	philo_thinking(t_philo *philo);
static int	philo_sleeping(t_philo *philo);

static int	philo_eating(t_philo *philo)
{
	if (!pick_up_forks(philo))
		return (0);
	if (!eat(philo))
		return (0);
	if (!drop_forks(philo))
		return (0);
	return (1);
}

static int	philo_thinking(t_philo *philo)
{
	if (!print_action(philo, THINKING))
		return (0);
	if (usleep(1000) == -1)
		return (0);
	return (1);
}

static int	philo_sleeping(t_philo *philo)
{
	if (!print_action(philo, SLEEPING))
		return (0);
	if (usleep(philo->info->sleep_time * 1000) == -1)
		return (0);
	return (1);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		if (!philo_eating(philo))
			return (NULL);
		if (!philo_thinking(philo))
			return (NULL);
		if (!philo_sleeping(philo))
			return (NULL);
	}
	return (NULL);
}
