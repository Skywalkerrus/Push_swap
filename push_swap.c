/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bantario <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 17:48:53 by bantario          #+#    #+#             */
/*   Updated: 2020/01/28 16:27:16 by bantario         ###   ########.fr       */
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
}

void	ss(t_stack *a, t_stack *b)
{
	sa_sb(a);
	sa_sb(b);
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
		printf("!!!\n");
		b->next = NULL;
		a = b;
		c->pred = a;
	}
	else if (a->value > 0)
	{
		printf("))))\n");
		c->pred = b;
		b->next = a;
	}
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
	return (two);
}

t_stack		*rr(t_stack *a, t_stack *b)
{
	t_stack *c;


	c = ra_rb(a);
	c->pred = ra_rb(b);
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
	return (posl);
}

t_stack		*rrr(t_stack *a, t_stack *b)
{
	t_stack		*c;

	c = rra_rrb(a);
	c->pred = rra_rrb(b);
	return (c);
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

	}
	return (0);
}
