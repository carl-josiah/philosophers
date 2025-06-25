/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 18:42:45 by ccastro           #+#    #+#             */
/*   Updated: 2025/06/25 20:10:22 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

static void	init_philo_data(t_philo *philo, t_info *info)
{
	init_id(philo);
	init_meal_count(philo);
	init_last_meal_time(philo);
	init_philo_forks(philo);
	init_philo_locks(philo);
}

static int	init_info(t_philo *philo, t_info *info, char **av)
{
	int	i;

	i = 0;
	init_args(info, av);
	info->philo_died = 0;
	info->meals_finished = 0;
	info->stop_simulation = 0;
	info->start_time = get_timestamp_ms();
	init_forks(info);
	if (!init_fork_mutexes(info))
		return (0);
	while (i < info->philo_count)
	{
		info->philo_data[i] = philo[i];
		i++;
	}
	return (1);
}

int	init(t_philo *philo, t_info *info, char **av)
{
	int	i;

	i = 0;
	while (i < info->philo_count)
	{
		philo[i].info = info;
		i++;
	}
	if (!init_info(philo, info, av))
		return (0);
	init_philo_data(philo, info);
	return (1);
}
