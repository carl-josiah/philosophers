/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 18:41:48 by ccastro           #+#    #+#             */
/*   Updated: 2025/07/04 19:15:43 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

int	print_action(t_philo *philo, int action)
{
	// printf("ENTERING MUTEX LOCK IN PRINT ACT\n");
	// printf("LOCKED!!!!!!!!!!\n");
	if (pthread_mutex_lock(&philo->info->print_lock))
		return (0);
	if (!philo->info->philo_died)
	{
		if (action == DIED)
		{
			print_death(philo);
			philo->info->philo_died = 1;
			if (pthread_mutex_unlock(&philo->info->print_lock))
				return (0);
			return (0);
		}
		else if (action == TAKE_FORK)
			print_take_fork(philo);
		else if (action == EATING)
			print_eating(philo);
		else if (action == THINKING)
			print_thinking(philo);
		else if (action == SLEEPING)
			print_sleeping(philo);
		if (pthread_mutex_unlock(&philo->info->print_lock))
			return (0);
		return (1);
	}
	else
		if (pthread_mutex_unlock(&philo->info->print_lock))
			return (0);
	// printf("EXITING MUTEX LOCK IN PRINT ACT\n");
	return (0);
}
