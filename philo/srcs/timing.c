/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timing.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 13:36:08 by ccastro           #+#    #+#             */
/*   Updated: 2025/07/09 19:38:26 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

int	responsive_usleep(unsigned long long requested_time, t_info *info)
{
	unsigned long long	start_time;
	unsigned long long	current_time;
	int					philo_death;

	start_time = get_timestamp_ms();
	while (1)
	{
		current_time = get_timestamp_ms();
		if (current_time - start_time >= requested_time)
			return (0);
		pthread_mutex_lock(&info->status_lock);
		philo_death = info->philo_died;
		pthread_mutex_unlock(&info->status_lock);
		if (philo_death)
			return (-1);
		usleep(500);
	}
}

unsigned long long	get_timestamp_ms(void)
{
	struct timeval	val;

	gettimeofday(&val, NULL);
	return (val.tv_sec * 1000 + val.tv_usec / 1000);
}
