/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bantario <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 17:48:53 by bantario          #+#    #+#             */
/*   Updated: 2020/01/22 20:09:53 by bantario         ###   ########.fr       */
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
	if (a->next == NULL)
	{
		printf("stack one el: %d\n", a->value);
		printf("\n");
		return;
	}
	while (a != NULL)
	{
		printf("stack: %d\n", a->value);
		if (a->next == NULL)
			break;
		a = a->next;
	}
	printf("\n");
}

/*t_stack		*pa(t_stack *a, t_stack *b)
{
	
} */

t_stack		*pb(t_stack *a, t_stack *b)
{
	t_stack *c;
	if (a->next != NULL)
		c = a->next;
	else
		c = (t_stack*)malloc(sizeof(t_stack));
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

		start = pb(start, b);
		b = start->pred;

		start = pb(start, b);
		b = start->pred;

		start = pb(start, b);
		b = start->pred; // zdes problema

		ft_putstr("stack b.\n");
		print_stack(b);

		//ft_putstr("stack a.\n");
		//print_stack(start);

	/*	start = pa(start, b);
		b = start->pred;
		
		start = pa(start, b);
		b = start->pred; */
		ft_putstr("stack a.\n");
		print_stack(a);
		ft_putstr("stack b.\n");
		print_stack(b);
	}
	return (0);
}
