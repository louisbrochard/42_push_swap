/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort_B.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrochar <lbrochar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 15:45:22 by louisbrocha       #+#    #+#             */
/*   Updated: 2023/05/17 15:36:14 by lbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	ft_compare_with_median(t_stack *stack_b, int n, int median)
{
	int		i;
	t_node	*elem;

	i = 0;
	elem = stack_b->top;
	while (i < n)
	{
		if (elem->value > median)
			return (1);
		i++;
		elem = elem->next;
	}
	return (0);
}

static void	ft_sort_min_b(t_stack *stack_b)
{
	int	len;

	len = stack_b->size;
	if (len > 1 && stack_b->top->value < stack_b->top->next->value)
		ft_op_swap(stack_b, 'b');
	if (len > 2 && stack_b->top->next->value < stack_b->top->next->next->value)
	{
		ft_op_rotate(stack_b, 'b');
		ft_op_swap(stack_b, 'b');
		ft_op_rev_rotate(stack_b, 'b');
	}
	if (len > 1 && stack_b->top->value < stack_b->top->next->value)
		ft_op_swap(stack_b, 'b');
}

static void	ft_median_sort(t_stack *sa, t_stack *sb, int len, int *r, int *p)
{
	int	i;
	int	median;

	i = 0;
	median = ft_get_median(sb, len, 2);
	while (ft_compare_with_median(sb, len - i, median) && i++ < len)
	{
		if (sb->top->value > median)
		{
			ft_op_push(sb, sa, 'a');
			*p = *p + 1;
		}
		else
		{
			ft_op_rotate(sb, 'b');
			*r = *r + 1;
		}
	}
}

static void	ft_place(t_stack *stack_b, int *r)
{
	int	lenb;

	lenb = stack_b->size;
	if (*r > (lenb / 2) && lenb > 3)
	{
		while (*r < lenb)
		{
			ft_op_rotate(stack_b, 'b');
			*r = *r + 1;
		}
	}
	else if (lenb > 3)
	{
		while (*r)
		{
			ft_op_rev_rotate(stack_b, 'b');
			*r = *r - 1;
		}
	}
}

void	ft_quick_sort_b(t_stack *stack_a, t_stack *stack_b, int len)
{
	int	r;
	int	p;

	r = 0;
	p = 0;
	if (len <= 3)
	{
		ft_sort_min_b(stack_b);
		return ;
	}
	ft_median_sort(stack_a, stack_b, len - p, &r, &p);
	ft_quick_sort_a(stack_a, stack_b, p);
	ft_place(stack_b, &r);
	ft_quick_sort_b(stack_a, stack_b, len - p);
	if (stack_b->top != NULL && ft_is_stack_sorted2(stack_b) == 1)
	{
		while (p--)
			ft_op_push(stack_a, stack_b, 'b');
	}
}
