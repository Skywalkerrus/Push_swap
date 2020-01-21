/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bantario <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 17:48:53 by bantario          #+#    #+#             */
/*   Updated: 2020/01/21 17:24:42 by bantario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	pa(t_stack *a,	t_stack *b)
{
	t_stack 	*new_elem;

	if (a->num > 0)
	{
		new_elem = (t_stack *)malloc(sizeof(t_stack));
		a->num++;
		a->pred = new_elem;
		new_elem->pred = NULL;
		new_elem->next = a;
		new_elem->value = b->value;
	}
	else if (a->num == 0)
	{
		a->value = b->value;
		a->pred = NULL;
		a->next = NULL;
		a->num++;
	}
}

t_stack		*sa_sb(t_stack *a, int i)
{
	t_stack *c;

	if (i > 1)
	{
		c = a;
		a = a->next;
		c->next = a->next;
		a->next = c;
	}
	return (a);
}

/*void	ss(int *a, int *b, int i, int c)
{
	sa_sb(a, i);
	sa_sb(b, c);
}
*/

void	print_stack(t_stack *a)
{
	if (a->next == NULL)
	{
		printf("stack one el: %d\n", a->value);
		printf("\n");
		return;
	}
	while (a->next != NULL)
	{
		printf("stack: %d\n", a->value);
		a = a->next;
	}
	printf("\n");
}

void	pb(t_stack *a, t_stack *b)
{
	if (b->value > 0)
	{
		printf("piska\n");
		//while (b->pred != NULL)
		//	b = b->pred;
		//a->next->pred = NULL;
		a->next = b;
		b->pred = a;
		b->pred->value = a->value;
		b = b->pred;
	}
	if (b->value == 0)
	{
		printf("jopka\n");
		a->next->pred = NULL;
		a->next = NULL;
		b->value = a->value;
	}
}

int		main(int ac, char **av)
{
	//int	*a;
	//int *b;
	int c;
	int i;
	t_stack *a;
	//t_stack *pred;
	t_stack *ne;
	t_stack *b;
	t_stack *start;

	a = (t_stack*)malloc(sizeof(t_stack));
	b = (t_stack*)malloc(sizeof(t_stack));
	b->next = NULL;
	b->pred = NULL;
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
			a->next = ne;
			a = a->next;
			ne->next = NULL;
			i++;
		}
		
		av[i] = 0;
		ft_putstr("stack a.\n");
		print_stack(start);
		/*pb(start, b);
		print_stack(b);
		print_stack(start->next);
		pb(start, b);
		ft_putstr("stack b\n");
		print_stack(b);
		print_stack(start); */
		start = sa_sb(start, ac);
		//start = start->pred; // нужно делать после sa/sb
		//print_stack(start);
		print_stack(start);	
	}
	return (0);
}
