/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louisbrochard <louisbrochard@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 17:17:54 by louisbrocha       #+#    #+#             */
/*   Updated: 2023/05/09 15:04:32 by louisbrocha      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

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


// exit_free.c
void	ft_exit_error(t_stack **stack_a, t_stack **stack_b);
void	ft_free_stack(t_stack **stack);

// initialization.c
void	ft_init(t_stack **stack_a, t_stack **stack_b, int argc, char **argv);
void	ft_push(t_stack *stack, int value);

// check.c
int		ft_check_arg(char **argv);
int		ft_argv_is_nb(char *str);
int		ft_check_duplicate(char **argv);
int		ft_is_sorted(char **argv);


// check_utils.c
int		ft_isdigit(int c);
long	ft_atoi(const char *str);
int		ft_is_sign(char c);


// op.c
void	ft_op_swap(t_stack *stack, char c);
void	ft_op_push(t_stack *stack_src, t_stack *stack_dest, char c);
void	ft_op_rotate(t_stack *stack, char c);
void	ft_op_rev_rotate(t_stack *stack, char c);

// short_sort.c
int		ft_is_stack_sorted(t_stack *stack);
int		get_min(t_stack *stack);
void	ft_insertion_sort(t_stack *stack_a, t_stack *stack_b);

// chatgpt.c

/*
//A
void			ft_work_a(t_begin *begin, int len);

//B
void			ft_work_b(t_begin *begin, int len);
static void		ft_place(t_begin *begin, int *r);
static void		ft_median_sort(t_begin *begin, int len, int *r, int *p);
*/

#endif
