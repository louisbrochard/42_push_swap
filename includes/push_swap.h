/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louisbrochard <louisbrochard@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 17:17:54 by louisbrocha       #+#    #+#             */
/*   Updated: 2023/05/15 00:20:02 by louisbrocha      ###   ########.fr       */
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
int		ft_is_stack_sorted2(t_stack *stack);
int		ft_is_stack_sorted(t_stack *stack);
int		get_min(t_stack *stack);
void	ft_insertion_sort(t_stack *stack_a, t_stack *stack_b);
void			ft_sort_3_elem(t_stack *stack_a);
void	ft_sort_2_elem(t_stack *stack_a);


// quick_sort.c
void 	quick_sort(t_stack *stack_a, t_stack *stack_b);
int     ft_get_median(t_stack *stack_a, int len, int pile);
void	ft_sort_tab(int *tab, int len);

// list_del.c
void	ft_lst_del(t_stack **stack);

//A
void	ft_quick_sort_a(t_stack *stack_a, t_stack *stack_b, int len);
//B
void	ft_quick_sort_b(t_stack *stack_a, t_stack *stack_b, int len);

#endif
