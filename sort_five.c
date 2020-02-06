/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bantario <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 17:40:22 by bantario          #+#    #+#             */
/*   Updated: 2020/02/06 19:06:15 by bantario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
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

t_stack		*many_sort(t_stack *a, t_stack *b)
{
	t_stack		*c;
	t_stack		*g;
	int			min;
	int			i;

	c = a;
	g = a;
	i = 0;
	min = c->value;
	while (c->next != NULL)
	{
		c = c->next;
		if (min > c->value)
			min = c->value;
	}
	printf("min: %d\n", min);
	while (g->value != min)
	{
		g = g->next;
		i++;
	}
	printf("i: %d\n", i);
	min = coll_list(a) - i;
	printf("PLOLZ:%d\n", min);
	if (i <= (coll_list(a) / 2))
		while (min--)
			a = ra_rb(a);
	else if (i >= (coll_list(a) / 2))
		while (min--)
			a = rra_rrb(a);
	b = NULL;
	return (a);
}
