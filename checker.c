/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bantario <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 18:20:51 by bantario          #+#    #+#             */
/*   Updated: 2020/02/22 17:31:57 by bantario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "checker.h"
#include "push_swap.h"
#define BUFF 12000

int		equal(char *str)
{
	if (ft_strnequ(str, "sa", 3) == 1)
		return (1);
	else if (ft_strnequ(str, "sb", 3) == 1)
		return (1);
	else if (ft_strnequ(str, "ss", 3) == 1)
		return (1);
	else if (ft_strnequ(str, "pa", 3) == 1)
		return (1);
	else if (ft_strnequ(str, "pb", 3) == 1)
		return (1);
	else if (ft_strnequ(str, "ra", 3) == 1)
		return (1);
	else if (ft_strnequ(str, "rb", 3) == 1)
		return (1);
	else if (ft_strnequ(str, "rr", 3) == 1)
		return (1);
	else if (ft_strnequ(str, "rra", 4) == 1)
		return (1);
	else if (ft_strnequ(str, "rrb", 4) == 1)
		return (1);
	else if (ft_strnequ(str, "rrr", 4) == 1)
		return (1);
	else
		return (0);
}

int		line(char	*str)
{
	int		i;
	char	*str2;

	i = 0;
	str2 = (char *)malloc(sizeof(char) * ft_strlen(str));
	while (str[i] != '\0' && str[i] != '\n')
	{
		str2[i] = str[i];
		i++;
	}
	if (equal(str2) == 0)
	{
		ft_putstr("Error\n");
		return (1);
	}
	return (0);
}

int		main(int ac, char **av)
{
	int		i;
	int		*tab;
	int		num;
	int		last;
	char	buff[BUFF];

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
			if (ft_atoi_mod(av[i]) == '!')
			{
				ft_putstr("Error\n");
				return (0);
			}
			last = ft_atoi(av[i]);
			i++;
		}
		while (read(2, buff, BUFF) > 0)
			if (line(buff) == 1)
				return (0);
	}
	return (0);
}
