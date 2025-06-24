/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 13:53:10 by ccastro           #+#    #+#             */
/*   Updated: 2025/06/24 16:49:53 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

int	create_philosophers(t_sim *info)
{
	int	i;
	int	philos;

	i = 0;
	philos = info->args->philo_count;
	while (i < philos)
	{
		if (pthread_create(info->philos[i].thread, NULL, routine, &info->philos[i]))
			return (0);
		i++;
	}
	return (1);
}

int	start_simul(t_sim *info)
{
	if (!create_philosophers(info))
		return (0);
	return (1);
}
