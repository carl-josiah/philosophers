/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastro <ccastro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 15:16:55 by ccastro           #+#    #+#             */
/*   Updated: 2025/06/17 18:02:49 by ccastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

static int	is_empty_arg(int ac, char *av[])
{
	int		i;
	size_t	j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (is_delim(av[i][j]))
				j++;
			else
				break ;
		}
		if (av[i][j] == '\0')
			return (1);
		i++;
	}
	return (0);
}

static int	is_all_digit(int ac, char *av[])
{
	int		i;
	int		has_digit;
	size_t	j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		has_digit = 0;
		while (av[i][j] && is_delim(av[i][j]))
			j++;
		if (av[i][j] == '+')
			j++;
		while (av[i][j] && is_digit(av[i][j]))
		{
			has_digit = 1;
			j++;
		}
		while (av[i][j] && is_delim(av[i][j]))
			j++;
		if (!has_digit || av[i][j] != '\0')
			return (0);
		i++;
	}
	return (1);
}

static int	is_valid_num(int ac, char *av[])
{
	int		i;
	int		num;

	i = 1;
	while (i < ac)
	{
		if (!philo_atoi_safe(av[i], &num))
			return (0);
		if (num <= 0)
			return (0);
		i++;
	}
	return (1);
}

int	is_valid_argc(int ac)
{
	if (ac == 5 || ac == 6)
		return (1);
	return (0);
}

int	is_valid_argv(int ac, char *av[])
{
	if (is_empty_arg(ac, av) || !is_all_digit(ac, av))
		return (0);
	if (!is_valid_num(ac, av))
		return (0);
	return (1);
}
