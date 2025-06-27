/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 18:42:45 by ccastro           #+#    #+#             */
/*   Updated: 2025/06/27 15:41:51 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

static int	init_info(t_philo *philo, t_info *info, char **av)
{
	init_args(info, av);
	info->philo_died = 0;
	info->meal_limit_reached = 0;
	info->stop_simulation = 0;
	info->start_time = get_timestamp_ms();
	init_forks(info);
	if (!init_fork_mutexes(info))
		return (0);
	info->philo = philo;
	return (1);
}

static void	assign_info_to_philos(t_philo *philo, t_info *info)
{
	int	i;

	i = 0;
	while (i < info->philo_count)
	{
		philo[i].info = info;
		i++;
	}
}

static void	init_philo(t_philo *philo)
{
	init_id(philo);
	init_meal_count(philo);
	init_philo_forks(philo);
	init_philo_locks(philo);
}

int	init(t_philo *philo, t_info *info, char **av)
{
	if (!init_info(philo, info, av))
		return (0);
	assign_info_to_philos(philo, info);
	init_philo(philo);
	return (1);
}
