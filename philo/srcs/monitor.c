/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 18:00:29 by ccastro           #+#    #+#             */
/*   Updated: 2025/07/09 19:20:31 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

void	*monitor_routine(void *args)
{
	int					i;
	t_info				*info;
	unsigned long long	meal_time;

	i = 0;
	info = (t_info *)args;
	while (1)
	{
		i = 0;
		while (i < info->philo_count)
		{
			pthread_mutex_lock(&info->philo[i].meal_time_lock);
			meal_time = info->philo[i].last_meal_time;
			pthread_mutex_unlock(&info->philo[i].meal_time_lock);
			if ((get_timestamp_ms() - meal_time) > info->death_time)
			{
				pthread_mutex_lock(&info->status_lock);
				info->philo_died = 1;
				printf("DEATH\n");
				pthread_mutex_unlock(&info->status_lock);
				return (NULL);
			}
			i++;
		}
		usleep(1000);
	}
}

int	monitor(t_info *info)
{
	pthread_t	monitor_thread;
	
	if (pthread_create(&monitor_thread, NULL, monitor_routine, info))
		return (0);
	if (pthread_detach(monitor_thread))
		return (0);
	return (1);
}
