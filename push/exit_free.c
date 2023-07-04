/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrochar <lbrochar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 17:16:20 by louisbrocha       #+#    #+#             */
/*   Updated: 2023/07/04 13:13:01 by lbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_free_stack(t_stack **stack)
{
	t_node	*current;
	t_node	*temp;

	if (!stack || !(*stack))
		return ;
	current = (*stack)->top;
	while (current != NULL)
	{
		temp = current->next;
		free(current);
		current = temp;
	}
	free(*stack);
	*stack = NULL;
}

void	ft_exit_error(t_stack **stack_a, t_stack **stack_b)
{
	if (stack_a && *stack_a)
		ft_free_stack(stack_a);
	if (stack_b && *stack_b)
		ft_free_stack(stack_b);
	write(2, "Error\n", 6);
	exit (1);
}

int	ft_free_total(t_head **head, t_stack **stack_a, t_stack **stack_b)
{
	if (head && *head)
	{
		free(*head);
	}
	ft_free_stack(stack_a);
	ft_free_stack(stack_b);
	return (0);
}
