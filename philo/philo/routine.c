/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laura <laura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 11:02:33 by lnunez-t          #+#    #+#             */
/*   Updated: 2024/05/19 17:32:45 by laura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_start(t_data *data)
{
	int	i;

	if (data->n_philo == 1)
		single_philo(data->philo);
	else
	{
		i = -1;
		while (++i < data->n_philo) 
			pthread_create(&data->philo[i].thd, NULL,
				&routine, (void *)&data->philo[i]); 
		while (data->fnsh_game == false)
			monitor(data);
	}
} 
 
void	*routine(void *ph)
{
	t_philo	*philo;
	t_data	*data;

	philo = (t_philo *)ph;
	data = philo->args;
	while (data->fnsh_game == false)
	{
		pthread_mutex_lock(&philo->args->checks);
		if (data->meal_limit > 0 && philo->meal_eaten == data->meal_limit)
		{
			pthread_mutex_unlock(&philo->args->checks);
			break ;
		}
		pthread_mutex_unlock(&philo->args->checks);
		p_eats(philo);
		p_sleeps(philo);
		p_thinks(philo);
	}
	return (NULL);
}

void	monitor(t_data *data)
{
	int	death_id;

	death_id = 0;
	while (data->fnsh_game == false) 
	{
		check_life(&data->philo[death_id]);
		meal_limit_check(data);
		usleep(1000);
		if (death_id == data->n_philo - 1)
			death_id = -1;
		death_id++;
	}
}

void	check_life(t_philo *philo)
{
	bool	lock;

	lock = true;
	pthread_mutex_lock(&philo->args->checks);
	if ((timestamp(philo->args) - philo->last_meal) >= philo->args->t_die)
	{
		lock = false;
		pthread_mutex_unlock(&philo->args->checks);
		printer(philo, DIED);
		pthread_mutex_lock(&philo->args->checks);
		philo->args->fnsh_game = true; 
		pthread_mutex_unlock(&philo->args->checks);
	}
	if (lock)
		pthread_mutex_unlock(&philo->args->checks);
}

void	meal_limit_check(t_data *data)
{
	int	meal_nbr;

	meal_nbr = 0;
	if (data->meal_limit > 0)
	{
		while (meal_nbr < data->n_philo)
		{
			pthread_mutex_lock(&data->checks); 
			if (data->philo[meal_nbr].meal_eaten < data->meal_limit)
			{
				pthread_mutex_unlock(&data->checks);
				break ;
			}
			pthread_mutex_unlock(&data->checks);
			meal_nbr++;
		}
		if (meal_nbr == data->n_philo)
		{
			pthread_mutex_lock(&data->checks);
			data->fnsh_game = true;
			pthread_mutex_unlock(&data->checks);
		}
	}
}