/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bantario <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 17:48:53 by bantario          #+#    #+#             */
/*   Updated: 2020/01/10 19:17:45 by bantario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdio.h>

int		main(int ac, char **av)
{
	int	a[ac];
	int b[ac];
	int c;
	int i;

	c = 0;
	i = 0;
	if (ac > 1)
	{
		printf("a: %lu\n", sizeof(a));
		printf("b: %lu\n", sizeof(b));
		printf("ac: %d\n", ac);
		printf("av1: %s\n", av[1]);
		while (av[i + 1])
		{
			a[i] = ft_atoi(av[i + 1]);
			i++;
		}
	}
	return (0);
}
