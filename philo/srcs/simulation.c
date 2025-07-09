/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 17:49:24 by ccastro           #+#    #+#             */
/*   Updated: 2025/07/09 19:18:52 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

int	start_simulation(t_philo *philo, t_info *info)
{
	init_eating_order(info);
	create_mutexes(info);
	if (!create_threads(philo))
		return (0);
	info->start_time = get_timestamp_ms();
	if (!monitor(info))
		return (0);
	init_last_meal_time(philo);
	join_threads(philo);
	destroy_mutexes(info);
	return (1);
}
