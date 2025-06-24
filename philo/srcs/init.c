/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 15:08:34 by ccastro           #+#    #+#             */
/*   Updated: 2025/06/24 10:26:12 by ccastro          ###   ########.fr       */
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

int	malloc_philos_and_forks(t_sim *info)
{
	info->philos = malloc(sizeof(t_philo) * info->args->philo_count);
	if (!info->philos)
		return (0);
	info->forks = malloc(sizeof(pthread_mutex_t) * info->args->philo_count);
	if (!info->forks)
		return (0);
	return (1);
}

int	init_forks(t_sim *info)
{
	int	i;

	i = 0;
	while (i < info->args->philo_count)
	{
		if (pthread_mutex_init(&(info->forks)[i], NULL))
			return (0);
		i++;
	}
	return (1);
}
