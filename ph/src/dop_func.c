/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dop_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bantario <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 13:16:13 by bantario          #+#    #+#             */
/*   Updated: 2020/03/07 13:16:24 by bantario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

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

int			check_numb_dublic(char	**av) // proverka na dublicaty
{
    int		i;
    int		j;
    int		tec;

    j = 1;
    i = j + 1;

    while (av[j])
    {
        tec = ft_atoi(av[j]);
        while (av[i])
        {
            if (tec == ft_atoi(av[i]))
            {
                ft_putstr("Error\n");
                return (1);
            } else if (tec == 0)
                return (-2);
            i++;
        }
        j++;
        i = j + 1;
    }
    return (0);
}

int		check_on_char(char	*av) // proverka chisel na bykvi
{
    if (ft_atoi_mod(av) == -1)
    {
        ft_putstr("Error\n");
        return (1);
    } else if (ft_atoi_mod(av) == -2)
        return (1);
    return (0);
}