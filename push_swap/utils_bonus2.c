/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnunez-t <lnunez-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 10:13:20 by lnunez-t          #+#    #+#             */
/*   Updated: 2024/01/19 16:09:07 by lnunez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	if (*lst)
		ft_lstlast(*lst)->next = new;
	else
		*lst = new;
}

t_list	*ft_lstlast(t_list *lst)
{
	while (lst && lst->next)
		lst = lst->next;
	return (lst);
}

t_list	*ft_lstnew(long content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (free(new), NULL);
	new->content = content;
	new->next = NULL;
	return (new);
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
