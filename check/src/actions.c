/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bantario <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 18:23:04 by bantario          #+#    #+#             */
/*   Updated: 2020/03/03 19:11:21 by bantario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "push_swap.h"
#include "../../includes/checker.h"

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


t_stack		*sa_sb_ss(t_stack *a)
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

t_stack		*ss(t_stack *a, t_stack *b)
{
	t_stack *c;

	c = sa_sb_ss(a);
	c->pred = sa_sb_ss(b);
	return (c);
}

void	print_stack(t_stack *a, char *stack_name)
{
	ft_putstr("stack: ");
	ft_putstr(stack_name);
	ft_putstr("\n");
	if (a->value == '-' || a == NULL)
	{
		ft_putstr("\nstack is empty\n");
		return;
	}
	if (a->value != '-' && a->next == NULL)
	{
		ft_putstr("stack one el: ");
		ft_putstr(ft_itoa(a->value));
		ft_putstr("\n");
		return;
	}
	while (a != NULL && a->value != '-')
	{
		//ft_putstr("stack: ");
		ft_putstr(ft_itoa(a->value));
		ft_putstr(" ");
		a = a->next;
	}
	ft_putstr("\n");
}

t_stack		*pa(t_stack *a, t_stack *b)
{
	t_stack *c;

	if (b->next != NULL)
		c = b->next;
	else
	{
		c = (t_stack*)malloc(sizeof(t_stack));
		c->value = '-';
	}
	if (a->value == '-')
	{
		b->next = NULL;
		a = b;
		c->pred = a;
	}
	else if (a->value != '-')
	{
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
		c->value = '-';
	}
	if (b->value != '-')
	{
		c->pred = a;
		a->next = b;
	}
	else if (b->value == '-')
	{
		a->next = NULL;
		b = a;
		b->value = a->value;
		c->pred = b;
	}
	return (c);
}

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
	while (posl->next != NULL && posl->next->value != '-')
		posl = posl->next;
	posl->next = one;
	one->next = NULL;
	return (two);
}

t_stack		*ra_rb_rr(t_stack *a)
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


	c = ra_rb_rr(a);
	c->pred = ra_rb_rr(b);
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

t_stack		*rra_rrb_rrr(t_stack *a)
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

	c = rra_rrb_rrr(a);
	c->pred = rra_rrb_rrr(b);
	return (c);
}

t_stack		*cr_stack_n(t_stack *a, char	**av, t_stack *ne, int i)
{
	t_stack		*start;

	while (av[i + 1])
	{
		a->value = ft_atoi(av[i + 1]);
		if (i == 0)
			start = a;
		ne = (t_stack *)malloc(sizeof(t_stack));
		//ne->value = '-';
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
	ne->value = '-';
	//printf("NE->value: %d\n", ne->value);
	av[i] = ft_itoa('-');
	return (start);
}

t_stack		*create_stack(char	**av)
{
	t_stack *a;
	t_stack *ne;
	int		i;

	i = 0;
	ne = NULL;
	a = (t_stack*)malloc(sizeof(t_stack));
	a->value = '-';
	return (cr_stack_n(a, av, ne, i));
}
