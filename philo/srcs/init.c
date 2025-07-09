/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 18:42:45 by ccastro           #+#    #+#             */
/*   Updated: 2025/07/09 01:26:05 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

static void	init_philo_meal_time_lock(t_philo *philo);
static void	init_info(t_philo *philo, t_info *info, char **av);
static void	assign_info_to_philos(t_philo *philo, t_info *info);
static void	init_philo(t_philo *philo);

static void	init_philo_meal_time_lock(t_philo *philo)
{
	int	i;
	int	philos;

	i = 0;
	philos = philo->info->philo_count;
	while (i < philos)
	{
		pthread_mutex_init(&philo[i].meal_time_lock, NULL);
		i++;
	}
}

static void	init_info(t_philo *philo, t_info *info, char **av)
{
	init_args(info, av);
	info->philo_died = 0;
	info->meal_limit_reached = 0;
	info->fork_init_flag = 0;
	init_forks(info);
	init_fork_mutexes(info);
	pthread_mutex_init(&info->print_lock, NULL);
	pthread_mutex_init(&info->status_lock, NULL);
	info->philo = philo;
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
	init_philo_meal_time_lock(philo);
}

void	init(t_philo *philo, t_info *info, char **av)
{
	init_info(philo, info, av);
	assign_info_to_philos(philo, info);
	init_philo(philo);
}
