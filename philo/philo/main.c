/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laura <laura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 15:00:26 by lnunez-t          #+#    #+#             */
/*   Updated: 2024/05/11 15:28:05 by laura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	alone(t_data *data)
{
	print_think(&data->philo[0]);
	ft_usleep(data->time_to_die);
	print_dead(&data->philo[0]);
}

void	start(t_data *data)
{
	int	i;

	data->t_start = millitimestamp();
	if (data->nb_philo == 1)
		return (alone(data));
	i = 0;
	while (i < data->nb_philo)
	{
		pthread_create(&data->threads[i], NULL, &routine, &data->philo[i]);
		i++;
	}
	data->t_start = millitimestamp();
	i = 0;
	while (i < data->nb_philo)
	{
		pthread_join(data->threads[i], NULL);
		i++;
	}
}

void	end(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		pthread_mutex_destroy(&data->forks[i]);
		i++;
	}
	if (data->forks)
		free (data->forks);
	if (data->threads)
		free (data->threads);
	if (data->philo)
		free (data->philo);
}

int	main(int ac, char **argv)
{
	t_data	*data;

	data = NULL;
	if (check_args(ac, argv))
		print_error();
	init_values(data, ac, argv);
	init_philos(data);
	init_forks(data);
	start(data);
	end(data);
	return (0);
}
