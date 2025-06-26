/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 19:12:33 by ccastro           #+#    #+#             */
/*   Updated: 2025/06/26 19:28:04 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

// void	*monitoring_thread(void *arg)
// {
// 	t_info	*info;
// 	int		i;

// 	info = (t_info *)arg;
// 	i = 0;
// 	while (1)
// 	{
// 		int	philos_done_eating;

// 		philos_done_eating = 0;
// 		if (philos_done_eating == info->philo_count)
// 		{
// 			info->meals_finished = 1;
// 			break ;
// 		}
// 		if (i == info->philo_count)
// 			i = 0;
// 		if (info->philo[i].meal_count == info->required_meals)
// 		{
// 			philos_done_eating++;
// 			i++;
// 		}
// 		if (usleep(100) == -1)
// 			return (error_message("usleep() FAILED"), NULL);
// 	}
// }

void	*monitoring_thread(void *arg)
{
	(void) arg;
	return (NULL);
}
