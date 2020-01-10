/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bantario <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 16:32:39 by bantario          #+#    #+#             */
/*   Updated: 2019/11/15 16:34:28 by bantario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putnbr_3(long int n)
{
	long long int nbr;

	nbr = 0;
	if (n < 0)
	{
		//ft_putchar('-');
		nbr = n * -1;
	}
	else
		nbr = n;
	if (nbr >= 10)
		ft_putnbr_3(nbr / 10);
	//ft_putchar(nbr % 10 + 48);
	nbr = nbr % 10 + 48;
	return (nbr);
}
