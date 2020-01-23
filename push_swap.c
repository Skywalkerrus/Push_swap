/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bantario <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 17:48:53 by bantario          #+#    #+#             */
/*   Updated: 2020/01/23 17:37:07 by bantario         ###   ########.fr       */
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
	
	c = b->next;
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
		printf("b->value:%d, a->value: %d\n", b->value, a->value);
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
		print_stack(start); // 1 2 3

		start = pb(start, b);
		b = start->pred; // a-> 2 3		b->1

		start = pb(start, b);
		b = start->pred; // a-> 3		b->2 1

		start = pb(start, b);
		b = start->pred; // a -> NULL	b -> 3 2 1

		ft_putstr("stack b.\n");
		print_stack(b); 

		ft_putstr("stack a.\n");
		print_stack(start);

		b = pa(start, b);
		start = start->pred;// a -> 3		b -> 2 1 
		
		ft_putstr("stack a.\n");
		print_stack(start);

		ft_putstr("stack b.\n");
		print_stack(b);

		b = pa(start, b);
		start = start->pred;  // a -> 3 2	b -> 1

		ft_putstr("stack a.\n");
		print_stack(start);
		ft_putstr("stack b.\n");
		print_stack(b);
	}
	return (0);
}
