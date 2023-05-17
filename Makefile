# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbrochar <lbrochar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/15 02:15:09 by louisbrocha       #+#    #+#              #
#    Updated: 2023/05/17 16:33:43 by lbrochar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_C = checker
NAME_P = push_swap


_SRCS_C = main.c \
		check_utils.c \
		check.c \
		exit_free.c \
		initialization.c \
		list_del.c \
		move.c \
		op.c \
		utils.c \
		utils2.c \
		utils3.c


_SRCS_P = big_sort_A.c \
		big_sort_B.c \
		check_utils.c \
		check.c \
		exit_free.c \
		initialization.c \
		list_del.c \
		main.c \
		op.c \
		quick_sort.c \
		short_sort.c \
		utils.c \
		ft_sort_3_elem.c

SRCS_C_DIR = check
SRCS_P_DIR = push
SRCS_C = $(addprefix $(SRCS_C_DIR)/, $(_SRCS_C))
SRCS_P = $(addprefix $(SRCS_P_DIR)/, $(_SRCS_P))
SRCO_C = $(SRCS_C:.c=.o)
SRCO_P = $(SRCS_P:.c=.o)

FLAG = -Wall -Wextra -Werror -g
INC = -I includes/

all : $(NAME_C) $(NAME_P)

$(NAME_C) : $(SRCO_C)
	gcc -o $(NAME_C) $(SRCO_C)

$(NAME_P) : $(SRCO_P)
	gcc -o $(NAME_P) $(SRCO_P)

%.o : %.c
	gcc $(FLAG) -c $< -o $@ $(INC)

clean :
	/bin/rm -f $(SRCO_C)
	/bin/rm -f $(SRCO_P)

fclean : clean
	/bin/rm -f $(NAME_C)
	/bin/rm -f $(NAME_P)

re :
	make fclean
	make
