/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnunez-t <lnunez-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 15:10:10 by lnunez-t          #+#    #+#             */
/*   Updated: 2024/01/31 15:27:59 by lnunez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *nptr)
{
	int		sign;
	int		nb;
	size_t	i;

	i = 0;
	sign = 1;
	nb = 0;
	while ((nptr[i] > 8 && nptr[i] < 14) || nptr[i] == 32)
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nb = nb * 10 + (nptr[i] - '0');
		i++;
	}
	return (nb * sign);
}

long long	millitimestamp(void)
{
	struct timeval	timeval;
	long long		millitime;

	gettimeofday(&timeval, NULL);
	millitime = timeval.tv_sec * 1000 + timeval.tv_usec / 1000;
	return (millitime);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

void	ft_usleep(int ms)
{
	long int	time;

	time = millitimestamp();
	while (millitimestamp() - time < ms)
		usleep(ms / 10);
}
