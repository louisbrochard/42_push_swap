# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbrochar <lbrochar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/15 02:15:09 by louisbrocha       #+#    #+#              #
#    Updated: 2023/05/24 15:54:25 by lbrochar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



#SETUP
NAME		=	push_swap
CC			=	gcc
FLAGS		=	-Wall -Wextra -Werror
RM			=	rm -rf

#FILES AND PATH
HEADER_SRCS	=	push_swap.h
HEADER_DIR	=	includes/
HEADER		=	$(addprefix $(HEADER_DIR), $(HEADER_SRCS))

MPATH_SRCS	=	big_sort_A.c \
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
		ft_sort_3_elem.c \
		ft_split.c
MPATH_DIR	=	push/
MPATH		=	$(addprefix $(MPATH_DIR), $(MPATH_SRCS))
OBJ_M		=	$(MPATH:.c=.o)

BPATH_SRCS	=	main.c \
		check_utils.c \
		check.c \
		exit_free.c \
		initialization.c \
		list_del.c \
		move.c \
		op.c \
		utils.c \
		utils2.c \
		utils3.c \
		ft_split.c
BPATH_DIR	=	check/
BPATH		=	$(addprefix $(BPATH_DIR), $(BPATH_SRCS))
OBJ_B		=	$(BPATH:.c=.o)

#FUNC_SRCS	=	ft_strncmp.c ft_strdup.c ft_split.c ft_strjoin.c
#FUNC_DIR	=	functions/
#FUNC 		=	$(addprefix $(FUNC_DIR), $(FUNC_SRCS))\
				gnl/get_next_line_utils.c gnl/get_next_line.c
#OBJ_F		=	$(FUNC:.c=.o)

#COMMANDS
%.o: %.c $(HEADER) Makefile
				@${CC} ${FLAGS} -c $< -o $@

$(NAME):		$(OBJ_M)
				@$(CC) $(OBJ_M) -o $(NAME)
				@echo -e "$(GREEN)$(NAME) created!$(DEFAULT)"

all:			$(NAME)

clean:
				@$(RM) $(OBJ_M)
				@echo -e "$(YELLOW)object files deleted!$(DEFAULT)"

fclean:			clean
				@$(RM) $(NAME)
				@echo -e "$(RED)all deleted!$(DEFAULT)"

re:				fclean all

.PHONY:		all clean fclean re

#COLORS
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
DEFAULT = \033[0m