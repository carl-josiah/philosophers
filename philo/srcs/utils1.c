/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 15:12:09 by ccastro           #+#    #+#             */
/*   Updated: 2025/06/17 17:34:48 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

int	philo_atoi_safe(char *str, int *out)
{
	size_t				i;
	int					sign;
	unsigned long long	num;

	i = 0;
	sign = 1;
	*out = 0;
	num = *out;
	while (str[i] && is_delim(str[i]))
		i++;
	if (is_sign(str[i]))
		if (str[i++] == '-')
			sign = -1;
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		num = (num * 10) + (str[i] - '0');
		if (sign == 1 && num > 2147483647ULL)
			return (0);
		else if (sign == -1)
			return (0);
		i++;
	}
	*out = sign * (int)num;
	return (1);
}
