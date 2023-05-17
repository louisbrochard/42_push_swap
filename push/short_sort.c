/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrochar <lbrochar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:49:04 by louisbrocha       #+#    #+#             */
/*   Updated: 2023/05/17 16:36:52 by lbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

void	ft_sort_2_elem(t_stack *stack_a)
{
	t_node	*elem;

	elem = stack_a->top;
	if (elem->value > elem->next->value)
		ft_op_swap(stack_a, 'a');
}
