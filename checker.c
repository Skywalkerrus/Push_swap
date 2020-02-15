/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bantario <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 18:20:51 by bantario          #+#    #+#             */
/*   Updated: 2020/02/15 19:24:52 by bantario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "checker.h"

int		main(int ac, char **av)
{
	int	i;
	int	*tab;
	
	i = 1;
	tab = (int	*)malloc(sizeof(int) * ac);
	if (ac > 1)
	{
		while (i < ac)
		{
			tab[i - 1] = ft_atoi_mod(av[i]);
			if (ft_atoi_mod(av[i]) == '\0')
			{
				ft_putstr("Error\n");
				return (0);
			}
			i++;
		}
	}
	return (0);
}
