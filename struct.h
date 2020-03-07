/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bantario <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 14:53:23 by bantario          #+#    #+#             */
/*   Updated: 2020/03/07 14:53:43 by bantario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef STRUCT_H
# define STRUCT_H
typedef	struct	s_stack
{
    int			value;
    int			num;
    int         trig;
    struct s_stack	*pred;
    struct s_stack *next;
    struct s_stack *start;
}			t_stack;
#endif