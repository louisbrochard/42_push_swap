/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrochar <lbrochar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:06:02 by louisbrocha       #+#    #+#             */
/*   Updated: 2023/05/22 18:07:58 by lbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_op_push(t_stack *stack_src, t_stack *stack_dest, char c)
{
	t_node	*src_top;

	if (!stack_src || !stack_src->top)
		return ;
	src_top = stack_src->top;
	stack_src->top = src_top->next;
	src_top->next = NULL;
	if (!stack_dest)
		return ;
	src_top->next = stack_dest->top;
	stack_dest->top = src_top;
	stack_dest->size = stack_dest->size + 1;
	stack_src->size = stack_src->size - 1;
	if (c == 'a')
		write(1, "pa\n", 3);
	else if (c == 'b')
		write(1, "pb\n", 3);
}

void	ft_op_swap(t_stack *stack, char c)
{
	t_node	*first;
	t_node	*second;

	if (!stack || !stack->top || !stack->top->next)
		return ;
	first = stack->top;
	second = stack->top->next;
	first->next = second->next;
	second->next = first;
	stack->top = second;
	if (c == 'a')
		write(1, "sa\n", 3);
	if (c == 'b')
		write(1, "sb\n", 3);
}

void	ft_op_rotate(t_stack *stack, char c)
{
	t_node	*first;
	t_node	*last;

	if (!stack || !stack->top || !stack->top->next)
		return ;
	first = stack->top;
	last = stack->top;
	while (last->next != NULL)
		last = last->next;
	last->next = first;
	stack->top = first->next;
	first->next = NULL;
	if (c == 'a')
		write(1, "ra\n", 3);
	else if (c == 'b')
		write(1, "rb\n", 3);
}

void	ft_op_rev_rotate(t_stack *stack, char c)
{
	t_node	*last;
	t_node	*second_last;

	if (!stack || !stack->top || !stack->top->next)
		return ;
	last = stack->top;
	while (last->next)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	last->next = stack->top;
	stack->top = last;
	if (c == 'a')
		write(1, "rra\n", 4);
	if (c == 'b')
		write(1, "rrb\n", 4);
}
