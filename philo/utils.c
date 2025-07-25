/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 19:11:04 by ccastro           #+#    #+#             */
/*   Updated: 2025/07/25 11:25:20 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atol(const char *str, unsigned long long *num)
{
	int	i;

	i = 0;
	*num = 0;
	if (str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			*num = (*num * 10) + (str[i] - '0');
		i++;
	}
	if (*num > INT_MAX)
		return (-1);
	if (*num == 0)
		return (0);
	return (1);
}

unsigned long long	curr_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	chunk_usleep(unsigned long long ms, t_philo *philo)
{
	unsigned long long	start;

	start = curr_time();
	while (!is_dead(philo) && (curr_time() - start) < ms)
		usleep(100);
}

void	init_philo_last_meal_time(t_philo *philo, t_info *info)
{
	unsigned long long	i;

	i = 0;
	while (i < info->philo_count)
	{
		philo[i].last_meal_time = info->start_time;
		i++;
	}
}

int	print_action(t_philo *philo, int action)
{
	unsigned long long	start;

	start = philo->info->start_time;
	guard_state(&philo->info->print_lock, LOCK);
	guard_state(&philo->info->death_lock, LOCK);
	if (philo->info->death_flag && action != DIED)
		return (guard_state(&philo->info->print_lock, UNLOCK),
			guard_state(&philo->info->death_lock, UNLOCK), 0);
	if (action == DIED)
		printf(RED "%llu %d died\n" WHT, curr_time() - start, philo->id);
	else if (action == TAKE_FORK && !philo->info->death_flag)
		printf("%llu %d has taken a fork\n", curr_time() - start, philo->id);
	else if (action == EATING && !philo->info->death_flag)
		printf("%llu %d is eating\n", curr_time() - start, philo->id);
	else if (action == SLEEPING && !philo->info->death_flag)
		printf("%llu %d is sleeping\n", curr_time() - start, philo->id);
	else if (action == THINKING && !philo->info->death_flag)
		printf("%llu %d is thinking\n", curr_time() - start, philo->id);
	else
		return (guard_state(&philo->info->print_lock, UNLOCK),
			guard_state(&philo->info->death_lock, UNLOCK), 0);
	return (guard_state(&philo->info->print_lock, UNLOCK),
		guard_state(&philo->info->death_lock, UNLOCK), 1);
}
