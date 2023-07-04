CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
AR = ar cr
NAME= libft.a
SOURCES = big_sort_A.c \
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
BONUS = main.c \
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

BDIR = check/
SDIR = push/
BPATH		=	$(addprefix $(BDIR), $(BONUS))
SPATH		=	$(addprefix $(SDIR), $(SOURCES))

OBJECTS = $(SPATH:.c=.o)
BONUS_OBJ = $(BPATH:.c=.o)
#build everything
all: $(NAME)

bonus: $(BONUS_OBJ)
	$(CC) $(CFLAGS) $(BONUS_OBJ) -o CHECKER


#creates a static library
$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o push_swap

#removes all *.o files
clean:
	$(RM) $(OBJECTS) $(BONUS_OBJ)

#removes all *.o files + libft.a + libmlx.a
fclean: clean
	$(RM) $(NAME)
	$(RM) push_swap
	$(RM) CHECKER

#removes all *.o files + libft.a + libmlx.a and rebuild everything
re: fclean all

.PHONY:	all clean fclean re bonus