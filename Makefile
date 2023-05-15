# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: louisbrochard <louisbrochard@student.42    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/15 02:15:09 by louisbrocha       #+#    #+#              #
#    Updated: 2023/05/15 15:45:43 by louisbrocha      ###   ########.fr        #
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
		op.c


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
		short_sort.c

SRCS_C_DIR = check
SRCS_P_DIR = push
SRCS_C = $(addprefix $(SRCS_C_DIR)/, $(_SRCS_C))
SRCS_P = $(addprefix $(SRCS_P_DIR)/, $(_SRCS_P))
SRCO_C = $(SRCS_C:.c=.o)
SRCO_P = $(SRCS_P:.c=.o)

FLAG = -Wall -Wextra -Werror
INC = -I includes/

all : $(NAME_C) $(NAME_P)

$(NAME_C) : $(SRCO_C)
	make -C libft
	gcc -o $(NAME_C) -Llibft -lft $(SRCO_C)

$(NAME_P) : $(SRCO_P)
	make -C libft
	gcc -o $(NAME_P) -Llibft -lft $(SRCO_P)

%.o : %.c
	gcc $(FLAG) -c $< -o $@ $(INC)

clean :
	/bin/rm -f $(SRCO_C)
	/bin/rm -f $(SRCO_P)
	make clean -C libft

fclean : clean
	/bin/rm -f $(NAME_C)
	/bin/rm -f $(NAME_P)
	/bin/rm -f libft/libft.a

re :
	make fclean
	make