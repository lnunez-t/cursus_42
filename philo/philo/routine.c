/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laura <laura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 11:02:33 by lnunez-t          #+#    #+#             */
/*   Updated: 2024/05/11 15:29:22 by laura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	printf("Philo %i %s\n", philo->n, FORK);
	pthread_mutex_lock(philo->right_fork);
	printf("Philo %i %s\n", philo->n, FORK);
}

void	leave_fork(t_philo *philo)
{
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	ft_sleep(philo);
}

void	philo_eat(t_philo *philo)
{
	printf("Philo %d %s", philo->n, EAT);
	philo->last_eat = millitimestamp();
	philo->n_eat++;
	ft_usleep(philo->info->time_to_eat);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
	printf("Philo %d %s", philo->n, SLEEP);
	ft_usleep(philo->info->time_to_sleep);
	printf("Philo %d %s", philo->n, THINK);
}

void	ft_sleep(t_philo *philo)
{
	print_sleep(philo);
	ft_usleep(philo->info->time_to_sleep);
	philo->n_eat++;
}

void	*routine(void *philo)
{
	t_philo	*ph;

	ph = (t_philo *)philo;
	ph->last_eat = millitimestamp();
	pthread_create(&ph->thread_id, NULL, &check_death, ph->info);
	pthread_detach(ph->thread_id);
	if (ph->n % 2 == 0)
		ft_usleep(1);
	while (!ph->info->has_died && !eat_enough(ph->info))
	{
		print_think(ph);
		take_fork(ph);
		print_eat(ph);
		ph->last_eat = millitimestamp();
		ft_usleep(ph->info->time_to_eat - 5);
		leave_fork(ph);
	}
	return (NULL);
}