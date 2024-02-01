/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnunez-t <lnunez-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 11:02:33 by lnunez-t          #+#    #+#             */
/*   Updated: 2024/02/01 13:46:29 by lnunez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_fork(t_philo *philo)
{
	pthread_mutex_lock(&(philo->left_fork));
	printf("Philo %i %s\n", philo->n, FORK);
	pthread_mutex_lock(&(philo->right_fork));
	printf("Philo %i %s\n", philo->n, FORK);
}

void	philo_eat(t_philo *philo)
{
	long long	time;

	printf("Philo %d %s", philo->n, EAT);
	philo->last_eat = millitimestamp();
	philo->n_eat++;
	ft_usleep(philo->info->time_to_eat);
	pthread_mutex_unlock(&(philo->right_fork));
	pthread_mutex_unlock(&(philo->left_fork));
	printf("Philo %d %s", philo->n, SLEEP);
	ft_usleep(philo->info->time_to_sleep);
	printf("Philo %d %s", philo->n, THINK);
}

void	*philo_life(void *philo)
{
	t_philo		*philo;
	pthread_t	t;


}

