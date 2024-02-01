/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnunez-t <lnunez-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 16:51:02 by lnunez-t          #+#    #+#             */
/*   Updated: 2024/01/19 16:25:23 by lnunez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	check_sort(t_stack *stack)
{
	int	len;

	len = ft_lstsize(stack->stack_a);
	if (is_sorted(&stack->stack_a))
		return ;
	if (len == 2)
	{
		if (stack->stack_a->content > stack->stack_a->next->content)
			sa(&stack->stack_a);
	}
	else if (len == 3)
		sort3(stack);
	else if (len == 5)
		sort5(stack);
	else
		sort(&stack->stack_a, &stack->stack_b, len);
}

void	ft_free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int	main(int ac, char **argv)
{
	t_stack	*tab;
	char	**args;

	if (ac == 1)
		return (0);
	tab = malloc(sizeof(t_stack));
	if (!tab)
		return (free(tab), -1);
	if (ac == 2)
		args = ft_split(argv[1], ' ');
	else
		args = argv;
	tab->stack_a = init(args, ac);
	if (ac == 2)
		ft_free_tab(args);
	if (tab->stack_a == NULL)
		return (free(tab), -1);
	tab->stack_b = NULL;
	tab->size_a = ft_lstsize(tab->stack_a);
	tab->size_b = ft_lstsize(tab->stack_b);
	add_index(tab->stack_a);
	check_sort(tab);
	final_clean(tab);
}
