/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_3_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrochar <lbrochar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 15:43:23 by lbrochar          #+#    #+#             */
/*   Updated: 2023/05/17 16:31:42 by lbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ft_rot(t_node **e, t_node **s, t_stack *stack_a)
{
	t_node		*elem;
	t_node		*suiv;

	elem = *e;
	suiv = *s;
	if (elem->value < suiv->value)
	{
		if (elem->value < suiv->next->value)
			ft_op_rev_rotate(stack_a, 'a');
		else
			ft_op_rotate(stack_a, 'a');
	}
}

void	ft_deal_algo(t_stack *stack_a)
{
	ft_op_swap(stack_a, 'a');
	ft_op_rotate(stack_a, 'a');
	ft_op_swap(stack_a, 'a');
	ft_op_rev_rotate(stack_a, 'a');
}

void	ft_sort_3_elem(t_stack *stack_a)
{
	t_node		*elem;
	t_node		*suiv;

	while (stack_a->top != NULL && ft_is_stack_sorted(stack_a) == 1)
	{
		elem = stack_a->top;
		suiv = elem->next;
		if ((suiv->next->value > suiv->value)
			&& (elem->value > suiv->next->value))
		{
			ft_deal_algo(stack_a);
		}
		else if (elem->value > suiv->value)
		{
			if (elem->value < suiv->next->value)
				ft_op_swap(stack_a, 'a');
			else
				ft_op_rotate(stack_a, 'a');
		}
		else if (stack_a->top != NULL && ft_is_stack_sorted(stack_a) == 1)
			ft_rot(&elem, &suiv, stack_a);
	}
}
