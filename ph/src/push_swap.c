/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bantario <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 15:58:14 by bantario          #+#    #+#             */
/*   Updated: 2020/03/03 19:49:21 by bantario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../includes/push_swap.h"
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
	ft_putstr("sa/sb\n");
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

void	ss_push_swap(t_stack *a, t_stack *b)
{
	sa_sb_ss(a);
	sa_sb_ss(b);
	ft_putstr("ss\n");
}

void	    print_stack(t_stack *a, char *stack_name)
{
	ft_putstr("stack: ");
	ft_putstr(stack_name);
	ft_putstr("\n");
	if (a->trig == 10 /*a->value == '-'*/)
	{
		ft_putstr("\nstack is empty\n");
		return;
	}
	if (a->next == NULL)
	{
		ft_putstr("\nstack one el: ");
		ft_putstr(ft_itoa(a->value));
		return;
	}
	while (a != NULL)
	{
		//ft_putstr("stack: ");
		ft_putstr(ft_itoa(a->value));
		ft_putstr(" ");
		a = a->next;
	}
	ft_putstr("\n");
    return;
}

t_stack		*pa(t_stack *a, t_stack *b)
{
	t_stack *c;

	if (b->next != NULL)
		c = b->next;
	else
	{
		c = (t_stack*)malloc(sizeof(t_stack));
		c->trig = 10;
	}
	if (a->trig == 10)
	{
		b->next = NULL;
		a = b;
		c->pred = a;
	}
	else if (a->trig != 10)
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
		c->trig = 10;
	}
	if (b->trig != 10)
	{
		a->next = b;
		c->pred = a;
	}
	if (b->trig == 10)
	{
		a->next = NULL;
		b = a;
		b->value = a->value;
		c->pred = b;
	}
	ft_putstr("pb\n");
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
	while (posl->next != NULL)
		posl = posl->next;
	posl->next = one;
	one->next = NULL;
	ft_putstr("ra/rb\n");
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

int		how_list(t_stack *c)
{
    t_stack *a;
	int	i;

	a = c;
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

t_stack		*cr_stack_n(t_stack *a, char	**av, t_stack *ne, int i)
{
	t_stack		*start;

	i = 0;
	while (av[i + 1])
	{
		a->value = ft_atoi(av[i + 1]);
		a->trig = 66;
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
	a->trig = 10;
	return (cr_stack_n(a, av, ne, i));
}

int     mod_econom(char **av)
{
    int i;

    i = 1;
    while (av[i] != '\0')
    {
        if (check_on_char(av[i]) == 1)
            return (1);
        i++;
    }
    return (0);
}

t_stack     *kostyl_for_two(t_stack *a)
{
    t_stack     *c;

    c = NULL;
    if (a->value > a->next->value)
        a = sa_sb(a);
    return (a);
}

int		main(int ac, char **av)
{
	t_stack     *b;
	t_stack     *start;

	if (mod_econom(av) == 1)
        return (0);
	b = (t_stack*)malloc(sizeof(t_stack));
	b->next = NULL;
	b->trig = 10;
	if (ac > 1)
	{
        if (check_numb_dublic(av) == 1)
            return (0);
		start = create_stack(av);
		if (how_list(start) == 2)
		    start = kostyl_for_two(start);
		if (how_list(start) == 3)
			start = sort_three_numb(start);
		if (how_list(start) > 3)
		    start = algo_two(start, b);
		print_stack(start, "a");
		//print_stack(b, "b");
	}
	return (0);
}
