/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnunez-t <lnunez-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 15:00:29 by lnunez-t          #+#    #+#             */
/*   Updated: 2024/02/01 13:53:29 by lnunez-t         ###   ########.fr       */
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
	int				stop;
	long int		t_start;
	t_philo			*philo;
	pthread_mutex_t	eat;
	pthread_mutex_t	end;
	pthread_mutex_t	dead;
}					t_data;

int					ft_atoi(const char *nptr);
long long			millitimestamp(void);
int					init_values(t_data *data, char **av);
int					check_args(char **av);
int					ft_isdigit(int c);
void				ft_usleep(int ms);

void				*philo_life(void *philo);
void				philo_eat(t_philo *philo);
void				take_fork(t_philo *philo);

#endif
