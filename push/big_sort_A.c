/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort_A.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louisbrochard <louisbrochard@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 15:45:29 by louisbrocha       #+#    #+#             */
/*   Updated: 2023/05/15 00:58:05 by louisbrocha      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		ft_compare_with_median(t_stack *stack_a, int n, int median)
{
	int		i;
    t_node  *elem;

	i = 0;
    elem = stack_a->top;
	while (i < n)
	{
		if (elem->value < median)
			return (1);
		i++;
		elem = elem->next;
	}
	return (0);
}

/*
static void			ft_sort_min_a(t_stack *stack_a)
{
    int len;

    len = stack_a->size;
	if (len > 1 && stack_a->top->value > stack_a->top->next->value)
	    ft_op_swap(stack_a, 'a');
	if (len > 2 && stack_a->top->value > stack_a->top->next->value)
	{
		ft_op_rotate(stack_a, 'a');
		ft_op_swap(stack_a, 'a');
		ft_op_rev_rotate(stack_a, 'a');
	}
	if (len > 1 && stack_a->top->value > stack_a->top->next->value)
        ft_op_swap(stack_a, 'a');
}
*/

static void		ft_median_sort(t_stack *stack_a, t_stack *stack_b, int len, int *r, int *p)
{
	int		i;
	int		median;

	i = 0;
	median = 0;
	median = ft_get_median(stack_a, len, 1);
	while (ft_compare_with_median(stack_a, len - i, median) && i++ < len)
	{
		if (stack_a->top->value < median)
		{
            ft_op_push(stack_a, stack_b, 'b');
			*p = *p + 1;
		}
		else
		{
			ft_op_rotate(stack_a, 'a');
			*r = *r + 1;
		}
	}
}

static void		ft_place(t_stack *stack_a, int *r)
{
	int		lena;

	lena = stack_a->size;
	if (*r > (lena / 2) && lena > 3)
	{
		while (*r < lena)
		{
			ft_op_rotate(stack_a, 'a');
			*r = *r + 1;
		}
	}
	else if (lena > 3)
	{
		while (*r)
		{
			ft_op_rev_rotate(stack_a, 'a');
			*r = *r - 1;
		}
	}
}

void			ft_quick_sort_a(t_stack *stack_a, t_stack *stack_b, int len)
{
	int			r;
	int			p;

	r = 0;
	p = 0;
	if (len <= 3)
	{
		if (len == 3)
		{
			ft_sort_3_elem(stack_a);
			return ;
		}
		if (len == 2)
		{
			ft_sort_2_elem(stack_a);
			return ;
		}
	}
	if (stack_a->top != NULL && ft_is_stack_sorted(stack_a) == 0)
		return ;
	ft_median_sort(stack_a, stack_b, len - p, &r, &p);
	ft_place(stack_a, &r);
	ft_quick_sort_a(stack_a, stack_b, (len - p));
	ft_quick_sort_b(stack_a, stack_b, p);
	while (p-- && stack_b->top != NULL)
	{
		ft_op_push(stack_b, stack_a, 'a');
	}
}