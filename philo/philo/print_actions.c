/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laura <laura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 12:34:16 by laura             #+#    #+#             */
/*   Updated: 2024/05/11 15:31:34 by laura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_eat(t_philo *philo)
{
    printf("%lld %d is eating\n", millitimestamp() - philo->info->t_start, philo->n);
}

void	print_think(t_philo *philo)
{
    printf("%lld %d is thinking\n", millitimestamp() - philo->info->t_start, philo->n);
}

void	print_dead(t_philo *philo)
{
    printf("%lld %d is dead\n", millitimestamp() - philo->info->t_start, philo->n);
}

void	print_sleep(t_philo *philo)
{
    printf("%lld %d is sleeping\n", millitimestamp() - philo->info->t_start, philo->n);
}

void	print_forks(t_philo *philo)
{
    printf("%lld %d has taken a fork\n", millitimestamp() - philo->info->t_start, philo->n);
}