# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bantario <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/10 16:02:54 by bantario          #+#    #+#              #
#    Updated: 2020/03/03 17:57:32 by bantario         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


INCLUDES = -I$(HEADERS_DIRECTORY) -I$(LIBFT_HEADERS) -I$(MINILIBX_HEADERS)

LIBFT = $(LIBFT_DIRECTORY)libft.a
LIBFT_DIRECTORY = ./libft/
LIBFT_HEADERS = $(LIBFT_DIRECTORY)includes/
LIBRARIES = -lft -L $(LIBFT_DIRECTORY)

HEADERS_DIR = ./includes/

HEADERS_LIST =  push_swap.h\
                checker.h\
                struct.h

HEADERS = $(addprefix $(HEADERS_DIR), $(HEADERS_LIS))

SRC_PH = ./ph_sw/src/

SRC_CH = ./check/src/

SRC_PH_LIST = push_swap.c\
        sort_five.c\
        ft_atoi_mod.c\
        dop_func.c\
        algo_two.c

SRC_CH_LIST = actions.c\
        checker.c\
        ft_atoi_mod.c

SRCS_PH = $(addprefix $(SRC_PH), $(SRC_PH_LIST))

SRCS_CH = $(addprefix $(SRC_CH), $(SRC_CH_LIST))

FLAGS = -Wall -Wextra -Werror
CC = gcc
LIBFT_DIR = ./libft/
LIBFT_NAME = libft.a
LIBFT = $(addprefix $(LIBFT_DIR), $(LIBFT_NAME))

SOURCES_DIR = ./sources/

SOURCES_LIST = actions.c \
    ft_atoi_mod.c\
    sort_five.c\
    ft_atoi_mod.c\
    dop_func.c\
    algo_two.c

OBJECTS_DIRECTORY = objects/
OBJECTS_LIST = $(patsubst %.c, %.o, $(SOURCES_LIST))
OBJECTS_LIST_PH = $(patsubst %.c, %.o, $(SOURCES_PH_LIST))
OBJECTS_LIST_CH = $(patsubst %.c, %.o, $(SOURCES_CH_LIST))
OBJECTS	= push_swap.o\
                  sort_five.o\
                  ft_atoi_mod.o\
                  dop_func.o\
                  algo_two.o
OBJECTS_PS = $(addprefix $(OBJECTS_DIRECTORY), $(OBJECTS_LIST_PH))
OBJECTS_CH = $(addprefix $(OBJECTS_DIRECTORY), $(OBJECTS_LIST_CH))

all:
	gcc $(FLAGS) -I $(HEADERS) -c $(SRC_PH_LIST)
	$(CC) $(FLAGS) $(LIBRARIES) $(INCLUDES) $(OBJECTS) -o push_swap
check:
	gcc -Wall -Wextra -Werror -o checker actions.c checker.c ft_atoi_mod.c libft/libft.a)
