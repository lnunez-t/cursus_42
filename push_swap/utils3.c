/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnunez-t <lnunez-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 15:04:13 by lnunez-t          #+#    #+#             */
/*   Updated: 2024/01/19 13:57:23 by lnunez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_a_sorted(t_list **stack1, int size)
{
	int	len;

	len = ft_lstsize(*stack1);
	if (len != size)
		return (0);
	if (is_sorted(stack1) == 0)
		return (0);
	return (1);
}

void	ft_clean(t_list *tab)
{
	t_list	*temp;
	int		i;

	i = ft_lstsize(tab);
	while (i > 0)
	{
		temp = tab->next;
		free(tab);
		tab = temp;
		i--;
	}
}

void	final_clean(t_stack *tab)
{
	ft_clean(tab->stack_a);
	ft_clean(tab->stack_b);
	free(tab);
}
