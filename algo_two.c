/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_two.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bantario <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 15:36:47 by bantario          #+#    #+#             */
/*   Updated: 2020/03/03 20:00:04 by bantario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack		*znac_do_interv(int i, t_stack *a, t_stack *b, int	interv)
{
	int		position;
	t_stack	*start;

	position = 0;
	//start = a;
	while (a != NULL)
	{
		if (a->value <= interv && a->value >= i)
		{
			position = ft_pos(a, a->value);
			if (position <= (coll_list(a) / 2))
				 while (where_one(a, a->value) != 1)
					 a = ra_rb(a);
			else if (position >= (coll_list(a) / 2))
				while (where_one(a, a->value) != 1)
					a = rra_rrb(a);
			a = pb(a, b);
			b = a->pred;
			start = a;
		}
		else if (a->next != NULL)
			a = a->next;
		else
			return (start);
	}
	return (start);
}

t_stack *algo_two(t_stack *a, t_stack *b)
{
	int iter;
	int	n;
	int	i;

	//print_stack(a, "a");
	//print_stack(b, "b");
	n = coll_list(a) / 5;
	iter = n; // 20
	i = 0;
	printf("iter: %d\n", iter);
	while (iter < coll_list(a))
	{
		printf("iter: %d\n", iter);
		a = znac_do_interv(i, a, b, iter);
		b = a->pred;
		iter += n;
		i += n;
	}
	print_stack(a, "a");
	print_stack(b, "b");
	return (a);
}
