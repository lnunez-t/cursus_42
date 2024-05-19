/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laura <laura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 16:37:38 by lnunez-t          #+#    #+#             */
/*   Updated: 2024/05/19 17:01:58 by laura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	validate_args(int ac, char **av)  
{   
	if (ac != 5 && ac != 6)    
	{    
		printf("%s\n", ERROR2);
		printf("%s\n", ERROR3);   
		return (FAILURE); 
	}
	if (ac == 6)
	{ 
		if (av[5][0] == '\0') 
		{ 
			printf("%s", ERROR1);
			return (FAILURE);
		}
	}
	if (check_digit(av))
	{
		printf("%s", ERROR1);
		return (FAILURE);
	}
	return (SUCCESS);
}

int	check_overflow(t_data *data, char **av)
{
	if (data->t_sleep < 0 || data->t_eat < 0 || data->t_die < 0
		|| data->n_philo > 200 || data->n_philo < 0)
		return (FAILURE);
	if (data->t_die < 60 || data->t_eat < 60 || data->t_sleep < 60)
		return (FAILURE);
	if (av[5])
	{
		data->meal_limit = ft_atoi(av[5]);
		if (data->meal_limit < 0)
			return (FAILURE);
	}
	else
		data->meal_limit = false;
	return (SUCCESS);
}

int	init_start(char **av, t_data *data)
{
	int	i;

	i = -1;
	data->error = false;
	data->fnsh_game = false;
	data->end_meal = 0;
	data->n_philo = ft_atoi(av[1]);
	data->t_die = ft_atoi(av[2]);
	data->t_eat = ft_atoi(av[3]);
	data->t_sleep = ft_atoi(av[4]);
	if (check_overflow(data, av)) 
	{
		printf("%s", ERROR1);
		return (free(data), 1);
	}
	data->philo = ft_calloc(data->n_philo, (sizeof(t_philo)));
	data->fork = ft_calloc(data->n_philo, (sizeof(pthread_mutex_t)));
	pthread_mutex_init(&data->checks, NULL);
	while (++i < data->n_philo)
		pthread_mutex_init(&data->fork[i], NULL);
	init_philos(data);
	data->t_start = timestart();
	return (SUCCESS);
}

void	init_philos(t_data *store)
{
	int	i;

	i = 0;
	while (i < store->n_philo)
	{
		store->philo[i].id_num = i + 1;
		store->philo[i].meal_eaten = 0;
		store->philo[i].last_meal = 0;
		store->philo[i].left_f = i;
		store->philo[i].right_f = (i + 1) % store->n_philo;
		store->philo[i].args = store; 
		i++;
	}
}

void	philo_destroy(t_data *store)
{
	int	i;

	i = 0;
	if (store->n_philo > 1)
	{
		while (i < store->n_philo)
			pthread_join(store->philo[i++].thd, NULL);
	}
	i = 0;
	while (i < store->n_philo)
		pthread_mutex_destroy(&store->fork[i++]);
	pthread_mutex_destroy(&store->checks);
	free(store->philo);
	free(store->fork);
	free(store);
}
