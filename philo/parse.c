/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 16:09:30 by ccastro           #+#    #+#             */
/*   Updated: 2025/07/21 19:15:03 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	is_five_or_six_args(int ac);
static int	is_all_digit(int ac, char **av);
static int	is_zero_or_greater_than_int_max(int ac, char **av, int num);
static int	is_philo_count_valid(char **av);

static int	is_five_or_six_args(int ac)
{
	if (ac < 5 || ac > 6)
		return (0);
	return (1);
}

static int	is_all_digit(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		if (av[i][j] == '+')
			j++;
		while (av[i][j] && av[i][j] >= '0' && av[i][j] <= '9')
			j++;
		if (av[i][j] != '\0')
			return (0);
		i++;
	}
	return (1);
}

static int	is_zero_or_greater_than_int_max(int ac, char **av, int zero_or_max)
{
	int					i;
	unsigned long long	num;

	i = 1;
	num = 0;
	while (i < ac)
	{
		if (ft_atol(av[i], &num) == zero_or_max)
			return (1);
		i++;
	}
	return (0);
}

static int	is_philo_count_valid(char **av)
{
	unsigned long long	num;

	num = 0;
	ft_atol(av[1], &num);
	if (num > 200)
		return (0);
	return (1);
}

int	parsing(int ac, char **av)
{
	if (!is_five_or_six_args(ac))
		return (parsing_error(ERR_AC), 0);
	else if (!is_all_digit(ac, av))
		return (parsing_error(ERR_AV_NUM), 0);
	else if (is_zero_or_greater_than_int_max(ac, av, ZERO))
		return (parsing_error(ERR_AV_ZERO), 0);
	else if (is_zero_or_greater_than_int_max(ac, av, GREATER_MAX))
		return (parsing_error(ERR_INT_MAX), 0);
	else if (!is_philo_count_valid(av))
		return (parsing_error(ERR_PHILO_COUNT), 0);
	return (1);
}
