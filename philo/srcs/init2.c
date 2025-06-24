/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 11:18:30 by ccastro           #+#    #+#             */
/*   Updated: 2025/06/24 16:30:01 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

static void	init_philos_status(t_sim *info)
{
	int	i;
	int	philos;

	i = 0;
	philos = info->args->philo_count;
	while (i < philos)
	{
		info->philos[i].time = 0;
		info->philos[i].state = THINKING;
		info->philos[i].meal_count = 0;
		i++;
	}
}

static void	init_philos_id(t_sim *info)
{
	int	i;
	int	j;
	int	philos;

	i = 0;
	j = 1;
	philos = info->args->philo_count;
	while (i < philos)
	{
		info->philos[i].id = j;
		i++;
		j++;
	}
}

static void	init_philos_forks(t_sim *info)
{
	int	i;
	int	philos;

	i = 0;
	philos = info->args->philo_count;
	while (i < philos)
	{
		info->philos[i].left_fork = &info->forks[i];
		info->philos[i].right_fork = &info->forks[(i + 1) % philos];
		i++;
	}
}

static void	resource_hierarchy_solution(t_sim *info)
{
	int	i;
	int	philos;

	i = 0;
	philos = info->args->philo_count;
	while (i < philos)
	{
		if (info->philos[i].left_fork > info->philos[i].right_fork)
		{
			info->philos[i].first_fork = info->philos[i].right_fork;
			info->philos[i].second_fork = info->philos[i].left_fork;
		}
		else
		{
			info->philos[i].first_fork = info->philos[i].left_fork;
			info->philos[i].second_fork = info->philos[i].right_fork;
		}
		i++;
	}
}

void	init_philos(t_sim *info)
{
	init_philos_status(info);
	init_philos_id(info);
	init_philos_forks(info);
	resource_hierarchy_solution(info);
}
