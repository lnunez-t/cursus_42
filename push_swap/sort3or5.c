/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3or5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnunez-t <lnunez-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 18:52:53 by lnunez-t          #+#    #+#             */
/*   Updated: 2023/12/02 17:25:15 by lnunez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort3(t_stack *stack)
{
	t_list	*last;

	if (is_sorted(&stack->stack_a))
		return ;
	last = ft_lstlast(stack->stack_a);
	if (is_rev(stack))
	{
		sa(&stack->stack_a);
		rra(&stack->stack_a);
	}
	else if (stack->stack_a->content > last->content
		&& stack->stack_a->next->content < last->content)
		ra(&stack->stack_a);
	else if (stack->stack_a->content < last->content
		&& stack->stack_a->next->content < last->content)
		sa(&stack->stack_a);
	else if (stack->stack_a->content > last->content
		&& stack->stack_a->next->content > last->content)
		rra(&stack->stack_a);
	else if (stack->stack_a->content < last->content
		&& stack->stack_a->next->content > last->content)
	{
		sa(&stack->stack_a);
		ra(&stack->stack_a);
	}
}

void	sort5(t_stack *stack)
{
	int		len;

	len = ft_lstsize(stack->stack_a);
	while (len--)
	{
		if (stack->stack_a->index == 0 || stack->stack_a->index == 1)
			pb(&stack->stack_a, &stack->stack_b);
		else
			ra(&stack->stack_a);
	}
	sort3(stack);
	pa(&stack->stack_a, &stack->stack_b);
	pa(&stack->stack_a, &stack->stack_b);
	if (stack->stack_a->content > stack->stack_a->next->content)
		sa(&stack->stack_a);
}
