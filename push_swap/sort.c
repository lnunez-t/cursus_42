/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnunez-t <lnunez-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 19:10:36 by lnunez-t          #+#    #+#             */
/*   Updated: 2023/12/19 15:12:49 by lnunez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	split_stack(t_list **stack1, t_list **stack2, t_push *push, int size)
{
	int	i;

	i = -1;
	while (++i < size)
	{
		if ((*stack1)->index <= push->mid)
			pb(stack1, stack2);
		else
		{
			if (ft_lstsize(*stack2) > 1 && (*stack2)->index < (push->mid / 2))
				rr(stack1, stack2);
			else
				ra(stack1);
		}
	}
	push->max = push->mid;
	push->mid = (push->max - push->next) / 2 + push->next;
	push->flag++;
}

void	find_next(t_list **stack1, t_list **stack2, t_push *push)
{
	if (ft_lstsize(*stack2) > 0 && ((*stack2)->index == push->next))
		pa(stack1, stack2);
	else if ((*stack1)->index == push->next)
	{
		(*stack1)->flag = -1;
		ra(stack1);
		push->next++;
	}
	else if (ft_lstsize(*stack2) > 2
		&& ft_lstlast(*stack2)->index == push->next)
		rrb(stack2);
	else if ((*stack1)->next->index == push->next)
		sa(stack1);
	else if ((ft_lstsize(*stack1)) > 1 && ((*stack1)->next->index == push->next)
		&& ((*stack2)->next->index == push->next + 1))
		ss(stack1, stack2);
	else
		return ;
	find_next(stack1, stack2, push);
}

void	sort_a(t_list **stack1, t_list **stack2, t_push *push)
{
	int	size_b;
	int	i;

	i = -1;
	size_b = ft_lstsize(*stack2);
	while (ft_lstsize(*stack2) && ++i < size_b)
	{
		if ((*stack2)->index == push->next)
			find_next(stack1, stack2, push);
		else if ((*stack2)->index >= push->mid)
		{
			(*stack2)->flag = push->flag;
			pa(stack1, stack2);
		}
		else if ((*stack2)->index < push->mid)
			rb(stack2);
	}
	push->max = push->mid;
	push->mid = (push->max - push->next) / 2 + push->next;
	push->flag++;
}

void	sort_b(t_list **stack1, t_list **stack2, t_push *push)
{
	int	now_flag;

	now_flag = ((*stack1)->flag);
	if ((*stack1)->flag != 0)
	{
		while ((*stack1)->flag == now_flag)
		{
			if ((*stack1)->index != push->next)
				pb(stack1, stack2);
			find_next(stack1, stack2, push);
		}
	}
	else if ((*stack1)->flag == 0)
	{
		while ((*stack1)->flag != -1)
		{
			if ((*stack1)->index != push->next)
				pb(stack1, stack2);
			find_next(stack1, stack2, push);
		}
	}
	if (ft_lstsize(*stack2))
		push->max = (is_max(stack2))->index;
	push->mid = (push->max - push->next) / 2 + push->next;
}

void	sort(t_list **stack1, t_list **stack2, int size)
{
	t_push	push;

	push.next = is_min(stack1)->index;
	push.max = is_max(stack1)->index;
	push.mid = push.max / 2 + push.next;
	push.flag = 0;
	split_stack(stack1, stack2, &push, size);
	while (!(is_a_sorted(stack1, size)))
	{
		if (ft_lstsize(*stack2) == 0)
			sort_b(stack1, stack2, &push);
		else
			sort_a(stack1, stack2, &push);
	}
}
