/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_two.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bantario <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 15:36:47 by bantario          #+#    #+#             */
/*   Updated: 2020/03/03 20:00:04 by bantario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack     *mod_znac(int   pos, t_stack *start, int a_val)
{
    if (pos <= (how_list(start) / 2))
        while (where_one(start, a_val) != 1)
            start = ra_rb(start);
    else if (pos >= (how_list(start) / 2))
        while (where_one(start, a_val) != 1)
            start = rra_rrb(start);
    return (start);
}

t_stack		*znac_do_interv(int i, t_stack *a, t_stack *b, int	interv)
{
	int		    position;
	t_stack	    *start;

	start = a;
	while (a != NULL)
	{
		if (a->value <= interv && a->value >= i)
		{
			position = ft_pos(start, a->value);
			if (a->value == '-')
			    break;
			start = mod_znac(position, start, a->value);
			a = pb(start, b);
			b = a->pred;
			start = a;
		}
		else if (a->next != NULL)
			a = a->next;
		else
		    return (start);
	}
	return (start);
}

int		max_val(t_stack *c)
{
    int			max;
    t_stack		*a;

    a = c;
    max = a->value;
    while (a->next != NULL)
    {
        a = a->next;
        if (max < a->value)
            max = a->value;
    }
    return (max);
}

t_stack     *step_two(t_stack *a, t_stack *b)
{
    int			max;
    int			position;
    t_stack     *for_b;

    for_b = b;
    while (b->value != '-')
    {
        max = max_val(b);
        position = ft_pos(for_b, max);
        if (position <= (coll_list(for_b) / 2))
            while (where_one(for_b, max) != 1)
                for_b = ra_rb(for_b);
        else if (position >= (coll_list(for_b) / 2))
            while (where_one(for_b, max) != 1)
                for_b = rra_rrb(for_b);
        b = pa(a, for_b);
        a = b->pred;
        for_b = b;
    }
    return (b);
}

t_stack     *algo_two(t_stack *a, t_stack *b)
{
	int iter;
	int	n;
	int	i;

	n = how_list(a) / 5;
	iter = n;
	i = 0;
	while (i <= (n * 5))
	{
		a = znac_do_interv(i, a, b, iter);
		b = a->pred;
        iter += n;
		i += 1;
	}
	while (iter > 0)
	{
	    b = step_two(a, b);
	    a = b->pred;
	    iter--;
    }
	return (a);
}
