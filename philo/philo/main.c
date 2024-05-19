/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laura <laura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 15:00:26 by lnunez-t          #+#    #+#             */
/*   Updated: 2024/05/19 16:46:30 by laura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)    
{
	t_data	*data;

	if (validate_args(ac, av) != 0)
		return (FAILURE);
	data = (t_data *)ft_calloc(1, sizeof(t_data));
	if (!data)
		return (FAILURE);
	if (init_start(av, data))
		return (FAILURE);
	philo_start(data);
	philo_destroy(data);
	return (SUCCESS);
}
