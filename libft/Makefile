SRCS	= ft_strlen.c ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_memset.c ft_strchr.c ft_strjoin.c ft_strlcpy.c ft_strncmp.c ft_tolower.c ft_toupper.c ft_strrchr.c ft_strnstr.c ft_calloc.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstnew.c ft_lstiter.c ft_lstmap.c ft_strlcat.c ft_memcpy.c ft_memmove.c ft_memchr.c ft_memcmp.c ft_strdup.c ft_substr.c ft_strtrim.c ft_itoa.c ft_lstadd_front.c ft_split.c 

SRCS_BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c 

NAME	= libft.a

OBJS	=  ${SRCS:.c=.o}

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

.c.o	:
		 $(CC) $(CFLAGS) -c $< -o ${<:.c=.o}

${NAME} : ${OBJS}
		ar rc ${NAME} ${OBJS}

all : ${NAME}


clean :
		rm -f ${OBJS}

fclean : clean
		rm -f ${NAME}

re : fclean all

bonus:	$(OBJS_BONUS)
	ar -rcs $(NAME) $(OBJS_BONUS)

so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRCS)
	gcc -nostartfiles -shared -o libft.so $(OBJS)
