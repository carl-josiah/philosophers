/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 15:12:09 by ccastro           #+#    #+#             */
/*   Updated: 2025/06/19 13:38:41 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

int	philo_atoi_safe(char *str, int *out)
{
	size_t				i;
	unsigned long long	num;

	i = 0;
	*out = 0;
	num = *out;
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
	*out = (int)num;
	return (1);
}
