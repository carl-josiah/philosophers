/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 15:08:34 by ccastro           #+#    #+#             */
/*   Updated: 2025/06/24 09:33:28 by ccastro          ###   ########.fr       */
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

int	allocate_memory(t_sim *init)
{
	init->philo = malloc(sizeof(t_philo) * init->arg->philo_count);
	if (!init->philo)
		return (0);
	init->fork = malloc(sizeof(pthread_mutex_t) * init->arg->philo_count);
	if (!init->fork)
		return (0);
	return (1);
}

int	init_fork(t_sim *init)
{
	int	i;

	i = 0;
	while (i < init->arg->philo_count)
	{
		if (pthread_mutex_init(&(init->fork)[i], NULL))
			return (0);
		i++;
	}
	return (1);
}
