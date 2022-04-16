/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-bach <ael-bach@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 04:21:17 by ael-bach          #+#    #+#             */
/*   Updated: 2022/04/16 21:41:24 by ael-bach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <semaphore.h>
# include <sys/time.h>
# include <limits.h>

typedef struct s_shared_data
{
	int				nbr_philo;
	int				t_to_die;
	int				t_to_eat;
	int				t_to_sleep;
	long			start;
	int				nbr_of_times_each_philo_eat;
	int				counter;
	sem_t			*fork;
	sem_t			*print;
}	t_shared_data;

typedef struct s_philo
{
	int				id;
	long int		last_meal_time;
	int				number_of_meals;
	pthread_t		thread[3];
	t_shared_data	*shared_data;
}	t_philo;

t_shared_data	*init_data(int c, char **v);
t_philo			**init_philos(t_shared_data *shared_data);
int				check_before_atoi(const char *str);
long			ft_atoi(const char *str);
long int		time_now(void);
void			ft_usleep(long long time);
void			ft_print(t_philo *philos, char *str);
void			creat_newprocess(t_philo **philos, t_shared_data *vr, int ac);
void			waiting_process(pid_t *id, int ac, t_shared_data *vr);
void			*ft_rotine(void *arg);
void			rotine(t_philo *philos);

#endif