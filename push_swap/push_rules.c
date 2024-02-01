/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_rules.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnunez-t <lnunez-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 11:33:37 by lnunez-t          #+#    #+#             */
/*   Updated: 2023/12/19 11:51:04 by lnunez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_push(t_list **stack1, t_list **stack2)
{
	t_list	*stack;

	if (!*stack2)
		return ;
	stack = (*stack2)->next;
	(*stack2)->next = *stack1;
	*stack1 = *stack2;
	*stack2 = stack;
}

void	pa(t_list **stack1, t_list **stack2)
{
	ft_push(stack1, stack2);
	write(1, "pa\n", 3);
}

void	pb(t_list **stack1, t_list **stack2)
{
	ft_push(stack2, stack1);
	write(1, "pb\n", 3);
}
