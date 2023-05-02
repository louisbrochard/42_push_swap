/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louisbrochard <louisbrochard@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:42:03 by louisbrocha       #+#    #+#             */
/*   Updated: 2023/05/02 16:49:40 by louisbrocha      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_stack *stack, int value)
{
	t_node	*new_node;

	if (!stack)
		ft_exit_error(&stack, NULL);
	new_node = malloc(sizeof(t_node));
	if (!new_node)
		ft_exit_error(&stack, NULL);
	new_node->value = value;
	new_node->next = stack->top;
	stack->top = new_node;
	stack->size++;
}

int		ft_pop(t_stack *stack)
{
	t_node	*top;
	int		value;

	if (!stack || !stack->top)
		ft_exit_error(&stack, NULL);
	top = stack->top;
	stack->top = top->next;
	stack->size--;
	value = top->value;
	free(top);
	return (value);
}

void	ft_rotate(t_stack *stack)
{
	t_node	*last;

	if (!stack || !stack->top || !stack->top->next)
		return ;
	last = stack->top;
	while (last->next)
		last = last->next;
	last->next = stack->top;
	stack->top = stack->top->next;
	last->next->next = NULL;
}
