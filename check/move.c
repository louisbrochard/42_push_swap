/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louisbrochard <louisbrochard@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 14:51:15 by louisbrocha       #+#    #+#             */
/*   Updated: 2023/05/15 16:20:21 by louisbrocha      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void    ft_check_stack(t_stack *stack_a, t_stack *stack_b)
{
    t_node  *elem;

    elem = stack_a->top;
    if (elem == NULL)
    {
        ft_printf("KO\n");
        return ;
    }
    while (elem->next != NULL)
    {
        if (elem->value < elem->next->value)
            elem = elem->next;
        else
        {
            ft_printf("KO\n");
            exit(0);
        }
    }
    if (stack_b->top == NULL)
        ft_printf("OK\n");
    else
        ft_printf("KO\n");
}

void			ft_move(char *str, t_stack *stack_a, t_stack *stack_b)
{
	if (str && (ft_strcmp(str, "sa\n") == 0))
        ft_op_swap(stack_a);
	else if (str && (ft_strcmp(str, "sb\n") == 0))
		ft_op_swap(stack_b);
	else if (str && (ft_strcmp(str, "pa\n") == 0) && stack_b->top != NULL)
        ft_op_push(stack_b, stack_a);
	else if (str && (ft_strcmp(str, "pb\n") == 0) && stack_a->top != NULL)
        ft_op_push(stack_a, stack_b);
    else if (str && (ft_strcmp(str, "ra\n") == 0 || ft_strcmp(str, "rr") == 0))
		ft_op_rotate(stack_a);
	else if (str && (ft_strcmp(str, "rra\n") == 0 || ft_strcmp(str, "rrr") == 0))
		ft_op_rev_rotate(stack_a);
	else if (str && (ft_strcmp(str, "rb\n") == 0 || ft_strcmp(str, "rr") == 0))
		ft_op_rotate(stack_b);
	else if (str && (ft_strcmp(str, "rrb\n") == 0 || ft_strcmp(str, "rrr") == 0))
		ft_op_rev_rotate(stack_b);
	else if (str && (ft_strcmp(str, "ss\n") == 0))
	{
        ft_op_swap(stack_a);
        ft_op_swap(stack_b);
	}
	else if ((str && (ft_strcmp(str, "pa\n") == 0) && stack_b->top == NULL)
			|| (str && (ft_strcmp(str, "pb\n") == 0) && stack_a->top == NULL))
		return ;
	else
	{
		write(2, "Error\n", 6);
		exit(1);
	}
}