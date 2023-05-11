/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louisbrochard <louisbrochard@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:49:04 by louisbrocha       #+#    #+#             */
/*   Updated: 2023/05/11 19:54:21 by louisbrocha      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_stack_sorted2(t_stack *stack)
{
	t_node	*current;

	if (!stack || !stack->top)
		return (1);
	current = stack->top;
	while (current->next)
	{
		if (current->value < current->next->value)
			return (1);
		current = current->next;
	}
	return (0);
}

int	ft_is_stack_sorted(t_stack *stack)
{
	t_node	*current;

	if (!stack || !stack->top)
		return (1);
	current = stack->top;
	while (current->next)
	{
		if (current->value > current->next->value)
			return (1);
		current = current->next;
	}
	return (0);
}

int	get_min(t_stack *stack)
{
	int		min;
	t_node	*tmp;

	tmp = stack->top;
	min = tmp->value;
	while (tmp != NULL)
	{
		if (tmp->value < min)
			min = tmp->value;
		tmp = tmp->next;
	}
	return (min);
}

void	ft_insertion_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	min;

	if (stack_a->size == 2)
		ft_op_rotate(stack_a, 'a');
	while (ft_is_stack_sorted(stack_a) == 1)
	{
		if (stack_a->size == 2)
			ft_op_rotate(stack_a, 'a');
		min = get_min(stack_a);
		while (stack_a->top->value != min)
			ft_op_rotate(stack_a, 'a');
		if (ft_is_stack_sorted(stack_a) == 1)
			ft_op_push(stack_a, stack_b, 'b');
	}
	while (stack_b->size != 0)
		ft_op_push(stack_b, stack_a, 'a');
}
