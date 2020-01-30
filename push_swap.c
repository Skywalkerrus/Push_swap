/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bantario <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 17:48:53 by bantario          #+#    #+#             */
/*   Updated: 2020/01/30 18:55:30 by bantario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

t_stack		*sa_sb(t_stack *a)
{
	t_stack *c;

	if (a->next != NULL)
	{
		c = a;
		a = a->next;
		c->next = a->next;
		a->next = c;
	}
	return (a);
	ft_putstr("sa/sb\n");
}

void	ss(t_stack *a, t_stack *b)
{
	sa_sb(a);
	sa_sb(b);
	ft_putstr("ss\n");
}

void	print_stack(t_stack *a)
{
	if (a->value == -1)
	{
		ft_putstr("stack is empty\n");
		return;
	}
	if (a->next == NULL)
	{
		printf("stack one el: %d\n", a->value);
		printf("\n");
		return;
	}
	while (a != NULL)
	{
		printf("stack: %d\n", a->value);
		a = a->next;
	}
	printf("\n");
}

t_stack		*pa(t_stack *a, t_stack *b)
{
	t_stack *c;

	if (b->next != NULL)
		c = b->next;
	else
	{
		c = (t_stack*)malloc(sizeof(t_stack));
		c->value = -1;
	}
	if (a->value == -1)
	{
		b->next = NULL;
		a = b;
		c->pred = a;
	}
	else if (a->value > 0)
	{
		c->pred = b;
		b->next = a;
	}
	ft_putstr("pa\n");
	return (c);
}

t_stack		*pb(t_stack *a, t_stack *b)
{
	t_stack *c;

	if (a->next != NULL)
		c = a->next;
	else
	{
		c = (t_stack*)malloc(sizeof(t_stack));
		c->value = -1;
	}
	if (b->value > 0)
	{
		a->next = b;
		c->pred = a;
	}
	if (b->value == 0)
	{
		a->next = NULL;
		b = a;
		b->value = a->value;
		c->pred = b;
	}
	ft_putstr("pb\n");
	return (c);
}
// 1 2 3 4 5 -> 2 3 4 5 1
t_stack		*ra_rb(t_stack *a)
{
	t_stack *one;
	t_stack *two;
	t_stack *posl;
	t_stack *pred;

	if (a->next == NULL)
		return (a);
	one = a;
	two = a->next;
	posl = a;
	pred = a;
	while (posl->next != NULL)
		posl = posl->next;
	posl->next = one;
	one->next = NULL;
	ft_putstr("ra/rb\n");
	return (two);
}

t_stack		*rr(t_stack *a, t_stack *b)
{
	t_stack *c;


	c = ra_rb(a);
	c->pred = ra_rb(b);
	ft_putstr("rr\n");
	return (c);
}

t_stack		*rra_rrb(t_stack *a)
{
	t_stack	*one;
	t_stack	*two;
	t_stack	*posl;
	t_stack	*pred;

	if (a->next == NULL)
		return (a);
	one = a;
	two = a->next;
	posl = a;
	pred = a;
	while (posl->next != NULL)
		posl = posl->next;
	while (pred->next != posl)
		pred = pred->next;
	posl->next = one;
	pred->next = NULL;
	ft_putstr("rra/rrb\n");
	return (posl);
}

t_stack		*rrr(t_stack *a, t_stack *b)
{
	t_stack		*c;

	c = rra_rrb(a);
	c->pred = rra_rrb(b);
	ft_putstr("rrr\n");
	return (c);
}

t_stack		*sort_three_part_two(t_stack *a)
{                                                                       
	if (a->value < a->next->value && a->next->value < a->next->next->value)
		return (a);
	else if (a->value > a->next->value &&
			a->next->value < a->next->next->value)
		a = sa_sb(a);
	else if (a->value > a->next->value 
			&& a->next->value > a->next->next->value)
	{
		a = sa_sb(a);
		a = rra_rrb(a);
	}
	else if (a->value > a->next->value 
			&& a->next->value < a->next->next->value)
		a = ra_rb(a);
	else if (a->value < a->next->value 
			&& a->next->value > a->next->next->value)
	{
		a = sa_sb(a);
		a = ra_rb(a);
	}
	else if (a->value < a->next->value 
			&& a->next->value > a->next->next->value)
		a = rra_rrb(a);
	return (a);
}

int		how_list(t_stack *a)
{
	int	i;

	i = 0;
	while (a != NULL)
	{
		i++;
		a = a->next;
	}
	return (i);
}

t_stack		*sort_three_numb(t_stack *a)
{
	int	i;

	i = 0;
	while (i < 2)
	{
		a = sort_three_part_two(a);
		i++;
	}
	return (a);
}

t_stack		*sort_five_numb(t_stack *start, t_stack *b)
{
	start = pb(start, b);
	b = start->pred;
	start = pb(start, b);
	b = start->pred;
	start = sort_three_numb(start);
	b = pa(start, b);
	start = b->pred;
	b = pa(start, b);
	start = b->pred;
	start = sort_three_numb(start);
	return (start);
}

int		main(int ac, char **av)
{
	int c;
	int i;
	t_stack *a;
	t_stack *ne;
	t_stack *b;
	t_stack *start;

	a = (t_stack*)malloc(sizeof(t_stack));
	b = (t_stack*)malloc(sizeof(t_stack));
	b->next = NULL;
	i = 0;
	c = 0;
	if (ac > 1)
	{
		while (av[i + 1])
		{
			a->value = ft_atoi(av[i + 1]);
			a->num = i;
			if (i == 0)
				start = a;
			ne = (t_stack *)malloc(sizeof(t_stack));
			if (av[i + 2] == NULL)
				a->next = NULL;
			else 
			{
				a->next = ne;
				a = a->next;
			}
			ne->next = NULL;
			i++;
			if (av[i] == NULL)
				free(ne);
		}	
		av[i] = 0;
		ft_putstr("stack a.\n");
		print_stack(start);
		ft_putstr("stack b\n");
		print_stack(b);
		if (how_list(start) == 3)
			start = sort_three_numb(start);
		else if (how_list(start) == 5)
			start = sort_five_numb(start, b);
		ft_putstr("stack a\n");
		print_stack(start);

	}
	return (0);
}
