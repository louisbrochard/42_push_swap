/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louisbrochard <louisbrochard@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:06:02 by louisbrocha       #+#    #+#             */
/*   Updated: 2023/05/15 15:21:04 by louisbrocha      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	ft_op_push(t_stack *stack_src, t_stack *stack_dest)
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
}

void	ft_op_swap(t_stack *stack)
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
}

void	ft_op_rotate(t_stack *stack)
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
}

void	ft_op_rev_rotate(t_stack *stack)
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
}
