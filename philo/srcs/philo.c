/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 15:22:37 by ccastro           #+#    #+#             */
/*   Updated: 2025/06/23 16:27:51 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

static int	is_correct_input(int ac, char *av[])
{
	if (!is_valid_argc(ac) || !is_valid_argv(ac, av))
		return (0);
	return (1);
}

int	main(int ac, char *av[])
{
	t_info			arg;
	t_philo			*philo;
	pthread_mutex_t	*fork;

	if (!is_correct_input(ac, av))
		return (EXIT_FAILURE);
	init_data(ac, av, &arg);
	if (!allocate_memory(&arg, philo, fork))
		return (EXIT_FAILURE);
	if (!init_fork(&arg, fork))
		return (EXIT_FAILURE);
	return (free(philo), free(fork), EXIT_SUCCESS);
}
