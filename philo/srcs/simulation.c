/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 17:49:24 by ccastro           #+#    #+#             */
/*   Updated: 2025/07/01 20:02:45 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

void	init_eating_order(t_info * info)
{
	int	i;
	int	philos;
	int	flag;

	i = 1;
	flag = 0;
	philos = info->philo_count;
	while (i < philos)
	{
		if (flag == 0)
		{
			info->forks[0] = philos;
			info->forks[philos - 1] = philos;
			flag = 1;
		}
		if (info->forks[i] % 2 == 0)
			info->forks[i] = i + 2;
		else
			info->forks[i] = i + 1;
		i++;
	}
}

// int	pick_up_forks(t_philo *philo)
// {
// 	if (philo->id == (*philo->left_fork && *philo->right_fork))
// 		return (0);
// 	pthread_mutex_lock(philo->lock_left);
// 	*philo->left_fork = philo->id;
// 	printf("%ld %d has taken a fork\n", get_timestamp_ms(), philo->id);
// 	pthread_mutex_lock(philo->lock_right);
// 	*philo->right_fork = philo->id;
// 	printf("%ld %d has taken a fork\n", get_timestamp_ms(), philo->id);
// 	return (1);
// }

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	// if (!pick_up_forks(philo))
	// 	return (NULL);
	return (NULL);
}

static int	create_threads(t_philo *philo)
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

static int create_mutexes(t_info *info)
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

static int	join_threads(t_philo *philo)
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

static int	destroy_mutexes(t_info *info)
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

int	start_simulation(t_philo *philo, t_info *info)
{
	init_eating_order(info);
	if (!create_mutexes(info))
		return (0);
	if (!create_threads(philo))
		return (0);
	if (!join_threads(philo))
		return (0);
	if (!destroy_mutexes(info))
		return (0);
	return (1);
}
