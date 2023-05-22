/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrochar <lbrochar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 15:56:30 by louisbrocha       #+#    #+#             */
/*   Updated: 2023/05/22 16:10:56 by lbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_push_init(t_stack *stack, int value)
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

void	ft_init(t_stack **stack_a, t_stack **stack_b, int argc, char **argv)
{
	int	i;

	*stack_a = malloc(sizeof(t_stack));
	if (!(*stack_a))
		return ;
	(*stack_a)->top = NULL;
	(*stack_a)->size = 0;
	i = argc;
	while (i-- > 1)
		ft_push_init(*stack_a, ft_atoi2(argv[i]));
	*stack_b = malloc(sizeof(t_stack));
	if (!(*stack_a))
		return ;
	(*stack_b)->top = NULL;
	(*stack_b)->size = 0;
}

void	ft_init2(t_stack **stack_a, t_stack **stack_b, int argc, char **argv)
{
	int	i;

	*stack_a = malloc(sizeof(t_stack));
	if (!(*stack_a))
		return ;
	(*stack_a)->top = NULL;
	(*stack_a)->size = 0;
	i = argc;
	while (i-- > 0)
		ft_push_init(*stack_a, ft_atoi2(argv[i]));
	*stack_b = malloc(sizeof(t_stack));
	if (!(*stack_a))
		return ;
	(*stack_b)->top = NULL;
	(*stack_b)->size = 0;
}
