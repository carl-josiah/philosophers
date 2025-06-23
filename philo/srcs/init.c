/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 15:08:34 by ccastro           #+#    #+#             */
/*   Updated: 2025/06/23 16:39:41 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

void	init_data(int ac, char **av, t_info *data)
{
	philo_atoi_safe(av[1], &data->philo_count);
	philo_atoi_safe(av[2], &data->death_time);
	philo_atoi_safe(av[3], &data->eat_time);
	philo_atoi_safe(av[4], &data->sleep_time);
	if (ac == 6)
		philo_atoi_safe(av[5], &data->meal_limit);
	else
		data->meal_limit = 0;
}

int	allocate_memory(t_info *arg, t_philo **philo, pthread_mutex_t **fork)
{
	*philo = malloc(sizeof(t_philo) * arg->philo_count);
	if (!*philo)
		return (0);
	*fork = malloc(sizeof(pthread_mutex_t) * arg->philo_count);
	if (!*fork)
		return (0);
	return (1);
}

int	init_fork(t_info *arg, pthread_mutex_t **fork)
{
	int	i;

	i = 0;
	while (i < arg->philo_count)
	{
		if (!pthread_mutex_init(&(*fork)[i], NULL))
			return (0);
		i++;
	}
	return (1);
}
