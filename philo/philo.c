/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-bach <ael-bach@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 02:41:25 by ael-bach          #+#    #+#             */
/*   Updated: 2022/04/16 22:46:09 by ael-bach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_shared_data	*init_shared(int c, char **v)
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
			return (NULL);
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
	shared_data->print = allocate_mutext();
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
		philos[i]->fork = allocate_mutext();
		i++;
	}
	philos = next_fork(philos, shared_data);
	return (philos);
}

void	*rotine(void *arg)
{
	t_philo	*philos;

	philos = arg;
	while (1)
	{
		pthread_mutex_lock(philos->fork);
		ft_print(philos, "has taken a fork");
		pthread_mutex_lock(philos->next_fork);
		ft_print(philos, "has taken a fork");
		philos->last_meal_time = time_now();
		ft_print(philos, "is  eating");
		ft_usleep(philos->shared_data->t_to_eat);
		pthread_mutex_unlock(philos->fork);
		pthread_mutex_unlock(philos->next_fork);
		ft_print(philos, "is  sleeping");
		ft_usleep(philos->shared_data->t_to_sleep);
		ft_print(philos, "is  thinking");
		philos->number_of_meals += 1;
	}
	return (NULL);
}

void	creat_threads(t_philo **philos, t_shared_data *shared_data)
{
	int	i;

	i = 0;
	while (i < shared_data->nbr_philo)
	{
		philos[i]->shared_data = shared_data;
		philos[i]->id = i + 1;
		philos[i]->number_of_meals = 0;
		philos[i]->last_meal_time = time_now();
		pthread_create(&philos[i]->thread, NULL, &rotine, philos[i]);
		usleep(50);
		i++;
	}
}

int	main(int c, char **v)
{
	t_philo			**philos;
	t_shared_data	*vr;

	if (c == 5 || c == 6)
	{
		vr = init_shared(c, v);
		if (vr == NULL || vr->nbr_philo == 0
			|| vr->nbr_of_times_each_philo_eat == 0)
			return (0);
		philos = init_philos(vr);
		vr->start = time_now();
		creat_threads(philos, vr);
		supervisore(philos, vr);
	}
	else
		printf("Error\n");
	return (0);
}
