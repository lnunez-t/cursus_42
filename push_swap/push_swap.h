/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnunez-t <lnunez-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 16:41:55 by lnunez-t          #+#    #+#             */
/*   Updated: 2024/01/19 16:22:42 by lnunez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_list
{
	long int		content;
	int				flag;
	int				index;
	struct s_list	*next;
}					t_list;

typedef struct s_push
{
	int	next;
	int	max;
	int	min;
	int	mid;
	int	flag;
}		t_push;

typedef struct s_stack
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		size_a;
	int		size_b;
}			t_stack;

int			ft_lstsize(t_list *lst);
char		**ft_split(char const *s, char c);
t_list		*ft_lstnew(long content);
long		ft_atoi(const char *nptr);
int			ft_isdigit(int c);
void		ft_putstr_fd(char *s, int fd);
void		ft_lstadd_back(t_list **lst, t_list *new);
t_list		*ft_lstlast(t_list *lst);

t_list		*is_min(t_list **stack1);
t_list		*is_max(t_list **stack1);
t_list		*init(char **arg, int ac);
int			index_min(t_list *stack1);
int			check_error(t_list *stack, int n, char *nb);
int			is_sorted(t_list **stack);
int			is_rev(t_stack *stack);
void		sort3(t_stack *stack);
void		sort5(t_stack *stack);
void		index_replace(t_list *stack, int n, int to);
void		add_index(t_list *stack);
void		split_stack(t_list **stack1, t_list **stack2,
				t_push *push, int size);
void		find_next(t_list **stack1, t_list **stack2, t_push *push);
void		sort_a(t_list **stack1, t_list **stack2, t_push *push);
void		sort_b(t_list **stack1, t_list **stack2, t_push *push);
void		sort(t_list **stack1, t_list **stack2, int size);
int			is_a_sorted(t_list **stack1, int size);
void		ft_clean(t_list *tab);
void		final_clean(t_stack *tab);
void		free_tab(char **dest);
void		ft_free_tab(char **tab);

void		pa(t_list **stack1, t_list **stack2);
void		pb(t_list **stack1, t_list **stack2);
void		sa(t_list **stack1);
void		sb(t_list **stack2);
void		ss(t_list **stack1, t_list **stack2);
void		ra(t_list **stack1);
void		rb(t_list **stack2);
void		rr(t_list **stack1, t_list **stack2);
void		rra(t_list **stack1);
void		rrb(t_list **stack2);
void		rrr(t_list **stack1, t_list **stack2);

#endif
