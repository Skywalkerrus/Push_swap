/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bantario <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 17:48:53 by bantario          #+#    #+#             */
/*   Updated: 2020/01/15 20:10:08 by bantario         ###   ########.fr       */
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
		a->num++;
	}
}

void	sa_sb(t_stack *a, int i)
{
	t_stack *c;
	t_stack *save;

	if (i > 1)
	{
		c = a;
		a = a->next;
		c->next = a->next;
		c->pred = a;
		a->pred = NULL;
		a->next->pred = c;
		a->next = c;
	}
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

/*int		len_b(int *b)
{
	int i;

	i = 0;
	while (*b)
		i++;
	return (i);
}*/

int		main(int ac, char **av)
{
	//int	*a;
	//int *b;
	int c;
	int i;
	t_stack *a;
	t_stack *pred;
	t_stack *b;
	t_stack *start;

	a = (t_stack*)malloc(sizeof(t_stack));
	b = (t_stack*)malloc(sizeof(t_stack));
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
			pred = a;
			a = (t_stack *)malloc(sizeof(t_stack));
			pred->next = a;
			a->pred = pred;
			i++;
		}
		av[i] = 0;
	}
	print_stack(start);
	//sa_sb(start, ac);
	pa(b, start);
	pa(b, start);
	//b = b->pred;
	//print_stack(b);
	//start = start->pred; // нужно делать после sa/sb
	//print_stack(start);
	print_stack(b);	
	return (0);
}
