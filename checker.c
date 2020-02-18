/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bantario <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 18:20:51 by bantario          #+#    #+#             */
/*   Updated: 2020/02/18 19:20:26 by bantario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "checker.h"
#include "push_swap.h"
#define BUFF 12000

void	cast_spell(char	*spell, )
{
	t_stack *a;
	t_stack *b;
}
int		main(int ac, char **av)
{
	int		i;
	int		*tab;
	int		num;
	char	buff[BUFF];

	num = 0;
	i = 1;
	tab = (int	*)malloc(sizeof(int) * ac);
	if (ac > 1)
	{
		while (i < ac)
		{
			tab[i - 1] = ft_atoi_mod(av[i]);
			if (ft_atoi_mod(av[i]) == '-')
			{
				ft_putstr("Error\n");
				return (0);
			}
			i++;
		}
		i = 0;
		while (read(2, buff, BUFF) != -1)
		{
			printf("buff[i]: %c\n", buff[i]);
			i++;
			if (buff == "sa")
				cast_spell("sa", tab);
			if (buff[i] == '\n')
				i = 0;
			if (buff[i] == 'k')
				break;
		}
	}
	return (0);
}
