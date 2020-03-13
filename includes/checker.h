/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bantario <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 18:42:49 by bantario          #+#    #+#             */
/*   Updated: 2020/02/15 18:55:06 by bantario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
#define CHECKER_H

#include "../libft/libft.h"
#include "struct.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int         ft_atoi_mod(const char *str);
t_stack		*create_stack(char	**av);
t_stack		*cr_stack_n(t_stack *a, char	**av, t_stack *ne, int i);
t_stack		*rrr(t_stack *a, t_stack *b);
t_stack		*rra_rrb_rrr(t_stack *a);
t_stack		*rra_rrb(t_stack *a);
t_stack		*rr(t_stack *a, t_stack *b);
t_stack		*ra_rb_rr(t_stack *a);
t_stack		*ra_rb(t_stack *a);
t_stack		*pb(t_stack *a, t_stack *b);
t_stack		*pa(t_stack *a, t_stack *b);
int         print_stack(t_stack *a, char *stack_name);
t_stack		*ss(t_stack *a, t_stack *b);
t_stack		*sa_sb_ss(t_stack *a);
t_stack		*sa_sb(t_stack *a);
int		    check_numb_dublic(char	**av);
int		    check_on_char_check(char	*av);
#endif