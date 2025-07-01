/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 15:22:37 by ccastro           #+#    #+#             */
/*   Updated: 2025/07/01 19:41:42 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

int	main(int ac, char **av) // don't forget to remove -g3 flag, test_init in src, inc, and make
{
	t_philo	philo[MAX_PHILO];
	t_info	info;

	if (!is_correct_input(ac, av))
		return (EXIT_FAILURE);
	if (!init(philo, &info, av))
		return (EXIT_FAILURE);
	if (!start_simulation(philo, &info))
		return (EXIT_FAILURE);
	test_init(philo, &info);
	return (EXIT_SUCCESS);
}
