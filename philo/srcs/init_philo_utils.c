/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 18:55:57 by ccastro           #+#    #+#             */
/*   Updated: 2025/07/09 02:19:10 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

void	init_id(t_philo *philo)
{
	int	i;
	int	j;
	int	philos;

	i = 0;
	j = 1;
	philos = philo->info->philo_count;
	while (i < philos)
	{
		philo[i].id = j;
		i++;
		j++;
	}
}

void	init_meal_count(t_philo *philo)
{
	int	i;
	int	philos;

	i = 0;
	philos = philo->info->philo_count;
	while (i < philos)
	{
		philo[i].meal_count = 0;
		i++;
	}
}

void	init_last_meal_time(t_philo *philo)
{
	int	i;
	int	philos;

	i = 0;
	philos = philo->info->philo_count;
	while (i < philos)
	{
		philo[i].last_meal_time = philo->info->start_time;
		i++;
	}
}

void	init_philo_forks(t_philo *philo)
{
	int	i;
	int	philos;

	i = 0;
	philos = philo->info->philo_count;
	while (i < philos)
	{
		philo[i].left_fork = &philo[i].info->forks[i];
		philo[i].right_fork = &philo[i].info->forks[(i + 1) % philos];
		i++;
	}
}

void	init_philo_locks(t_philo *philo)
{
	int	i;
	int	philos;

	i = 0;
	philos = philo->info->philo_count;
	while (i < philos)
	{
		philo[i].lock_left = &philo[i].info->fork_locks[i];
		philo[i].lock_right = &philo[i].info->fork_locks[(i + 1) % philos];
		i++;
	}
}
