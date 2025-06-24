/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 15:22:37 by ccastro           #+#    #+#             */
/*   Updated: 2025/06/24 09:28:47 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

static int	is_correct_input(int ac, char **av)
{
	if (!is_valid_argc(ac) || !is_valid_argv(ac, av))
		return (0);
	return (1);
}

int	init_philo(int ac, char **av, t_sim *init)
{
	init_data(ac, av, init->arg);
	if (!allocate_memory(init))
		return (0);
	if (!init_fork(init))
		return (0);
	return (1);	
}

int	main(int ac, char **av)
{
	t_info	arg;
	t_sim	init;

	init.arg = &arg;
	if (!is_correct_input(ac, av))
		return (EXIT_FAILURE);
	if (!init_philo(ac, av, &init))
		return (EXIT_FAILURE);
	return (free(init.philo), free(init.fork), EXIT_SUCCESS);
}
