/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 15:22:37 by ccastro           #+#    #+#             */
/*   Updated: 2025/07/09 00:38:01 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

int	main(int ac, char **av)
{
	t_philo	philo[MAX_PHILO];
	t_info	info;

	if (!is_correct_input(ac, av))
		return (EXIT_FAILURE);
	init(philo, &info, av);
	if (!start_simulation(philo, &info))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
