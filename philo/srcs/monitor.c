/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 15:07:43 by ccastro           #+#    #+#             */
/*   Updated: 2025/07/09 02:17:29 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

void	monitor(t_philo *philo, t_info *info)
{
	int					i;
	unsigned long long	last_meal;

	i = 0;
	// while (1)
	// {
	// 	if (i == info->philo_count)
	// 		i = 0;
	// 	pthread_mutex_lock(&philo[i].meal_time_lock);
	// 	last_meal = philo[i].last_meal_time;
	// 	pthread_mutex_unlock(&philo[i].meal_time_lock);
	// 	if ((get_timestamp_ms() - last_meal) > philo[i].info->death_time)
	// 	{
	// 		pthread_mutex_lock(&info->status_lock);
	// 		info->philo_died = 1;
	// 		printf("death detected!\n");
	// 		pthread_mutex_unlock(&info->status_lock);
	// 		return ;
	// 	}
	// 	i++;
	// 	usleep(1000);
	// }

	 while (1)
    {
        if (i == info->philo_count)
            i = 0;
        pthread_mutex_lock(&philo[i].meal_time_lock);
        last_meal = philo[i].last_meal_time;
        pthread_mutex_unlock(&philo[i].meal_time_lock);
        unsigned long long	now = get_timestamp_ms();
        printf("Monitor: Philo %d last_meal_time=%llu, now=%llu, diff=%llu\n",
            philo[i].id, last_meal, now, now - last_meal);
        if ((now - last_meal) > philo[i].info->death_time)
        {
            pthread_mutex_lock(&info->status_lock);
            info->philo_died = 1;
            printf("death detected! (philo %d, diff=%llu > death_time=%llu)\n",
                philo[i].id, now - last_meal, philo[i].info->death_time);
            pthread_mutex_unlock(&info->status_lock);
            return ;
        }
        i++;
        greater_usleep(2, philo);
    }
}
