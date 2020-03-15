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


.PHONY: all, $(NAME), clean, fclean, re

NAME1 = push_swap
NAME2 = checker

CC = gcc

FLAGS = -Wall -Werror -Wextra

HEADERS_DIR = ./includes/

HEADERS_LIST =  push_swap.h\
                checker.h\
                struct.h

HEADERS = $(addprefix $(HEADERS_DIR), $(HEADERS_LIS))

SRC_PH = ./ph/src/

SRC_CH = ./check/src/

INCLUDES = ./includes/
OBJ_PATH1 = ./obj/
LFT_PATH = ./libft/
OBJ_PATH2 = ./obj/

SRC_S_PH = $(addprefix $(SRC_PH),$(SRC_NAME_PH))

SRC_S_CH = $(addprefix $(SRC_CH),$(SRC_NAME_CH))

OBJ1 = $(addprefix $(OBJ_PATH1),$(OBJ_NAME1))

OBJ2 = $(addprefix $(OBJ_PATH2),$(OBJ_NAME2))

OBJ_NAME1 = $(SRC_NAME_PH:.c=.o)

OBJ_NAME2 = $(SRC_NAME_CH:.c=.o)

SRC_NAME_PH = push_swap.c\
             sort_five.c\
             ft_atoi_mod.c\
              dop_func.c\
              algo_two.c\
              freesh.c

SRC_NAME_CH = actions.c\
        checker.c\
        ft_atoi_mod.c\
        cr_stack_for_one_arg.c

all: fclean $(NAME1) $(NAME2)

$(NAME1): $(OBJ1)
	@make -C $(LFT_PATH)
	@$(CC) -o push_swap $(OBJ1) -lm -L $(LFT_PATH) -lft

$(NAME2): fclean $(OBJ2)
	@make -C $(LFT_PATH)
	@$(CC) -o $(NAME2) $(OBJ2) -lm -L $(LFT_PATH) -lft

$(OBJ_PATH1)%.o: $(SRC_CH)%.c
	@mkdir -p $(OBJ_PATH1)
	@$(CC) $(FLAGS) $(HEADERS) -o $@ -c $<

$(OBJ_PATH2)%.o: $(SRC_PH)%.c
	@mkdir -p $(OBJ_PATH2)
	@$(CC) $(FLAGS) $(HEADERS) -o $@ -c $<

clean:
	@make -C $(LFT_PATH) clean
	@rm -rf $(OBJ_PATH)

fclean: clean
	@make -C $(LFT_PATH) fclean
	@rm -f $(NAME1)
	@rm -f $(NAME2)

re: fclean all