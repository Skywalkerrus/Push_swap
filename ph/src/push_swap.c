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

t_stack		*sa(t_stack *a)
{
	t_stack *c;

	if (a->next != NULL)
	{
		c = a;
		a = a->next;
		c->next = a->next;
		a->next = c;
	}
	//ft_putstr("sa\n");
	return (a);
}

t_stack		*sb(t_stack *a)
{
	t_stack *c;

	if (a->next != NULL)
	{
		c = a;
		a = a->next;
		c->next = a->next;
		a->next = c;
	}
	//ft_putstr("sb\n");
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
	//ft_putstr("ss\n");
}

void        print_stack_2(t_stack *a)
{
    char    *del;

    while (a != NULL)
    {
        del = ft_itoa_2(a->value);
        ft_putstr(del);
        free(del);
        ft_putstr(" ");
        a = a->next;
    }
}

void	    print_stack(t_stack *a, char *stack_name)
{
	ft_putstr("stack: ");
	ft_putstr(stack_name);
	ft_putstr("\n");
	if (a->trig == 10)
	{
		ft_putstr("\nstack is empty\n");
		return;
	}
	else if (a->next == NULL)
	{
		ft_putstr("\nstack one el: ");
		ft_putstr(ft_itoa(a->value));
		return;
	}
	print_stack_2(a);
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
	//ft_putstr("pa\n");
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
	//ft_putstr("pb\n");
	return (c);
}

t_stack		*ra(t_stack *a)
{
	t_stack *one;
	t_stack *two;
	t_stack *posl;

	if (a->next == NULL)
		return (a);
	one = a;
	two = a->next;
	posl = a;
	while (posl->next != NULL)
		posl = posl->next;
	posl->next = one;
	one->next = NULL;
	//ft_putstr("ra\n");
	return (two);
}

t_stack		*rb(t_stack *a)
{
	t_stack *one;
	t_stack *two;
	t_stack *posl;

	if (a->next == NULL)
		return (a);
	one = a;
	two = a->next;
	posl = a;
	while (posl->next != NULL)
		posl = posl->next;
	posl->next = one;
	one->next = NULL;
	//ft_putstr("rb\n");
	return (two);
}

t_stack		*ra_rb_rr(t_stack *a)
{
	t_stack *one;
	t_stack *two;
	t_stack *posl;

	if (a->next == NULL)
		return (a);
	one = a;
	two = a->next;
	posl = a;
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
	//ft_putstr("rr\n");
	return (c);
}

t_stack		*rra(t_stack *a)
{
	t_stack	*one;
	t_stack	*posl;
	t_stack	*pred;

	if (a->next == NULL)
		return (a);
	one = a;
	posl = a;
	pred = a;
	while (posl->next != NULL)
		posl = posl->next;
	while (pred->next != posl)
		pred = pred->next;
	posl->next = one;
	pred->next = NULL;
	//ft_putstr("rra\n");
	return (posl);
}

t_stack		*rrb(t_stack *a)
{
	t_stack	*one;
	t_stack	*posl;
	t_stack	*pred;

	if (a->next == NULL)
		return (a);
	one = a;
	posl = a;
	pred = a;
	while (posl->next != NULL)
		posl = posl->next;
	while (pred->next != posl)
		pred = pred->next;
	posl->next = one;
	pred->next = NULL;
	//ft_putstr("rrb\n");
	return (posl);
}

t_stack		*rra_rrb_rrr(t_stack *a)
{
	t_stack	*one;
	t_stack	*posl;
	t_stack	*pred;

	if (a->next == NULL)
		return (a);
	one = a;
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
	//ft_putstr("rrr\n");
	return (c);
}

t_stack		*sort_three_part_two(t_stack *a)
{                                                                       
	if (a->value < a->next->value && a->next->value < a->next->next->value)
		return (a);
	else if (a->value > a->next->value &&
			a->next->value < a->next->next->value)
		a = sa(a);
	else if (a->value > a->next->value 
			&& a->next->value > a->next->next->value)
	{
		a = sa(a);
		a = rra(a);
	}
	else if (a->value > a->next->value 
			&& a->next->value < a->next->next->value)
		a = ra(a);
	else if (a->value < a->next->value 
			&& a->next->value > a->next->next->value)
	{
		a = sa(a);
		a = ra(a);
	}
	else if (a->value < a->next->value 
			&& a->next->value > a->next->next->value)
		a = rra(a);
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

void 		free_three_lists(t_stack *o, t_stack *t, t_stack *th)
{
	free_list(o);
	free_list(t);
	free_list(th);
}

t_stack		*analog_cr_stack_mod(int cunt_w, t_stack *a)
{
	t_stack	*ne;

	ne = NULL;
	if (cunt_w == 0)
	{
		a->next = NULL;
		a->trig = 10;
	} else
	{
		ne = (t_stack *)malloc(sizeof(t_stack));
		ne->trig = 10;
		a->next = ne;
		a = a->next;
		a->next = NULL;
	}
	return (a);
}

int		anal_mod(char	*str, char	*s2, int i)
{
	while (str[i] != ' ' && str[i] != '\t' && str[i])
	{
		if (str[i] != '0' && ft_isdigit(str[i]) == 0)
			return (-1);
		*s2 = str[i];
		s2++;
		i++;
	}
	*s2 = '\0';
	return (i);
}

t_stack		*analog_cr_stack(char	*str, t_stack	*a, int i)
{
	t_stack	*start;
	char	*s2;
	int 	cunt_w;

	cunt_w = ft_ctword(str, ' ') + 1;
	while (str[i])
	{
		if (!start) start = a;
		if (str[i] != ' ' && str[i] != '\t')
		{
			s2 = (char*) malloc(sizeof(char) * 100);
			if ((i = anal_mod(str, s2, i)) == -1)
				return (NULL);
			a->value = ft_atoi(s2);
			free(s2);
			a->trig = 66;
			a = analog_cr_stack_mod(cunt_w--, a);
		} else
			i++;
	}
	return (start);
}

void    free_to_free(t_stack *a)
{
    if (a != NULL)
    {
        free_list(a);
        free(a);
    } else
        return;
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
		if ((ne = (t_stack *)malloc(sizeof(t_stack))) == NULL)
		    return (NULL);
		if (av[i + 2] == NULL) {
			a->next = NULL;
			//free(a);
			free_list(ne);
		}
		else
		{
			a->next = ne;
			a = a->next;
		}
		ne->next = NULL;
		i++;
		if (av[i] == NULL)
			free_to_free(ne);
	}
	av[i] = 0;
	return (start);
}

t_stack		*create_stack(char	**av, int ac) {
    t_stack *a;
    t_stack *ne;
    t_stack *r;
    int i;

    i = 0;
    ne = NULL;
    if ((a = (t_stack *) malloc(sizeof(t_stack))) == NULL)
        return (NULL);
    a->trig = 10;
    if (ac > 2)
        return (cr_stack_n(a, av, ne, i));;
	r = analog_cr_stack(av[1], a, i);
	if (r == NULL)
	{
		ft_putstr("Error\n");
		/*free_list(r);
		//free(r);
		free_list(a);
		//free(a);
		free_list(ne);
		//free(ne);*/
		return (NULL);
	} else {
        return (r);
    }
}

int     mod_econom(char **av)
{
    int i;

    i = 1;
    while (av[i])
    {
        if (check_on_char(av[i]) == 1)
            return (1);
        i++;
    }
    return (0);
}

t_stack     *kostyl_for_two(t_stack *a)
{
    if (a->value > a->next->value)
        a = sa(a);
    return (a);
}

int		main(int ac, char **av)
{
	t_stack     *b;
	t_stack     *start;

	if (ac != 2 && mod_econom(av) == 1)
        return (0);
	if ((b = (t_stack*)malloc(sizeof(t_stack))) == NULL)
	    return (0);
	b->next = NULL;
	b->trig = 10;
	if (ac > 1) {
        if (check_numb_dublic(av) == 1 && ac != 2) {
            free_list(b);
            return (0);
        }
        if ((start = create_stack(av, ac)) == NULL)
        {
            free(start);
            return (0);
        }
		if (ac == 2 && check_n_arg(start) == -1)
		{
			free_list(start);
			free_list(b);
			return (0);
		}
		if (how_list(start) == 2)
		    start = kostyl_for_two(start);
		else if (how_list(start) == 3)
			start = sort_three_numb(start);
		else if (how_list(start) > 70)
		    start = algo_two(start, b);
		else if (how_list(start) < 70 && how_list(start) > 3)
			start = many_sort(start, b);
		print_stack(start, "a");
		free_to_free(start);
	}
	if (ac < 4)
	    free_to_free(b);
	else if (ac > 3)
	    free_list(b);
	return (0);
}