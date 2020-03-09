/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bantario <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 17:40:22 by bantario          #+#    #+#             */
/*   Updated: 2020/03/03 20:00:02 by bantario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include <stdio.h>

int		coll_list(t_stack *c)
{
	t_stack *a;
	int		i;

	a = c;
	i = 0;
	while (a != NULL)
	{
		a = a->next;
		i++;
	}
	return (i);
}

int		ft_pos(t_stack *c, int	min)
{
	int			i;
	t_stack		*a;

	i = 0;
	a = c;
	while (c->value != min)
	{
		c = c->next;
		i++;
	}
	c = a;
	return (i);
}

int		where_one(t_stack *a, int min)
{
	if (a->value == min)
		return (1);
	return (0);
}

int		min_val(t_stack *c)
{
	int			min;
	t_stack		*a;

	a = c;
	min = a->value;
	while (a->next != NULL)
	{
		a = a->next;
		if (min > a->value)
			min = a->value;
	}
	return (min);
}

t_stack		*many_sort(t_stack *a, t_stack *b)
{
	int			min;
	int			position;

	position = 0;
	while (a->trig != 10)
	{ 
		min = min_val(a);
		position = ft_pos(a, min);
		if (position <= (coll_list(a) / 2))
			while (where_one(a, min) != 1)
				a = ra_rb(a);
		else if (position >= (coll_list(a) / 2))
			while (where_one(a, min) != 1)
				a = rra_rrb(a);
		a = pb(a, b);
		b = a->pred;
	}
	while (b->trig != 10)
	{
		b = pa(a, b);
		a = b->pred;
	}
	a->pred = b;
	return (a);
}
