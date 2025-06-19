/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 14:54:29 by ccastro           #+#    #+#             */
/*   Updated: 2025/06/19 18:20:18 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

void	error_message(const char *msg)
{
	printf(RED "ERROR: %s\n" DEFAULT, msg);
	printf("Usage: ./philo ");
	printf("[philosopher_count] [time_to_die] [time_to_eat] [time_to_sleep] ");
	printf(GREY "optional: [req_meal_count]\n" DEFAULT);
}
