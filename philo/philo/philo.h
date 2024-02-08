/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laura <laura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 15:00:29 by lnunez-t          #+#    #+#             */
/*   Updated: 2024/02/08 18:24:57 by laura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "messages.h"
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_philo
{
	int				n;
	int				is_eating;
	int				n_eat;
	long int		last_eat;
	struct s_data	*info;
	pthread_t		thread_id;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
}					t_philo;

typedef struct s_data
{
	int				nb_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_meals;
	int				has_died;
	long int		t_start;
	pthread_t		*threads;
	t_philo			*philo;
	pthread_mutex_t	*forks;
}					t_data;

int					ft_atoi(const char *nptr);
long long			millitimestamp(void);
int					check_args(int ac, char **av);
int					ft_isdigit(int c);
void				ft_usleep(int ms);
void				print_error(void);

void				init_philos(t_data *data);
void				init_forks(t_data *data);
int					init_values(t_data *data, int ac, char **av);
void				print_eat(t_philo *philo);
void				print_think(t_philo *philo);
void				print_dead(t_philo *philo);
void				print_sleep(t_philo *philo);
void				print_forks(t_philo *philo);
void				start(t_data *data);
void				*routine(void *philo);
void				sleep(t_philo *philo);
void				leave_fork(t_philo *philo);
void			    *check_death(void *void_data);
int					eat_enough(t_data *data);

#endif
