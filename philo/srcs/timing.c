/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timing.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 13:36:08 by ccastro           #+#    #+#             */
/*   Updated: 2025/06/24 13:47:05 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

long	get_timestamp_ms(void)
{
	struct timeval	val;

	gettimeofday(&val, NULL);
	return (val.tv_sec * 1000 + val.tv_usec / 1000);
}
