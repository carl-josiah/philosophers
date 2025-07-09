/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_info_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 19:22:48 by ccastro           #+#    #+#             */
/*   Updated: 2025/07/09 00:35:01 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

void	init_args(t_info *info, char **av)
{
	philo_atoi_safe(av[1], &info->philo_count);
	philo_atoi_safe(av[2], &info->death_time);
	philo_atoi_safe(av[3], &info->eat_time);
	philo_atoi_safe(av[4], &info->sleep_time);
	if (av[5])
		philo_atoi_safe(av[5], &info->required_meals);
	else
		info->required_meals = 0;
}

void	init_forks(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->philo_count)
	{
		info->forks[i] = i;
		i++;
	}
}

void	init_fork_mutexes(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->philo_count)
	{
		pthread_mutex_init(&info->fork_locks[i], NULL);
		i++;
	}
}
