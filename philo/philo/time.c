/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laura <laura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 16:52:27 by laura             #+#    #+#             */
/*   Updated: 2024/05/19 16:58:41 by laura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	timestart(void)
{
	struct timeval	start_time;

	gettimeofday(&start_time, NULL);
	return ((start_time.tv_sec * 1000) + (start_time.tv_usec / 1000));
}

long long	timestamp(t_data *store)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (((time.tv_sec * 1000) + (time.tv_usec / 1000)) - store->t_start);
}

void	ft_sleeper(t_philo *plo, int t_2_wait)
{
	long long	current_time;
	long long	diff;

	current_time = timestamp(plo->args);
	while (1)
	{
		pthread_mutex_lock(&plo->args->checks);
		diff = (timestamp(plo->args) - current_time);
		if (diff >= t_2_wait)
		{
			pthread_mutex_unlock(&plo->args->checks);
			break ;
		}
		pthread_mutex_unlock(&plo->args->checks);
		usleep (100);
	}
}

void	printeright_f(t_philo *plo)
{
	printer(plo, FORK);
	printer(plo, FORK);
}