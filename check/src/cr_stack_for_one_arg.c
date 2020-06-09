/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cr_stack_for_one_arg.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bantario <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 20:05:50 by bantario          #+#    #+#             */
/*   Updated: 2020/03/15 20:05:52 by bantario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

int 		check_n_arg(t_stack	*start)
{
	t_stack	*a;
	t_stack *b;

	a = start;
	if (a->next != NULL)
		b = a->next;
	while (a->trig != 10)
	{
		while (b->trig != 10)
		{
			if (a->value == b->value)
			{
				ft_putstr("Error\n");
				return (-1);
			}
			b = b->next;
		}
		if (a->next != NULL)
			a = a->next;
		if (a->next != NULL)
			b = a->next;
	}
	return (0);
}

t_stack		*analog_cr_stack_mod(int cunt_w, t_stack *a)
{
	t_stack	*ne;

	ne = NULL;
	//printf("cunt_w: %d\n", cunt_w);
	if (cunt_w == 2)
	{
		a->next = NULL;
		a->trig = 10;
	} else
	{
	        ne = (t_stack *) malloc(sizeof(t_stack));
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
		if (!start)
		    start = a;
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