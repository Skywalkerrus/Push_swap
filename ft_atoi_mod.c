/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_mod.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bantario <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 18:27:51 by bantario          #+#    #+#             */
/*   Updated: 2020/02/18 17:23:11 by bantario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

/*static int	ft_isblankss(char c)
{
	if (c == ' ' || c == '\f' || c == '\n'
			|| c == '\v' || c == '\t'
			|| c == '\r')
		return (1);
	return (0);
} */

static int	ft_sign(int y)
{
	if (y < 0)
		return (0);
	return (-1);
}

int			ft_atoi_mod(const char *str)
{
	int			sign;
	long int	result;
	long int	check;
	int			i;

	result = 0;
	sign = 1;
	check = 0;
	i = 0;
	if (str[0] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]) == 0)
			return ('-');
		check = result;
		result = str[i] + result * 10 - '0';
		if (result / 10 != check)
			return (ft_sign(sign));
		i++;
	}
	return (result * sign);
}
