/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bantario <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 17:36:45 by bantario          #+#    #+#             */
/*   Updated: 2020/02/06 19:06:18 by bantario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

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
int     how_list(t_stack *a);
