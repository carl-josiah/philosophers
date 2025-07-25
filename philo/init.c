/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 16:37:37 by ccastro           #+#    #+#             */
/*   Updated: 2025/07/25 15:43:13 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	init_info(int ac, char **av, t_philo *philo, t_info *info);
static void	init_philo(t_philo *philo, t_info *info);

void	init_philo_last_meal_time(t_philo *philo, t_info *info)
{
	unsigned long long	i;

	i = 0;
	while (i < info->philo_count)
	{
		philo[i].last_meal_time = info->start_time;
		i++;
	}
}

static void	init_info(int ac, char **av, t_philo *philo, t_info *info)
{
	unsigned long long	i;

	i = 0;
	ft_atol(av[1], &info->philo_count);
	ft_atol(av[2], &info->time_to_die);
	ft_atol(av[3], &info->time_to_eat);
	ft_atol(av[4], &info->time_to_sleep);
	if (ac == 6)
		ft_atol(av[5], &info->required_meals);
	else
		info->required_meals = 0;
	info->death_flag = 0;
	info->init_fork_flag = 0;
	info->start_time = 0;
	while (i < info->philo_count)
	{
		info->forks[i] = i;
		pthread_mutex_init(&info->fork_locks[i], NULL);
		i++;
	}
	pthread_mutex_init(&info->print_lock, NULL);
	pthread_mutex_init(&info->death_lock, NULL);
	pthread_mutex_init(&info->meal_lock, NULL);
	info->philo = philo;
}

static void	init_philo(t_philo *philo, t_info *info)
{
	unsigned long long	i;

	i = 0;
	while (i < info->philo_count)
	{
		philo[i].info = info;
		philo[i].id = i + 1;
		philo[i].meal_count = 0;
		philo[i].left_fork = &info->forks[i];
		philo[i].right_fork = &info->forks[(i + 1) % info->philo_count];
		philo[i].lock_left = &info->fork_locks[i];
		philo[i].lock_right = &info->fork_locks[(i + 1) % info->philo_count];
		philo[i].last_meal_time = 0;
		pthread_mutex_init(&philo[i].meal_count_lock, NULL);
		pthread_mutex_init(&philo[i].meal_time_lock, NULL);
		i++;
	}
}

void	init_fork_eating_order(t_philo *philo, t_info *info)
{
	unsigned long long	i;

	i = 1;
	while (i < info->philo_count)
	{
		if (philo->info->init_fork_flag == 0)
		{
			info->forks[0] = info->philo_count;
			info->forks[info->philo_count - 1] = info->philo_count;
			info->init_fork_flag = 1;
		}
		if (info->forks[i] % 2 == 0)
			info->forks[i] = i + 2;
		else
			info->forks[i] = i + 1;
		i++;
	}
}

void	initialize(int ac, char **av, t_philo *philo, t_info *info)
{
	init_info(ac, av, philo, info);
	init_philo(philo, info);
}
