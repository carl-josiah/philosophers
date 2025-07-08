/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 15:07:43 by ccastro           #+#    #+#             */
/*   Updated: 2025/07/08 18:52:53 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

void	monitor(t_philo *philo, t_info *info)
{
	int	i;

	i = 0;
	while (1)
	{
		if (i == info->philo_count)
			i = 0;
		if ((get_timestamp_ms() - philo[i].last_meal_time)
			> philo[i].info->death_time)
		{
			info->philo_died = 1;
			printf("death detected!\n");
			return ;
		}
		i++;
		usleep(1000);
	}
}
