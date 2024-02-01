/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnunez-t <lnunez-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 09:31:16 by lnunez-t          #+#    #+#             */
/*   Updated: 2024/01/24 14:42:35 by lnunez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	check_input(char *input, t_stack *tab)
{
	if (ft_strcmp(input, "sa\n") == 0)
		sa(&tab->stack_a);
	else if (ft_strcmp(input, "sb\n") == 0)
		sb(&tab->stack_b);
	else if (ft_strcmp(input, "ss\n") == 0)
		ss(&tab->stack_a, &tab->stack_b);
	else if (ft_strcmp(input, "pa\n") == 0)
		pa(&tab->stack_a, &tab->stack_b);
	else if (ft_strcmp(input, "pb\n") == 0)
		pb(&tab->stack_a, &tab->stack_b);
	else if (ft_strcmp(input, "ra\n") == 0)
		ra(&tab->stack_a);
	else if (ft_strcmp(input, "rb\n") == 0)
		rb(&tab->stack_b);
	else if (ft_strcmp(input, "rra\n") == 0)
		rra(&tab->stack_a);
	else if (ft_strcmp(input, "rrb\n") == 0)
		rrb(&tab->stack_b);
	else
	{
		free(input);
		return (0);
	}
	free(input);
	return (1);
}

int	check_error(t_list *stack, int n, char *nb)
{
	int			i;
	t_list		*tmp;

	i = 0;
	tmp = stack;
	while (nb[i])
	{
		if (!(((nb[i] == '-' || nb[i] == '+') && ft_isdigit(nb[i + 1])
					&& (i == 0 || !ft_isdigit(nb[i - 1])))
				|| ft_isdigit(nb[i])))
			return (0);
		i++;
	}
	while (tmp)
	{
		if (tmp->content == n)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

t_list	*init(char **arg, int ac)
{
	t_list	*tmp;
	t_list	*res;
	int		i;
	long	nb;

	if (ac == 2)
		i = 0;
	else
		i = 1;
	res = NULL;
	while (arg[i])
	{
		nb = ft_atoi(arg[i]);
		if (nb > 2147483647 || nb < -2147483648
			|| !check_error(res, nb, arg[i]))
		{
			ft_putstr_fd("Error\n", 2);
			return (ft_clean(res), NULL);
		}
		tmp = ft_lstnew(nb);
		ft_lstadd_back(&res, tmp);
		tmp->index = -1;
		i++;
	}
	return (res);
}

void	input(t_stack *tab)
{
	char	*input;

	input = get_next_line(0);
	while (input)
	{
		if (!check_input(input, tab))
		{
			ft_putstr_fd("Error\n", 1);
			final_clean(tab);
			exit (-1);
		}
		input = get_next_line(0);
	}
}

int	main(int ac, char **argv)
{
	t_stack	*tab;

	if (ac == 2)
		argv = ft_split(argv[1], ' ');
	if (ac == 1)
		return (0);
	tab = malloc(sizeof(t_stack));
	if (!tab)
		return (free(tab), -1);
	tab->stack_b = NULL;
	tab->stack_a = init(argv, ac);
	if (ac == 2)
		ft_free_tab(argv);
	if (tab->stack_a == NULL)
		return (free(tab->stack_a), -1);
	input(tab);
	if (is_sorted(tab->stack_a) && !tab->stack_b)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	final_clean(tab);
}
