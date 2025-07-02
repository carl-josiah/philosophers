/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 09:17:34 by ccastro           #+#    #+#             */
/*   Updated: 2025/07/02 11:29:58 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

int	is_valid_argc(int ac)
{
	if (ac == 5 || ac == 6)
		return (1);
	error_input("MUST BE 5 OR 6 ARGUMENTS");
	return (0);
}

int	is_valid_argv(int ac, char **av)
{
	if (is_empty_arg(ac, av))
		return (error_input("MUST NOT HAVE EMPTY ARGUMENTS"), 0);
	if (!is_all_digit(ac, av))
		return (error_input("MUST BE A NUMBER (E.G. \"+42\" or \"42\")"), 0);
	if (is_valid_num(ac, av) == 0)
		return (error_input("MUST NOT BE GREATER THAN INT_MAX"), 0);
	if (is_valid_num(ac, av) == -1)
		return (error_input("MUST NOT BE LESS THAN OR EQUAL TO ZERO"), 0);
	if (is_over_max_philo(av))
	{
		error_input("[philosopher_count] MUST NOT BE GREATER THAN 200");
		return (0);
	}
	return (1);
}

int	is_correct_input(int ac, char **av)
{
	if (!is_valid_argc(ac) || !is_valid_argv(ac, av))
		return (0);
	return (1);
}
