/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timing.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 13:36:08 by ccastro           #+#    #+#             */
/*   Updated: 2025/07/09 01:58:10 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

unsigned long long	get_timestamp_ms(void)
{
	struct timeval	val;

	gettimeofday(&val, NULL);
	return (val.tv_sec * 1000 + val.tv_usec / 1000);
}

unsigned long long	greater_usleep(unsigned long long time, t_philo *philo)
{
	unsigned long long	start;

	start = get_timestamp_ms();
	while (!is_simulation_end(philo->info))
	{
		if (get_timestamp_ms() - start >= time)
			break ;
		usleep(100);
	}
	return (0);
}
