/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bantario <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 17:36:45 by bantario          #+#    #+#             */
/*   Updated: 2020/01/15 20:06:39 by bantario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

typedef	struct	s_stack
{
	int			value;
	int			num;
	struct s_stack	*pred;
	struct s_stack *next;
	struct s_stack *start;
}			t_stack;
