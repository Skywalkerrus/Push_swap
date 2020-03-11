/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bantario <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 18:20:51 by bantario          #+#    #+#             */
/*   Updated: 2020/03/03 18:44:48 by bantario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../../includes/checker.h"
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

t_stack		*cast_push_first(int	key, t_stack *a, t_stack *b)
{
    t_stack *r;

    r = NULL;
	if (key == 1)
	    r = sa_sb(a);
	else if (key == 2)
	    r->pred = sa_sb(b);
	else if (key == 3)
	    return(ss(a, b));
	else if (key == 4)
		r->pred = rra_rrb(b);
	else if (key == 5)
	    r->pred = rra_rrb(b);//return (rra_rrb(b));
    else if (key == 6)
        r = ra_rb(a);
	else if (key == 7)
	    r = rra_rrb(a);
	return (r);
}

t_stack		*cast_push_second(int	key, t_stack *a, t_stack *b)
{
	t_stack *ret;

	if (key == 8)
	{
		b = pa(a, b);
		a = b->pred;
	} else if (key == 9)
	{
		a = pb(a, b);
		b = a->pred;
	} else if (key == 10)
	{
		a = rr(a, b);
		b = a->pred;
	} else if (key == 11)
	{
		a = rrr(a, b);
		b = a->pred;
	}
	ret = a;
	ret->pred = b;
	return (ret);
}

t_stack     *cast_de(int    key, t_stack *a, t_stack *b, t_stack *s)
{
    a = s;
	if (key < 8 && key > 0)
    {
	    a = cast_push_first(key, a, b);
        b = a->pred;
	}
	else if (key > 8 && key < 12)
	{
		a = cast_push_second(key, a, b);
		b = a->pred;
	}
	print_stack(a, "a");
    return (a);
}

t_stack     *chtec2(char    **av)
{
    t_stack *a;
    t_stack *b;

    b = (t_stack*)malloc(sizeof(t_stack));
    b->trig = 10;
    b->next = NULL;
    a = create_stack(av);
    a->pred = b;
    return (a);
}

t_stack 	*line(char	*str, t_stack *a, t_stack *b, t_stack *s)
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
		s = NULL;
		return (s);
	} else
    {
        a = cast_de(equal(str2) , a, b, s);
        b = a->pred;
    }
	return (a);
}

int		check_numb(int	i, char **av, int	last) // proverka poryadka vozrastaniya
{
	if (i > 1 && last > ft_atoi(av[i]))
	{
		ft_putstr("KO\n");
		return (1);
	}
	return (0);
}

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

int		check_on_char_check(char	*av) // proverka chisel na bykvi
{
    if (ft_atoi_mod(av) == 0 || ft_atoi_mod(av) == -1)
	{
		ft_putstr("Error\n");
		return (1);
	}
	return (0);
}

int     chtec(t_stack *a, t_stack *b, t_stack *s)
{
    char	buff[BUFF];

    while (read(2, buff, BUFF) > 0)
    {
        s = line(buff, a, b, s);
        b = a->pred;
        if (s == NULL)
            return (1);
    }
    return (0);
}

int		main(int ac, char **av)
{
	int		*tab;
	int		m[3];
	t_stack *a;
	t_stack *s;

	m[0] = 0;
	m[1] = 1;
	if (ac > 1)
	{
		m[2] = ft_atoi(av[1]); //last
		tab = (int  *)malloc(sizeof(int) * ac);
		while (m[1] < ac)
		{
			tab[m[1] - 1] = ft_atoi_mod(av[m[1]]);
			if ((check_on_char_check(av[m[1]]) == 1) || check_numb_dublic(av) == 1)
				return (0);
			m[2] = ft_atoi(av[m[1]]);
			m[1]++;
		}
		a = chtec2(av);
		s = a;
		if (chtec(a, a->pred, s) == 1)
            return (0);
	}
	return (0);
}
