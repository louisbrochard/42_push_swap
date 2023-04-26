/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louisbrochard <louisbrochard@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 17:17:54 by louisbrocha       #+#    #+#             */
/*   Updated: 2023/04/26 18:55:48 by louisbrocha      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

// struct
typedef struct s_stack
{
	int				value;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}   t_stack;



// main.c


// utils.c
void    ft_exit_error(t_stack **stack_a, t_stack **stack_b);
void	ft_free_stack(t_stack **stack);

// check.c
int     ft_check_arg(char **argv);
int     ft_argv_is_nb(char *str);
int     ft_check_duplicate(char **argv);
int     ft_is_sorted(char **argv);


// check_utils.c
int     ft_isdigit(int c);
long    ft_atoi(const char *str);
int     ft_is_sign(char c);

#endif