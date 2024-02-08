/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laura <laura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 17:54:34 by laura             #+#    #+#             */
/*   Updated: 2024/02/08 18:24:25 by laura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_args(int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	if (ac != 5 && ac != 6)
		return (1);
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (!ft_isdigit(av[i][j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void    *check_death(void *void_data)
{
    int		i;
    t_data	*data;

	i = 0;
	data = (t_data *)void_data;
	while (1)
	{
		if (eat_enough(data))
			break;
		if (millitimestamp() - data->philo[i].last_eat > data->time_to_die
			&& data->philo[i].last_eat != -1
			&& (data->philo[i].n_eat < data->nb_meals
			|| data->nb_meals == -1))
			{
				print_dead(&data->philo[i]);
				data->has_died = 1;
				exit (EXIT_FAILURE);
			}
			i = (i + 1) % data->nb_philo;
	}
	return (0);
}

int	eat_enough(t_data *data)
{
	int	i;
	
	i = 0;
	if (data->nb_meals == -1)
		return (0);
	while (i < data->nb_philo)
	{
		if (data->philo[i].n_eat < data->nb_meals)
			return (0);
		i++;
	}
	return (1);
}