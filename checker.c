/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bantario <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 18:20:51 by bantario          #+#    #+#             */
/*   Updated: 2020/02/29 18:44:31 by bantario         ###   ########.fr       */
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
		return (2);
	else if (ft_strnequ(str, "ss", 3) == 1)
		return (3);
	else if (ft_strnequ(str, "pa", 3) == 1)
		return (8);
	else if (ft_strnequ(str, "pb", 3) == 1)
		return (9);
	else if (ft_strnequ(str, "ra", 3) == 1)
		return (6);
	else if (ft_strnequ(str, "rb", 3) == 1)
		return (4);
	else if (ft_strnequ(str, "rr", 3) == 1)
		return (10);
	else if (ft_strnequ(str, "rra", 4) == 1)
		return (7);
	else if (ft_strnequ(str, "rrb", 4) == 1)
		return (5);
	else if (ft_strnequ(str, "rrr", 4) == 1)
		return (11);
	else
		return (0);
}

t_stack		*cast_push_first(int	key, t_stack *start, t_stack *b)
{
	t_stack	*ret;

	if (key == 1)
		start = sa_sb(start);
	else if (key == 2)
		b = sa_sb(b);
	else if (key == 3)
		ss(start, b);
	else if (key == 4)
		b = ra_rb(b);
	else if (key == 5)
		b = rra_rrb(b);
	else if (key == 6)
		start = ra_rb(start);
	else if (key == 7)
		start = rra_rrb(start);
	ret = start;
	ret->pred = b;
	return (ret);
	
}

t_stack		*cast_push_second(int	key, t_stack *start, t_stack *b)
{
	t_stack *ret;

	if (key == 8)
	{
		b = pa(start, b);
		start = b->pred;
	} else if (key == 9)
	{
		start = pb(start, b);
		b = start->pred;
	} else if (key == 10)
	{
		start = rr(start, b);
		b = start->pred;
	} else if (key == 11)
	{
		start = rrr(start, b);
		b = start->pred;
	}
	ret = start;
	ret->pred = b;
	return (ret);
}

void	cast_de(int		key, char	**av)
{
	t_stack	*b;
	t_stack	*start;

	b = (t_stack*)malloc(sizeof(t_stack));
	b->next = NULL;
	start = create_stack(av);
	if (key < 8 && key > 0)
		start = cast_push_first(key, start, b);
	else if (key > 8 && key < 12)
		start = cast_push_second(key, start, b);
	b = start->pred;
	print_stack(start, "a");
	print_stack(b, "b");
}

int		line(char	*str, char	**av)
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
	} else
		cast_de(equal(str2), av);
	return (0);
}

int		check_numb(int	i, char **av, int	last) // proverka poryadka vorastaniya
{
	if (i > 1 && last > ft_atoi(av[i]))
	{
		ft_putstr("KO\n");
		return (1);
	}
	return (0);
}

int		check_on_char(char	**av, int i) // proverka chisel na bykvi
{
	if (ft_atoi_mod(av[i]) == '!')
	{
		ft_putstr("Error\n");
		return (1);
	}
	return (0);
}

int		main(int ac, char **av)
{
	int		*tab;
	int		m[3];
	char	buff[BUFF];

	m[0] = 0; // num
	m[1] = 1; //i
	if (ac > 1)
	{
		m[2] = ft_atoi(av[1]); //last
		tab = (int  *)malloc(sizeof(int) * ac);
		while (m[1] < ac)
		{
			tab[m[1] - 1] = ft_atoi_mod(av[m[1]]);
			if (/*(check_numb(m[1], av, m[2]) == 1) ||*/ (check_on_char(av, m[1]) == 1))
				return (0);
			m[2] = ft_atoi(av[m[1]]);
			m[1]++;
		}
		while (read(2, buff, BUFF) > 0)
			if (line(buff, av) == 1)
				return (0);
	}
	return (0);
}
