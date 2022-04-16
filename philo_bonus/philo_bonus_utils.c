/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-bach <ael-bach@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 22:56:45 by ael-bach          #+#    #+#             */
/*   Updated: 2022/04/15 23:46:09 by ael-bach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_print(t_philo *philos, char *str)
{
	sem_wait(philos->shared_data->print);
	printf("%ld : %d %s\n",
		time_now() - philos->shared_data->start, philos->id, str);
	sem_post(philos->shared_data->print);
}

void	ft_usleep(long long time)
{
	usleep(time * 99 / 100);
}

long int	time_now(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

t_shared_data	*init_data(int c, char **v)
{
	t_shared_data	*shared_data;
	int				i;

	shared_data = malloc(sizeof(t_shared_data));
	if (!shared_data)
		return (NULL);
	i = 1;
	while (v[i])
	{
		if (check_before_atoi(v[i]) == -1)
			exit (1);
		i++;
	}
	shared_data->nbr_philo = ft_atoi(v[1]);
	shared_data->t_to_die = ft_atoi(v[2]);
	shared_data->t_to_eat = ft_atoi(v[3]);
	shared_data->t_to_sleep = ft_atoi(v[4]);
	if (c == 6)
		shared_data->nbr_of_times_each_philo_eat = ft_atoi(v[5]);
	else
		shared_data->nbr_of_times_each_philo_eat = -1;
	return (shared_data);
}

t_philo	**init_philos(t_shared_data *shared_data)
{
	t_philo	**philos;
	int		nb_philo;
	int		i;

	nb_philo = shared_data->nbr_philo;
	philos = malloc(nb_philo * sizeof(t_philo *));
	i = 0;
	while (i < nb_philo)
	{
		philos[i] = malloc(sizeof(t_philo));
		i++;
	}
	return (philos);
}
