/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 11:18:40 by ccastro           #+#    #+#             */
/*   Updated: 2025/07/02 11:30:58 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

void	init_eating_order(t_info *info)
{
	int	i;
	int	philos;

	i = 1;
	philos = info->philo_count;
	while (i < philos)
	{
		if (info->fork_init_flag == 0)
		{
			info->forks[0] = philos;
			info->forks[philos - 1] = philos;
			info->fork_init_flag = 1;
		}
		if (info->forks[i] % 2 == 0)
			info->forks[i] = i + 2;
		else
			info->forks[i] = i + 1;
		i++;
	}
}

int	create_threads(t_philo *philo)
{
	int	i;
	int	philos;

	i = 0;
	philos = philo->info->philo_count;
	while (i < philos)
	{
		if (pthread_create(&philo[i].thread, NULL, routine, &philo[i]))
			return (0);
		i++;
	}
	return (1);
}

int	create_mutexes(t_info *info)
{
	int	i;
	int	philos;

	i = 0;
	philos = info->philo_count;
	while (i < philos)
	{
		if (pthread_mutex_init(&info->fork_locks[i], NULL))
			return (0);
		i++;
	}
	return (1);
}

int	join_threads(t_philo *philo)
{
	int	i;
	int	philos;

	i = 0;
	philos = philo->info->philo_count;
	while (i < philos)
	{
		if (pthread_join(philo[i].thread, NULL))
			return (0);
		i++;
	}
	return (1);
}

int	destroy_mutexes(t_info *info)
{
	int	i;
	int	philos;

	i = 0;
	philos = info->philo_count;
	while (i < philos)
	{
		if (pthread_mutex_destroy(&info->fork_locks[i]))
			return (0);
		i++;
	}
	return (1);
}
