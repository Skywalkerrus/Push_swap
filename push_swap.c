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

/*void	pa(int *a, int *b, int i)
{
	if (a[0] != NULL)
	{
		 
	}
}

void	sa_sb(int *a, int i)
{
	int c;

	if (i > 1)
	{
		c = a[0];
		a[0] = a[1];
		a[1] = c;
	}
}

void	ss(int *a, int *b, int i, int c)
{
	sa_sb(a, i);
	sa_sb(b, c);
}
*/
void	print_stack(t_stack *a)
{
	while (a->pred != NULL)
	{
		printf("*a = %d\n", a->value);
		a = a->pred;
	}
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

	a = (t_stack*)malloc(sizeof(t_stack));
	b = (t_stack*)malloc(sizeof(t_stack));
	i = 0;
	c = 0;
	if (ac > 1)
	{
		while (av[i + 1])
		{
			a->value = ft_atoi(av[i + 1]);
			printf("a:val: %d\n", a->value);
			a->num = i;
			pred = a;
			a = (t_stack *)malloc(sizeof(t_stack));
			a->pred = pred;
			i++;
		}
		av[i] = 0;
	}
	//sa_sb(a, ac);
	//c = len_b(b);
	print_stack(a);	
	return (0);
}
