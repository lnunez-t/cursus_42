/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laura <laura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 15:00:29 by lnunez-t          #+#    #+#             */
/*   Updated: 2024/05/19 16:54:36 by laura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h> 
# include <sys/time.h>
# include <limits.h> 
# include "messages.h"

# define SUCCESS		0
# define FAILURE		-42

typedef struct s_philo
{
	int				meal_eaten;
	int				id_num;
	pthread_t		thd;
	long long		last_meal;
	int				right_f;
	int				left_f;
	struct s_data			*args;
}					t_philo;

typedef struct s_data
{
	int				error;
	bool			fnsh_game;
	int				end_meal;
	long long		t_start;
	long long		t_eat;
	long long		t_die;
	long long		t_sleep;
	int				n_philo;
	int				meal_limit;
	struct s_philo			*philo;
	pthread_mutex_t	checks;
	pthread_mutex_t	*fork;
}					t_data;

int			check_digit(char **str);
int			ft_atoi(const char *str);
int			validate_args(int ac, char **av);
int			ft_atoi(const char *str);
int			check_overflow(t_data *store, char **av);
long long	timestart(void);
long long	timestamp(t_data *store);
int			init_start(char **av, t_data *store);
void		*ft_calloc(size_t count, size_t size);
void		init_philos(t_data *store);
void		philo_start(t_data *store);
void		*routine(void *val);
void		*single_philo(void *p);
void		printer(t_philo *plo, char *str);
void		ft_sleeper(t_philo *plo, int t_2_wait);
void		philo_destroy(t_data *store);
void		monitor(t_data *store);
void		p_eats(t_philo *plo);
void		p_thinks(t_philo *plo);
void		p_sleeps(t_philo *plo);
void		check_life(t_philo *plo);
void		grab_fork(t_philo *plo);
void		meal_limit_check(t_data *store);
void		printeright_f(t_philo *plo);

#endif
