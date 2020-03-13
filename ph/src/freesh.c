/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freesh.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bantario <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 20:45:59 by bantario          #+#    #+#             */
/*   Updated: 2020/03/13 20:46:00 by bantario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	free_list(t_stack *a)
{
	t_stack	*tec;
	t_stack	*nex;

	tec = a;
	if (a->next != NULL)
		a = a->next;
	nex = a;
	while (a->next != NULL)
	{
		free(tec);
		tec = nex;
		if (a->next != NULL)
			a = a->next;
		else
		{
			free(nex);
			return;
		}
		nex = a;
	}
}