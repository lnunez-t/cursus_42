/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnunez-t <lnunez-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 18:16:21 by lnunez-t          #+#    #+#             */
/*   Updated: 2023/12/20 14:09:28 by lnunez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	index_replace(t_list *stack, int n, int to)
{
	t_list	*tmp;

	tmp = stack;
	while (tmp)
	{
		if (tmp->index == -1 && tmp->content == n)
			break ;
		tmp = tmp->next;
	}
	tmp->index = to;
}

int	index_min(t_list *stack1)
{
	t_list		*tmp;
	long int	min;

	min = 9223372036854775807;
	tmp = stack1;
	while (tmp)
	{
		if (tmp->index == -1 && tmp->content < min)
			min = tmp->content;
		tmp = tmp->next;
	}
	return (min);
}

void	add_index(t_list *stack)
{
	int	len;
	int	min;
	int	i;

	i = 0;
	len = ft_lstsize(stack);
	while (i < len)
	{
		min = index_min(stack);
		index_replace(stack, min, i);
		i++;
	}
}
