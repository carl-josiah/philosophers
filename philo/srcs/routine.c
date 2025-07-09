/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 11:15:20 by ccastro           #+#    #+#             */
/*   Updated: 2025/07/09 02:05:17 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

static int	philo_eating(t_philo *philo);
static void	philo_thinking(t_philo *philo);
static void	philo_sleeping(t_philo *philo);

static int	philo_eating(t_philo *philo)
{
	if (is_simulation_end(philo->info))
		return (0);
	if (!pick_up_forks(philo))
		return (0);
	if (is_simulation_end(philo->info))
		return (drop_forks(philo), 0);
	eat(philo);
	drop_forks(philo);
	return (1);
}

static void	philo_thinking(t_philo *philo)
{
	if (is_simulation_end(philo->info))
		return ;
	greater_usleep(1000, philo);
}

// static void	philo_sleeping(t_philo *philo)
// {
// 	if (is_simulation_end(philo->info))
// 		return ;
// 	usleep(philo->info->sleep_time * 1000);
// }

static void	philo_sleeping(t_philo *philo)
{
    if (is_simulation_end(philo->info))
        return ;
    greater_usleep(philo->info->sleep_time, philo);
    // Add extra stagger for even philosophers after sleeping
    if (philo->info->philo_count % 2 == 0 && philo->id % 2 == 0)
        greater_usleep(1000, philo); // 1ms, you can try 2000 or more if needed
}

static void	*single_philo_case(t_philo *philo)
{
	pthread_mutex_lock(philo->lock_left);
	*philo->left_fork = philo->id;
	greater_usleep(philo->info->death_time, philo);
	pthread_mutex_unlock(philo->lock_left);
	return (NULL);
}

// void	*routine(void *arg)
// {
// 	t_philo	*philo;

// 	philo = (t_philo *)arg;
// 	while (((unsigned long long)get_timestamp_ms()) < philo->info->start_time)
// 		usleep(100);
// 	if (philo->info->philo_count == 1)
// 		return (single_philo_case(philo));
// 	while (1)
// 	{
// 		if (is_simulation_end(philo->info))
// 			return (NULL);
// 		if (!philo_eating(philo))
// 			return (NULL);
// 		philo_thinking(philo);
// 		philo_sleeping(philo);
// 	}
// 	return (NULL);
// }


void	*routine(void *arg)
{
    t_philo	*philo;

    philo = (t_philo *)arg;
    printf("Philo %d thread started\n", philo->id);
    while (get_timestamp_ms() < philo->info->start_time)
        usleep(100);

    // Stagger start for even philosophers
	if (philo->id % 2 == 0)
		greater_usleep(1000, philo);

    printf("Philo %d enters main loop at %llu\n", philo->id, get_timestamp_ms());
    if (philo->info->philo_count == 1)
        return (single_philo_case(philo));
    while (1)
    {
        if (is_simulation_end(philo->info))
            return (NULL);
        if (!philo_eating(philo))
            return (NULL);
        philo_thinking(philo);
        philo_sleeping(philo);
    }
    return (NULL);
}
