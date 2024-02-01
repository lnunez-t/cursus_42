/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnunez-t <lnunez-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 09:31:52 by lnunez-t          #+#    #+#             */
/*   Updated: 2024/01/19 16:26:03 by lnunez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include "get_next_line/get_next_line.h"

typedef struct s_list
{
	long int		content;
	int				flag;
	int				index;
	struct s_list	*next;
}					t_list;

typedef struct s_stack
{
	t_list	*stack_a;
	t_list	*stack_b;
}			t_stack;

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

int			is_sorted(t_list *stack);
int			check_input(char *input, t_stack *tab);
int			check_error(t_list *stack, int n, char *nb);
t_list		*init(char **arg, int ac);
void		input(t_stack *tab);
int			ft_strcmp(char *s1, char *s2);
char		**ft_split(char const *s, char c);
t_list		*ft_lstnew(long content);
long		ft_atoi(const char *nptr);
int			ft_isdigit(int c);
void		ft_putstr_fd(char *s, int fd);
void		ft_lstadd_back(t_list **lst, t_list *new);
t_list		*ft_lstlast(t_list *lst);
void		ft_clean(t_list *tab);
int			ft_lstsize(t_list *lst);
void		final_clean(t_stack *tab);
void		ft_free_tab(char **tab);

#endif
