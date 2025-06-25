/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 15:22:37 by ccastro           #+#    #+#             */
/*   Updated: 2025/06/25 20:00:44 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

int	main(int ac, char **av)
{
	t_philo	philo;
	t_info	info;

	if (!is_correct_input(ac, av))
		return (EXIT_FAILURE);
	if (!init(&philo, &info, av))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
