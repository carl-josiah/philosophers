/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 14:43:20 by ccastro           #+#    #+#             */
/*   Updated: 2025/06/24 15:23:15 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

void	print_philo_action(t_philo *philo, int action, long timestamp)
{
	if (action == DIED)
		printf("%ld Philosopher %d died\n", timestamp, philo->id);
	else if (action == THINKING)
		printf("%ld Philosopher %d is thinking\n", timestamp, philo->id);
	else if (action == TAKE_FORK)
		printf("%ld Philosopher %d has taken a fork\n", timestamp, philo->id);
	else if (action == EATING)
		printf("%ld Philospher %d is eating\n", timestamp, philo->id);
	else if (action == SLEEPING)
		printf("%ld Philosopher %d is sleeping\n", timestamp, philo->id);
}
