/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 09:42:43 by ccastro           #+#    #+#             */
/*   Updated: 2025/06/24 10:39:04 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

int	assign_philo_forks(t_sim *info)
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
	return (1);
}
