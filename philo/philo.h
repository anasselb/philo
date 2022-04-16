/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-bach <ael-bach@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 15:51:00 by ael-bach          #+#    #+#             */
/*   Updated: 2022/04/12 01:47:12 by ael-bach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_shared_data
{
	int				nbr_philo;
	int				t_to_die;
	int				t_to_eat;
	int				t_to_sleep;
	long			start;
	int				nbr_of_times_each_philo_eat;
	int				counter;
	pthread_mutex_t	*print;
}	t_shared_data;

typedef struct s_philo
{
	int				id;
	long int		last_meal_time;
	int				number_of_meals;
	pthread_t		thread;
	pthread_mutex_t	*fork;
	pthread_mutex_t	*next_fork;
	t_shared_data	*shared_data;
}	t_philo;

int				check_before_atoi(const char *str);
long			ft_atoi(const char *str);
long int		time_now(void);
pthread_mutex_t	*allocate_mutext(void);
int				heck_meals(t_philo **philos);
int				supervisore(t_philo **philos, t_shared_data *vr);
void			ft_print(t_philo *philos, char *str);
t_philo			**next_fork(t_philo **philos, t_shared_data *v);
void			ft_usleep(long long time);

#endif