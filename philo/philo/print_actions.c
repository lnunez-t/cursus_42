/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laura <laura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 12:34:16 by laura             #+#    #+#             */
/*   Updated: 2024/02/04 12:42:21 by laura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_eat(t_philo *philo)
{
    printf("%ld %d is eating\n", millitimestamp() - philo->info->t_start, philo->n);
}

void	print_think(t_philo *philo)
{
    printf("%ld %d is thinking\n", millitimestamp() - philo->info->t_start, philo->n);
}

void	print_dead(t_philo *philo)
{
    printf("%ld %d is dead\n", millitimestamp() - philo->info->t_start, philo->n);
}

void	print_sleep(t_philo *philo)
{
    printf("%ld %d is sleeping\n", millitimestamp() - philo->info->t_start, philo->n);
}

void	print_forks(t_philo *philo)
{
    printf("%ld %d has taken a fork\n", millitimestamp() - philo->info->t_start, philo->n);
}