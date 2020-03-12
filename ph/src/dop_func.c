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

int		check_numb_dublic(char	**av) // proverka na dublicaty
{
    int		i;
    int		j;
    int		tec;

    j = 1;
    i = j + 1;

    while (av[j] != '\0')
    {
        tec = ft_atoi(av[j]);
        while (av[i] != '\0')
        {
            if (tec == ft_atoi(av[i]))
            {
                ft_putstr("Error\n");
                return (1);
            }
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
    }
    return (0);
}