/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 14:54:29 by ccastro           #+#    #+#             */
/*   Updated: 2025/06/26 18:20:49 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

void	error_input(const char *msg)
{
	printf(RED "ERROR: %s\n" DEFAULT, msg);
	printf("Usage: ./philo ");
	printf("[philosopher_count] [time_to_die] [time_to_eat] [time_to_sleep] ");
	printf(GREY "optional: [req_meal_count]\n" DEFAULT);
}

void	error_msg(const char *msg)
{
	printf(RED "ERROR: %s\n" DEFAULT, msg);
}
