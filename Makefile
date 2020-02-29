# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bantario <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/10 16:02:54 by bantario          #+#    #+#              #
#    Updated: 2020/02/29 18:24:59 by bantario         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all:
	gcc -Wall -Wextra -Werror -o push_swap push_swap.c sort_five.c libft/libft.a
check:
	gcc -Wall -Wextra -Werror -o checker actions.c checker.c ft_atoi_mod.c libft/libft.a
