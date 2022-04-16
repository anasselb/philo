/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-bach <ael-bach@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 15:49:16 by ael-bach          #+#    #+#             */
/*   Updated: 2022/04/12 04:24:39 by ael-bach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int	check_before_atoi(const char *str)
{
	long	i;
	long	j;

	i = 0;
	if (str[0] == '+' && str[1] != '\0')
		i++;
	j = 0;
	while (str[j] == '0')
		j++;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0)
		{
			write (2, "Error\n", 6);
			return (-1);
		}
		i++;
	}
	return (0);
}

static long long	ft_line(const char *str, long i, long n)
{
	long long	a;

	a = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		a = a * 10 + (str[i] - 48);
		i++;
	}
	return (a * n);
}

long	ft_atoi(const char *str)
{
	long long		i;
	long long		n;
	long long		c;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == ' '))
		i++;
	n = 1;
	c = 0;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '+' || str[i] == '-')
			c += 1;
		if (str[i] == '-')
			n *= -1;
		i++;
	}
	if (c >= 2 || ft_line(str, i, n) > INT32_MAX
		|| ft_line(str, i, n) < INT32_MIN)
	{
		write (2, "Error\n", 6);
		return (0);
	}
	return (ft_line(str, i, n));
}
