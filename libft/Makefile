# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: louisbrochard <louisbrochard@student.42    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/15 13:31:54 by louisbrocha       #+#    #+#              #
#    Updated: 2023/05/15 14:04:59 by louisbrocha      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= libft.a

## ########################################################################## ##
#   INGREDIENTS																  ##
## ########################################################################## ##
# INCS			header file locations
#
# SRCS_DIR		source directory
# SRCS			source files
#
# BUILD_DIR		build directory
# OBJS			object files
#
# CC			compiler
# CFLAGS		compiler flags
# CPPFLAGS		preprocessor flags
# LDFLAGS		linker flags
# LDLIBS		libraries name

INCS		:= includes

SRCS_DIR	:= srcs
SRCS		:= ft_strlen.c ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
				ft_memset.c ft_strchr.c ft_strjoin.c ft_strlcpy.c ft_strncmp.c ft_tolower.c ft_toupper.c ft_strrchr.c \
				ft_strnstr.c ft_calloc.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
				ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstnew.c ft_lstiter.c ft_lstmap.c \
				ft_strlcat.c ft_memcpy.c ft_memmove.c ft_memchr.c ft_memcmp.c ft_strdup.c ft_substr.c ft_strtrim.c ft_itoa.c \
				ft_lstadd_front.c ft_split.c ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
				ft_lstclear.c ft_lstiter.c ft_lstmap.c \
				ft_printf.c ft_print_char.c ft_print_nbr.c ft_print_str.c ft_print_unsigned.c ft_print_hexa.c ft_print_ptr.c \
				get_next_line.c get_next_line_utils.c
			   
SRCS		:= $(SRCS:%=$(SRCS_DIR)/%)

BUILD_DIR	:= .build
OBJS		:= $(SRCS:$(SRCS_DIR)/%.c=$(BUILD_DIR)/%.o)

CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror	
CPPFLAGS    := $(INCS:%=-I%)

## ########################################################################## ##
#   UTENSILS																  ##
## ########################################################################## ##
# RM			force remove
# MAKEFLAGS		make flags
# DIR_UP		duplicate directory tree

RM          := rm -f
MAKEFLAGS   += --silent --no-print-directory
DIR_DUP     = mkdir -p $(@D)

## ########################################################################## ##
#   RECIPES																	  ##
## ########################################################################## ##
# all			default goal
# $(NAME)		link .o -> archive
# %.o			compilation .c -> .o
# clean			remove .o
# fclean		remove .o + binary
# re			remake default goal

all: $(NAME)

$(BUILD_DIR)/%.o: $(SRCS_DIR)/%.c
	echo "→ Compiling $<"
	$(DIR_DUP)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@ 

$(NAME): $(OBJS)
	@ar -rsc $@ $^
	echo "\033[0;32m✓ $@ READY\033[0m"

clean:
	echo "→ Removing objects"
	$(RM) $(OBJS)

fclean: clean
	echo "→ Removing binaries"
	$(RM) $(NAME)

re: fclean all

.PHONY: re