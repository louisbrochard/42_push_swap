/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louisbrochard <louisbrochard@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 17:17:54 by louisbrocha       #+#    #+#             */
/*   Updated: 2023/05/03 18:12:46 by louisbrocha      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

// struct
//s_node est une structure qui contient un entier (int) et un pointeur vers le prochain élément (struct s_node *next) de la pile. 
//Cette structure est utilisée pour représenter chaque élément individuel de la pile.
typedef struct s_node
{
    int value;
    struct s_node *next;
} t_node;

//s_stack est une structure qui contient un pointeur vers le sommet de la pile (struct s_node *top) 
//et la taille de la pile (int size). 
//Cette structure est utilisée pour représenter l'ensemble de la pile et stocker les éléments de la pile en utilisant des nœuds s_node.
typedef struct s_stack
{
	t_node	*top;
	int	size;
}   t_stack;



// main.c


// exit_free.c
void    ft_exit_error(t_stack **stack_a, t_stack **stack_b);
void	ft_free_stack(t_stack **stack);

// initialization.c
void	ft_initialisation(t_stack **stack_a, t_stack **stack_b, int argc, char **argv);
void    ft_push(t_stack *stack, int value);

// check.c
int     ft_check_arg(char **argv);
int     ft_argv_is_nb(char *str);
int     ft_check_duplicate(char **argv);
int     ft_is_sorted(char **argv);


// check_utils.c
int     ft_isdigit(int c);
long    ft_atoi(const char *str);
int     ft_is_sign(char c);


// op.c
void	ft_op_swap(t_stack *stack, char c);
void	ft_op_push(t_stack *stack_src, t_stack *stack_dest, char c);
void    ft_op_rotate(t_stack *stack, char c);
void	ft_op_rev_rotate(t_stack *stack, char c);

// short_sort.c
int ft_is_stack_sorted(t_stack *stack);
int get_min(t_stack *stack);
void	ft_insertion_sort(t_stack *stack_a, t_stack *stack_b);

// chatgpt.c



#endif