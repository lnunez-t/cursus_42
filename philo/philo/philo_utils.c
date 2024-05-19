/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laura <laura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 15:10:10 by lnunez-t          #+#    #+#             */
/*   Updated: 2024/05/19 17:05:55 by laura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_isdigit(int nbr)
{
	if (nbr >= '0' && nbr <= '9')
		return (FAILURE);
	return (SUCCESS);
}

int	check_digit(char **str)
{
	int	i;
	int	j;

	i = 1;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (!ft_isdigit(str[i][j]))
				return (FAILURE);
			j++;
		}
		i++;
	}
	return (SUCCESS);
}

int	ft_atoi(const char *str)
{
	int		i;
	long	res;

	i = 0;
	res = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == ' '))
		i++;
	if (str[i] == '-')
		return (FAILURE);
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	if (res > 2147483647)
		return (FAILURE);
	return (res);
}

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	size_t	j;
	char	*ptr;

	i = 0;
	j = count * size;
	if (size >= SIZE_MAX / count)
		return (NULL);
	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	while (i < j)
	{
		ptr[i] = '\0';
		i++;
	}
	return (ptr);
}

void	printer(t_philo *philo, char *str)
{
	if (philo->args->fnsh_game == false)
	{
		pthread_mutex_lock(&philo->args->checks);
		printf("%lld\t | \t%d\t |    %s\n",
			timestamp(philo->args), philo->id_num, str);
		pthread_mutex_unlock(&philo->args->checks);
	}
}
