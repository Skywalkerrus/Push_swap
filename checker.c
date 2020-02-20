/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bantario <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 18:20:51 by bantario          #+#    #+#             */
/*   Updated: 2020/02/20 18:14:14 by bantario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "checker.h"
#include "push_swap.h"
#define BUFF 12000

/*void	cast_spell(char	*s)
{
	int		i;
	int		trig;

	i = 0;
	trig = 0;
	s = NULL;
	
} */

int		main(int ac, char **av)
{
	int		i;
	int		*tab;
	int		num;
	//char	buff[BUFF];
	int		last;

	num = 0;
	i = 1;
	if (ac > 1)
	{
		last = ft_atoi(av[1]);
		tab = (int  *)malloc(sizeof(int) * ac);
		while (i < ac)
		{
			if (i > 1 && last > ft_atoi(av[i]))
			{
				ft_putstr("KO\n");
				return (0);
			}
			tab[i - 1] = ft_atoi_mod(av[i]);
			if (ft_atoi_mod(av[i]) == '-')
			{
				ft_putstr("Error\n");
				return (0);
			}
			last = ft_atoi(av[i]);
			i++;
		}
		/*while (read(2, buff, BUFF) > 0) */
	}
	return (0);
}
