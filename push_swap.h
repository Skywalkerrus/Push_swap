/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bantario <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 17:36:45 by bantario          #+#    #+#             */
/*   Updated: 2020/03/02 18:48:46 by bantario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdio.h>

typedef	struct	s_stack
{
	int			value;
	int			num;
	struct s_stack	*pred;
	struct s_stack *next;
	struct s_stack *start;
}			t_stack;

t_stack     *many_sort(t_stack *a, t_stack *b);
t_stack     *rra_rrb(t_stack *a);
t_stack     *ra_rb(t_stack *a);
int			how_list(t_stack *a);
t_stack		*pb(t_stack *a, t_stack *b);
t_stack		*pa(t_stack *a, t_stack *b);
void		print_stack(t_stack *a, char *stack_name);
t_stack		*sa_sb(t_stack *a);
t_stack		*ss(t_stack *a, t_stack *b);
t_stack		*rr(t_stack *a, t_stack *b);
t_stack		*rrr(t_stack *a, t_stack *b);
t_stack		*create_stack(char	**av);
t_stack		*cr_stack_n(t_stack *a, char **av, t_stack *ne, int i);
t_stack     *cast_push_first(int    key, t_stack *start, t_stack *b);
t_stack     *cast_push_second(int   key, t_stack *start, t_stack *b);
