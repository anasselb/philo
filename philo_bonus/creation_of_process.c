/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creation_of_process.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-bach <ael-bach@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 23:01:15 by ael-bach          #+#    #+#             */
/*   Updated: 2022/04/16 22:00:30 by ael-bach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*ft_rotine(void *arg)
{
	t_philo	*philos;

	philos = arg;
	while (1)
	{
		sem_wait(philos->shared_data->fork);
		ft_print(philos, "has taken a fork");
		sem_wait(philos->shared_data->fork);
		ft_print(philos, "has taken a fork");
		philos->last_meal_time = time_now();
		ft_print(philos, "is  eating");
		ft_usleep(philos->shared_data->t_to_eat);
		sem_post(philos->shared_data->fork);
		sem_post(philos->shared_data->fork);
		ft_print(philos, "is  sleeping");
		ft_usleep(philos->shared_data->t_to_sleep);
		ft_print(philos, "is  thinking");
		philos->number_of_meals += 1;
	}
	return (NULL);
}

void	creat_newprocess(t_philo **philos, t_shared_data *vr, int ac)
{
	pid_t	*id;
	int		i;

	id = malloc (sizeof(pid_t) * vr->nbr_philo);
	sem_unlink("fork");
	vr->fork = sem_open("fork", O_CREAT, 777, vr->nbr_philo);
	if (vr->fork == SEM_FAILED)
		exit(1);
	sem_unlink("print");
	vr->print = sem_open("print", O_CREAT, 777, 1);
	vr->start = time_now();
	i = 0;
	while (i < vr->nbr_philo)
	{
		philos[i]->id = i + 1;
		id[i] = fork();
		philos[i]->shared_data = vr;
		philos[i]->number_of_meals = 0;
		philos[i]->last_meal_time = time_now();
		if (id[i] == 0)
			rotine(philos[i]);
		i++;
	}
	waiting_process(id, ac, vr);
}

void	waiting_process(pid_t *id, int ac, t_shared_data *vr)
{
	int	i;

	if (ac == 5)
		waitpid(-1, NULL, 0);
	else if (ac == 6)
	{
		i = 0;
		while (i < vr->nbr_philo)
		{
			waitpid(id[i], NULL, 0);
			i++;
		}
	}
}
