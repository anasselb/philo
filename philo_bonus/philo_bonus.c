/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-bach <ael-bach@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 23:54:55 by ael-bach          #+#    #+#             */
/*   Updated: 2022/04/15 23:45:17 by ael-bach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	check_meals(t_philo *philos)
{
	if (philos->shared_data->nbr_of_times_each_philo_eat < 0)
		return (0);
	else
	{
		if (philos->number_of_meals
			<= philos->shared_data->nbr_of_times_each_philo_eat)
			return (0);
	}
	return (1);
}

void	*philos_checker(void *arg)
{
	t_philo	*philos;

	philos = arg;
	while (1)
	{
		if (check_meals(philos))
			exit (1);
		if (time_now() - philos->last_meal_time > philos->shared_data->t_to_die)
		{
			sem_wait(philos->shared_data->print);
			printf("%ld : %d is died\n",
				time_now() - philos->shared_data->start, philos->id);
			exit (0);
		}
	}
	return (NULL);
}

void	rotine(t_philo *philos)
{
	pthread_create(&philos->thread[0], NULL, ft_rotine, philos);
	pthread_create(&philos->thread[1], NULL, philos_checker, philos);
	pthread_join(philos->thread[0], NULL);
	pthread_join(philos->thread[1], NULL);
}

int	main(int ac, char **av)
{
	t_philo			**philos;
	t_shared_data	*vr;
	pid_t			*id;

	if (ac == 5 || ac == 6)
	{
		vr = init_data(ac, av);
		philos = init_philos(vr);
		id = creat_newprocess(philos, vr, ac);
	}
	else
		printf("Error\n");
	return (0);
}
