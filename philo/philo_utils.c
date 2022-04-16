/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-bach <ael-bach@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 22:53:49 by ael-bach          #+#    #+#             */
/*   Updated: 2022/04/12 01:38:53 by ael-bach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_print(t_philo *philos, char *str)
{
	pthread_mutex_lock(philos->shared_data->print);
	printf("%ld : %d %s\n",
		time_now() - philos->shared_data->start, philos->id, str);
	pthread_mutex_unlock(philos->shared_data->print);
}

pthread_mutex_t	*allocate_mutext(void)
{
	pthread_mutex_t	*mutex;

	mutex = malloc(sizeof(pthread_mutex_t));
	if (!mutex)
		return (NULL);
	pthread_mutex_init(mutex, NULL);
	return (mutex);
}

int	check_meals(t_philo **philos)
{
	int	i;

	i = 0;
	while (i < philos[0]->shared_data->nbr_philo)
	{
		if (philos[0]->shared_data->nbr_of_times_each_philo_eat < 0)
			return (0);
		else
		{
			if (philos[i]->number_of_meals
				<= philos[0]->shared_data->nbr_of_times_each_philo_eat)
				return (0);
		}
		i++;
	}
	return (1);
}

int	supervisore(t_philo **philos, t_shared_data *vr)
{
	int	i;

	while (1)
	{
		i = 0;
		while (i < vr->nbr_philo)
		{
			if (check_meals(philos))
				return (1);
			if (time_now() - philos[i]->last_meal_time > vr->t_to_die)
			{
				pthread_mutex_lock(vr->print);
				printf("%ld : %d is died\n",
					time_now() - vr->start, philos[i]->id);
				return (1);
			}
			i++;
		}
	}
	return (0);
}

long int	time_now(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}
