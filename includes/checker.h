/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrochar <lbrochar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 14:28:19 by louisbrocha       #+#    #+#             */
/*   Updated: 2023/05/22 16:53:19 by lbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

typedef struct s_node
{
	int				value;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node		*top;
	int			size;
}	t_stack;

// main.c

// check_utils.c
long	ft_atoi2(const char *str);
int		sign(char c);
int		digit(int c);
int		s(int c);

// check.c
int		ft_check_arg(char **argv);
int		ft_check_duplicate(char **argv);
int		ft_argv_is_nb(char *str);
int		ft_is_sorted(char **argv);

// exit_free.c
void	ft_exit_error(t_stack **stack_a, t_stack **stack_b);
void	ft_free_stack(t_stack **stack);

// initialization.c
void	ft_init(t_stack **stack_a, t_stack **stack_b, int argc, char **argv);
void	ft_push_init(t_stack *stack, int value);
void	ft_init2(t_stack **stack_a, t_stack **stack_b, int argc, char **argv);

// list_del.c
void	ft_lst_del(t_stack **stack);

// move.c
void	ft_move(char *str, t_stack *stack_a, t_stack *stack_b);
void	ft_check_stack(t_stack *stack_a, t_stack *stack_b);

// op.c
void	ft_op_push(t_stack *stack_src, t_stack *stack_dest);
void	ft_op_swap(t_stack *stack);
void	ft_op_rotate(t_stack *stack);
void	ft_op_rev_rotate(t_stack *stack);

//utils.c
int		ft_strcmp(const char *s1, const char *s2);
char	*get_next_line(int fd);
char	*ft_read_backup(int fd, char *backup);
char	*ft_get_line(char *backup);
char	*ft_backup(char *backup);
char	*ft_strjoin2(char *s1, char *s2);
void	ft_boucle(char *s1, char *s2, char *str);
char	*ft_strchr2(char *s, int c);
size_t	ft_strlen2(char *str);
int		ft_strlen(const char *str);
size_t	ft_strlcpy(char *dest, const char *src, size_t n);
int		ft_is_stack_sorted(t_stack *stack);

// split.c
char	**ft_split(const char *str, char c);

#endif
