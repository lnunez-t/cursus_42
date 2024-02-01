/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rules.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnunez-t <lnunez-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 11:34:16 by lnunez-t          #+#    #+#             */
/*   Updated: 2023/11/24 17:43:55 by lnunez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_rev(t_list **stack)
{
	t_list	*temp;
	t_list	*end;

	if (!(*stack) || !((*stack)->next))
		return ;
	temp = *stack;
	end = ft_lstlast(*stack);
	while ((*stack)->next->next)
		*stack = (*stack)->next;
	end->next = temp;
	(*stack)->next = NULL;
	*stack = end;
}

void	rra(t_list **stack1)
{
	ft_rev(stack1);
	write(1, "rra\n", 4);
}

void	rrb(t_list **stack2)
{
	ft_rev(stack2);
	write(1, "rrb\n", 4);
}

void	rrr(t_list **stack1, t_list **stack2)
{
	ft_rev(stack1);
	ft_rev(stack2);
	write(1, "rrr\n", 4);
}
