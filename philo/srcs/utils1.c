/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 15:12:09 by ccastro           #+#    #+#             */
/*   Updated: 2025/06/25 20:03:13 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

int	philo_atoi_safe(char *str, void *out)
{
	size_t				i;
	unsigned long long	num;

	i = 0;
	(*(int *)out) = 0;
	num = (*(int *)out);
	while (str[i] && is_delim(str[i]))
		i++;
	if (str[i] == '-')
		return (-1);
	if (str[i] == '+')
		i++;
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		num = (num * 10) + (str[i] - '0');
		if (num > 2147483647ULL)
			return (0);
		i++;
	}
	if (num == 0)
		return (-1);
	(*(int *)out) = (int)num;
	return (1);
}
