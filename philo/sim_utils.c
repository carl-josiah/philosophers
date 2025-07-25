/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sim_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 11:09:04 by ccastro           #+#    #+#             */
/*   Updated: 2025/07/25 15:32:59 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_dead(t_philo *philo)
{
	guard_state(&philo->info->death_lock, LOCK);
	if (philo->info->death_flag)
		return (guard_state(&philo->info->death_lock, UNLOCK), 1);
	guard_state(&philo->meal_time_lock, LOCK);
	if (curr_time() > philo->last_meal_time + philo->info->time_to_die)
	{
		guard_state(&philo->meal_time_lock, UNLOCK);
		philo->info->death_flag = 1;
		guard_state(&philo->info->death_lock, UNLOCK);
		print_action(philo, DIED);
		return (1);
	}
	guard_state(&philo->info->death_lock, UNLOCK);
	return (guard_state(&philo->meal_time_lock, UNLOCK), 0);
}

int	has_eaten_required_meals(t_philo *philo)
{
	guard_state(&philo->meal_count_lock, LOCK);
	if (!philo->info->required_meals)
		return (guard_state(&philo->meal_count_lock, UNLOCK), 0);
	if ((unsigned long long)philo->meal_count < philo->info->required_meals)
		return (guard_state(&philo->meal_count_lock, UNLOCK), 0);
	return (guard_state(&philo->meal_count_lock, UNLOCK), 1);
}

int	philo_has_eaten(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		guard_state(philo->lock_left, LOCK);
		if (philo->id == *philo->left_fork)
			return (guard_state(philo->lock_left, UNLOCK), 1);
		guard_state(philo->lock_left, UNLOCK);
		guard_state(philo->lock_right, LOCK);
		if (philo->id == *philo->right_fork)
			return (guard_state(philo->lock_right, UNLOCK), 1);
		guard_state(philo->lock_right, UNLOCK);
	}
	else
	{
		guard_state(philo->lock_right, LOCK);
		if (philo->id == *philo->right_fork)
			return (guard_state(philo->lock_right, UNLOCK), 1);
		guard_state(philo->lock_right, UNLOCK);
		guard_state(philo->lock_left, LOCK);
		if (philo->id == *philo->left_fork)
			return (guard_state(philo->lock_left, UNLOCK), 1);
		guard_state(philo->lock_left, UNLOCK);
	}
	usleep(100);
	return (0);
}

int	odd_take_forks(t_philo *philo)
{
	guard_state(philo->lock_right, LOCK);
	*philo->right_fork = philo->id;
	if (!print_action(philo, TAKE_FORK))
		return (guard_state(philo->lock_right, UNLOCK), 0);
	guard_state(philo->lock_left, LOCK);
	*philo->left_fork = philo->id;
	if (!print_action(philo, TAKE_FORK))
		return (guard_state(philo->lock_left, UNLOCK), 0);
	return (1);
}

int	even_take_forks(t_philo *philo)
{
	guard_state(philo->lock_left, LOCK);
	*philo->left_fork = philo->id;
	if (!print_action(philo, TAKE_FORK))
		return (guard_state(philo->lock_left, UNLOCK), 0);
	guard_state(philo->lock_right, LOCK);
	*philo->right_fork = philo->id;
	if (!print_action(philo, TAKE_FORK))
		return (guard_state(philo->lock_right, UNLOCK), 0);
	return (1);
}
