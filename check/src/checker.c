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
		return (3);
	else if (ft_strnequ(str, "ss", 3) == 1)
		return (2);
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
	else if (ft_strnequ(str, "", 1) == 1)
		return (95);
	else
		return (0);
}

int     equal_sec(char  *str)
{
    if (ft_strnequ(str, "", 1) == 1)
        return (95);
    return (0);
}

t_stack     *cast_push_b(int	key, t_stack *a, t_stack *b)
{
    t_stack *r;

    r = a;
    if (key == 3)
        r->pred = sa_sb(b);
    else if (key == 4)
        r->pred = ra_rb(b);
    else if (key == 5)
        r->pred = rra_rrb(b);
    return (r);
}

t_stack		*cast_push_first(int	key, t_stack *a, t_stack *b)
{
    t_stack *r;

    r = a;
	if (key == 1)
	    r = sa_sb(a);
	else if (key == 2)
	    return(ss(a, b));
	else if (key == 6)
        r = ra_rb(a);
	else if (key == 7)
	    r = rra_rrb(a);
	r->pred = b;
	return (r);
}

t_stack     *helper_pb(t_stack *a, t_stack *b)
{
    if (a->trig != 10)
        return (pb(a, b));
    else{
        a->pred = b;
        return (a);
    }
}

t_stack		*cast_push_second(int	key, t_stack *a, t_stack *b)
{
	t_stack *r;
	t_stack *z;

	r = a;
	z = NULL;
	if (key == 8)
	{
	    if (b->trig != 10)
	    {
		    r = pa(a, b);
		    z = r; //b
		    r = r->pred; //a
	    }else
	        z = b;
	    r->pred = z;
	} else if (key == 9)
        r = helper_pb(a, b);//pb(a, b);
	else if (key == 10)
		r = rr(a, b);
	else if (key == 11)
		r = rrr(a, b);
	return (r);
}

t_stack     *cast_de(int    key, t_stack *a, t_stack *b, t_stack *s)
{
    a = s;
    b = s->pred;
	if ((key <= 2 && key > 0) || (key > 5 && key < 8))
	    a = cast_push_first(key, a, b);
	else if (key >= 8 && key < 12)
        a = cast_push_second(key, a, b);
	else if (key > 2 && key < 6)
	    a = cast_push_b(key, a, b);
    return (a);
}

void     check_numb_two(t_stack *a)
{
    t_stack	*s;
    t_stack	*s2;

    s = a;
    if (s->next != NULL)
    	s2 = s->next;
    while (s->trig != 10)
	{
    	while (s2->trig != 10)
		{
    		if (s->value > s2->value)
			{
				ft_putstr("KO\n");
				return;
			}
    		if (s2->next != NULL)
    			s2 = s2->next;
		}
		if (s->next != NULL)
			s = s->next;
		if (s->next != NULL)
			s2 = s->next;
	}
    ft_putstr("OK\n");
}

t_stack 	*line(char	*str, t_stack *a, t_stack *b, t_stack *s)
{
	int		i;
	char	*str2;

	i = 0;
	str2 = (char *)malloc(sizeof(char) * ft_strlen(str));
	while (str[i] && str[i] != '\n')
	{
		str2[i] = str[i];
		i++;
	}
	/*if (equal_sec(str2) == 95)
	{
		check_numb_two(a);
		return (NULL);
	}*/
	if (equal(str2) == 0)
	{
		ft_putstr("Error\n");
		s = NULL;
		return (s);
	}
	else if (equal(str2) == 95) {
		print_stack(a, "hui na");
		check_numb_two(a);
		return (NULL);
	}
	else {
	    int test_jopi = equal(str2);
        a = cast_de(test_jopi/*equal(str2)*/, a, b, s);
    }
	print_stack(a, "a");
	print_stack(a->pred, "b");
	return (a);
}

int		check_numb_dublic(char	**av) // proverka na dublicaty
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
    if (ft_atoi_mod(av) == -1)
	{
		ft_putstr("Error\n");
		return (1);
	}
	return (0);
}

t_stack     *chtec2(char    **av, int ac)
{
    t_stack *a;
    t_stack *b;

    b = (t_stack*)malloc(sizeof(t_stack));
    b->trig = 10;
    b->next = NULL;
    a = create_stack(av, ac);
    a->trig = 0;
    if (a)
    	a->pred = b;
    return (a);
}

int     chtec(t_stack *a, t_stack *b, t_stack *s)
{
    char	buff[BUFF];
    t_stack *k;

    k = NULL;
    while (read(0, buff, BUFF) > 0)
    {
        s = line(buff, a, b, s);
        k = s;
        if (s != NULL)
            b = k->pred;
        if (s == NULL)
            return (1);
    }
    return (0);
}

int     blyat(char     **av, int ac)
{
    t_stack *a;
    t_stack *s;
    t_stack *b;

    if ((a = chtec2(av, ac)) == NULL)
		return (1);
	if (ac == 2 && check_n_arg(a) == -1)
	{
		//free_list(a);
		return (1);
	}
    b = a->pred;
    s = a;
    if (chtec(a, b, s) == 1) {
        //free_list
        return (1);
    }
    return (0);
}

int		main(int ac, char **av)
{
	int		*tab;
	int		m[3];

	m[0] = 0;
	m[1] = 1;
	if (ac > 1) {
        if (ac == 2)
            if (blyat(av, ac) == 1)
                return (0);
        m[2] = ft_atoi(av[1]); //last
        tab = (int *) malloc(sizeof(int) * ac);
        while (m[1] < ac) {
            tab[m[1] - 1] = ft_atoi_mod(av[m[1]]);
            if ((check_on_char_check(av[m[1]]) == 1) || (check_numb_dublic(av) == 1))
                return (0);
            m[2] = ft_atoi(av[m[1]]);
            m[1]++;
        }
        if (blyat(av, ac) == 1)
            return (0);
    }
	return (0);
}
