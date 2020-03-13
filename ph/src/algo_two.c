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

#include "../../includes/push_swap.h"

t_stack     *mod_znac(int   pos, t_stack *start, int a_val)
{
    if (how_list(start) == 1 && a_val == 45)
        return (start);
    else if (pos <= (how_list(start) / 2))
        while (where_one(start, a_val) != 1)
            start = ra(start);
    else if (pos >= (how_list(start) / 2))
        while (where_one(start, a_val) != 1)
            start = rra(start);
    return (start);
}

t_stack		*znac_do_interv(t_stack *a, t_stack *b, int	interv)
{
	int		    position;
	t_stack	    *start;

	start = a;
	while (a != NULL)
	{
		if (a->value <= interv && a->trig != 10)
		{
            position = ft_pos(start, a->value);
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
    while (b->trig != 10)
    {
        max = max_val(b);
        position = ft_pos(for_b, max);
        if (position <= (coll_list(for_b) / 2))
            while (where_one(for_b, max) != 1)
                for_b = rb(for_b);
        else if (position >= (coll_list(for_b) / 2))
            while (where_one(for_b, max) != 1)
                for_b = rrb(for_b);
        b = pa(a, for_b);
        a = b->pred;
        for_b = b;
    }
    return (b);
}

int     na_scoc_delit(t_stack *a)
{
    if (how_list(a) < 100)
        return (how_list(a) / SIX);
    else if (how_list(a) > 100 && how_list(a) < 700)
        return (how_list(a) / DVEN);
    else if (how_list(a) > 700)
        return (how_list(a) / TWEN);
	return (0);
}

t_stack     *algo_two(t_stack *a, t_stack *b)
{
	int iter;
	int	n;
	int	i;

	n = na_scoc_delit(a);
	iter = n;
	i = iter - n;
	while (i <= (n * 5))
	{
		a = znac_do_interv(a, b, iter);
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
