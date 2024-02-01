/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnunez-t <lnunez-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 15:00:26 by lnunez-t          #+#    #+#             */
/*   Updated: 2024/02/01 13:52:24 by lnunez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo(t_data *data)
{
	int	i;

	data->t_start = millitimestamp();
	i = -1;
	while (++i < data->nb_philo)
	{
		data->philo[i].n = i + 1;
		data->philo[i].last_eat = 0;
		data->philo[i].right_fork = NULL;
		data->philo[i].info = data;
		data->philo[i].n_eat = 0;
		pthread_mutex_init(data->philo[i].left_fork, NULL);
		if (i == data->nb_philo - 1)
			data->philo[i].left_fork = data->philo[0].right_fork;
		else
			data->philo[i].left_fork = data->philo[i + 1].right_fork;
		if (pthread_create(&data->philo[i].thread_id, NULL,
				&philo_life, &data->philo[i]) != 0)
			return (-1);
	}
	return (0);
}

int	main(int ac, char **argv)
{
	t_data	*data;

	if (ac != 5 && ac != 6)
		printf("%s", "Invalid number of arguments !");
	if (init_values(&data, argv) == 1)
		return (0);
	philo(data);
}
