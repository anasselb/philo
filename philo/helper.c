/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-bach <ael-bach@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 02:28:40 by ael-bach          #+#    #+#             */
/*   Updated: 2022/04/12 02:29:19 by ael-bach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_usleep(long long time)
{
	usleep(time * 98 / 100);
}

t_philo	**next_fork(t_philo **philos, t_shared_data *v)
{
	int	i;

	i = 0;
	while (i < v->nbr_philo)
	{
		philos[i]->next_fork = philos[(i + 1) % v->nbr_philo]->fork;
		i++;
	}
	return (philos);
}
