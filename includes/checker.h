/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louisbrochard <louisbrochard@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 14:28:19 by louisbrocha       #+#    #+#             */
/*   Updated: 2023/05/15 15:27:16 by louisbrocha      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include "../libft/includes/ft_printf.h"
# include "../libft/includes/libft.h"
# include "../libft/includes/get_next_line.h"

typedef struct s_node
{
	int			value;
	struct s_node			*next;
}	t_node;

typedef struct s_stack
{
	t_node		*top;
	int			size;
}	t_stack;

// main.c

// check_utils.c
long	ft_atoi2(const char *str);
int	ft_is_sign(char c);
int	ft_isdigit(int c);

// check.c
int	ft_check_arg(char **argv);
int	ft_check_duplicate(char **argv);
int	ft_argv_is_nb(char *str);
int	ft_is_sorted(char **argv);

// exit_free.c
void	ft_exit_error(t_stack **stack_a, t_stack **stack_b);
void	ft_free_stack(t_stack **stack);

// initialization.c
void	ft_init(t_stack **stack_a, t_stack **stack_b, int argc, char **argv);
void	ft_push_init(t_stack *stack, int value);

// list_del.c
void		ft_lst_del(t_stack **stack);

// move.c
void			ft_move(char *str, t_stack *stack_a, t_stack *stack_b);
void    ft_check_stack(t_stack *stack_a, t_stack *stack_b);

// op.c
void	ft_op_push(t_stack *stack_src, t_stack *stack_dest);
void	ft_op_swap(t_stack *stack);
void	ft_op_rotate(t_stack *stack);
void	ft_op_rev_rotate(t_stack *stack);



#endif