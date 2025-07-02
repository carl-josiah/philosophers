/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 17:49:24 by ccastro           #+#    #+#             */
/*   Updated: 2025/07/02 18:49:54 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

int	start_simulation(t_philo *philo, t_info *info)
{
	init_eating_order(info);
	// if (!monitor(philo, info))
	// 	return (0);
	if (!create_mutexes(info))
		return (0);
	if (!create_threads(philo))
		return (0);
	// test_init(philo, info);
	if (!join_threads(philo))
		return (0);
	if (!destroy_mutexes(info))
		return (0);
	return (1);
}
