/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 14:27:18 by ccastro           #+#    #+#             */
/*   Updated: 2025/07/07 17:05:36 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

int	print_action(t_philo *philo, int action)
{
	// if (pthread_mutex_lock(&philo->info->print_lock))
	// 	return (0);
	// if (philo->info->philo_died && action != DIED)
		// return (pthread_mutex_unlock(&philo->info->print_lock), 0);
	if (philo->info->philo_died && action != DIED)
		return (0);
	if (action == TAKE_FORK)
		print_take_fork(philo);
	if (action == EATING)
		print_eating(philo);
	if (action == THINKING)
		print_thinking(philo);
	if (action == SLEEPING)
		print_sleeping(philo);
	if (action == DIED)
		print_died(philo);
	// if (pthread_mutex_unlock(&philo->info->print_lock))
	// 	return (0);
	return (1);
}
