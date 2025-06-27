/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 19:12:33 by ccastro           #+#    #+#             */
/*   Updated: 2025/06/27 16:09:26 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

static int	monitor_death(t_info *info, int *i)
{
	if ((get_timestamp_ms() - info->philo[*i].last_meal_time)
		> info->death_time)
	{
		info->philo_died = 1;
		pthread_mutex_lock(&info->print_lock);
		printf("%ld %d died\n", get_timestamp_ms(), info->philo->id);
		pthread_mutex_unlock(&info->print_lock);
		return (1);
	}
	return (0);
}

static int	monitor_meals(t_info *info)
{
	int	i;
	int	done_eating_count;

	i = 0;
	done_eating_count = 0;
	while (i < info->philo_count)
	{
		if (info->philo[i].meal_count == info->required_meals)
			done_eating_count++;
		i++;
	}
	if (done_eating_count == info->philo_count)
	{
		info->meal_limit_reached = 1;
		return (1);
	}
	return (0);
}

void	*monitoring_thread(void *arg)
{
	int		i;
	int		philos_done_eating;
	t_info	*info;

	i = 0;
	info = (t_info *)arg;
	while (1)
	{
		philos_done_eating = 0;
		if (i == info->philo_count)
			i = 0;
		if (monitor_death(info, &i))
			break ;
		if (info->required_meals > 0)
		{
			if (monitor_meals(info))
				break ;
		}
		i++;
	}
	if (usleep(1000) == -1)
		return (error_msg("usleep() FAILED"), NULL);
	return (NULL);
}
