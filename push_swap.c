/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bantario <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 17:48:53 by bantario          #+#    #+#             */
/*   Updated: 2020/01/21 20:02:15 by bantario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

/*void	pa(t_stack *a,	t_stack *b)
{

} */

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
		//printf("stack: %d\n", a->value);
		a = a->next;
	}
	printf("\n\n");
}

t_stack		*pb(t_stack *a, t_stack *b)
{
	t_stack *c;

	c = a->next;
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
			printf("a->VALUE: %D\n", a->value);
			a->num = i;
			if (i == 0)
				start = a;
			ne = (t_stack *)malloc(sizeof(t_stack));
			a->next = ne;
			a = a->next;
			ne->next = NULL;
			i++;
		}	
		av[i] = 0;

		ft_putstr("stack a.\n");
		print_stack(start);

		start = pb(start, b);
		b = start->pred;

		start = pb(start, b);
		b = start->pred;

		printf("b->value: %d\n, b->next->value: %d\n", b->value, b->next->value);
		ft_putstr("stack b.\n");
		print_stack(b);

		ft_putstr("stack a.\n");
		printf("b->value: %d\n, b->next->value: %d\n", start->value, start->next->value);
		print_stack(start);
	}
	return (0);
}
