/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laura <laura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 12:34:16 by laura             #+#    #+#             */
/*   Updated: 2024/05/19 17:10:33 by laura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*single_philo(void *p) 
{   
	t_philo	*philo;   
   
	philo = (t_philo *)p;  
	pthread_mutex_lock(&philo->args->fork[philo->left_f]);
	printer(philo, FORK);
	ft_sleeper(philo, philo->args->t_die); 
	pthread_mutex_unlock(&philo->args->fork[philo->left_f]);
	printer(philo, DIED);
	pthread_mutex_lock(&philo->args->checks);
	philo->args->fnsh_game = true;
	pthread_mutex_unlock(&philo->args->checks);
	return (NULL);
}

void	grab_fork(t_philo *philo)
{
	if (philo->id_num % 2)
	{
		usleep(1500);
		pthread_mutex_lock(&philo->args->fork[philo->left_f]);
		pthread_mutex_lock(&philo->args->fork[philo->right_f]);
		printeright_f(philo);
	}
	else
	{
		pthread_mutex_lock(&philo->args->fork[philo->right_f]);
		pthread_mutex_lock(&philo->args->fork[philo->left_f]);
		printeright_f(philo);
	}
}

void	p_eats(t_philo *philo)
{
	bool	lock;

	lock = true;
	pthread_mutex_lock(&philo->args->checks);
	if (philo->args->fnsh_game == false)
	{
		lock = false;
		pthread_mutex_unlock(&philo->args->checks);
		grab_fork(philo);
		printer(philo, EATING);
		pthread_mutex_lock(&philo->args->checks);
		philo->last_meal = timestamp(philo->args);
		philo->meal_eaten++;
		pthread_mutex_unlock(&philo->args->checks);
		ft_sleeper(philo, philo->args->t_eat);
		pthread_mutex_unlock(&philo->args->fork[philo->left_f]);
		pthread_mutex_unlock(&philo->args->fork[philo->right_f]);
	}
	if (lock)
		pthread_mutex_unlock(&philo->args->checks);
}

void	p_thinks(t_philo *philo)
{
	if (philo->args->fnsh_game == false)
		printer(philo, THINKING);
}

void	p_sleeps(t_philo *philo)
{
	if (philo->args->fnsh_game == false)
	{
		printer(philo, SLEEPING);
		ft_sleeper(philo, philo->args->t_sleep);
	}
}