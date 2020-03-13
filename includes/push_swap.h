/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bantario <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 17:36:45 by bantario          #+#    #+#             */
/*   Updated: 2020/03/03 17:58:36 by bantario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "../libft/libft.h"
#include <stdio.h>
#include "struct.h"

#define FIVE 5
#define SIX 6
#define DVEN 12
#define TWEN 20

t_stack     *many_sort(t_stack *a, t_stack *b);
t_stack     *rra(t_stack *a);
t_stack     *rrb(t_stack *a);
t_stack     *ra(t_stack *a);
t_stack     *rb(t_stack *a);
int			how_list(t_stack *a);
t_stack		*pb(t_stack *a, t_stack *b);
t_stack		*pa(t_stack *a, t_stack *b);
void	    print_stack(t_stack *a, char *stack_name);
t_stack		*sa(t_stack *a);
t_stack		*sb(t_stack *a);
t_stack		*ss(t_stack *a, t_stack *b);
t_stack		*rr(t_stack *a, t_stack *b);
t_stack		*rrr(t_stack *a, t_stack *b);
t_stack		*create_stack(char	**av);
t_stack		*cr_stack_n(t_stack *a, char **av, t_stack *ne, int i);
t_stack     *cast_push_first(int    key, t_stack *start, t_stack *b);
t_stack     *cast_push_second(int   key, t_stack *start, t_stack *b);
int			coll_list(t_stack *a);
void		ss_push_swap(t_stack *a, t_stack *b);
t_stack		*algo_two(t_stack *a, t_stack *b);
int			ft_pos(t_stack *c, int	min);
int			where_one(t_stack *a, int min);
int         check_numb_dublic(char	**av);
int		    check_on_char(char	*av);
int         ft_atoi_mod(const char *str);
void		free_list(t_stack *a);
#endif