/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louisbrochard <louisbrochard@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:34:48 by louisbrocha       #+#    #+#             */
/*   Updated: 2023/05/02 16:47:55 by louisbrocha      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_merge_stack_b(t_stack **stack_a, t_stack **stack_b, int size)
{
    int     half_size;
    int     nb_pushed;

    half_size = size / 2;
    nb_pushed = 0;
    while (nb_pushed < half_size)
    {
        if ((*stack_b)->value > (*stack_a)->value)
        {
            ft_push(stack_a, ft_pop(stack_b));
            nb_pushed++;
        }
        else if (ft_get_last(stack_a)->value > (*stack_b)->value
                 && (*stack_b)->value > (*stack_a)->next->value)
            ft_insert(stack_a, ft_pop(stack_b));
        else
        {
            ft_reverse_rotate(stack_a);
            ft_reverse_rotate(stack_a);
            ft_push(stack_a, ft_pop(stack_b));
            ft_rotate(stack_a);
            ft_rotate(stack_a);
            nb_pushed++;
        }
    }
}

void	ft_split_stack_a(t_stack *stack_a, t_stack *stack_b, int len_a)
{
	int	median;
	int	pushed;

	median = ft_find_median(stack_a, len_a);
	pushed = 0;
	while (pushed < len_a / 2)
	{
		if (stack_a->top->value < median)
		{
			ft_push(stack_b, ft_pop(stack_a));
			pushed++;
		}
		else
			ft_rotate(stack_a);
	}
}

int		ft_find_median(t_stack *stack, int len)
{
	int		*array;
	int		i;
	int		median;

	if (!(array = malloc(sizeof(int) * len)))
		ft_exit_error(&stack, NULL);
	i = 0;
	while (i < len)
	{
		array[i] = stack->top->value;
		ft_rotate(stack);
		i++;
	}
	ft_sort_array(array, len);
	median = array[len / 2];
	free(array);
	return (median);
}

void	ft_sort_array(int *array, int len)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < len - 1)
	{
		j = i + 1;
		while (j < len)
		{
			if (array[i] > array[j])
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
			}
			j++;
		}
		i++;
	}
}


void	ft_sort_three(t_stack *stack)
{
	int	a;
	int	b;
	int	c;

	a = stack->top->value;
	b = stack->top->next->value;
	c = stack->top->next->next->value;
	if (a > b && a > c && b < c)
		ft_swap(stack, 'a');
	else if (a > b && b > c)
	{
		ft_swap(stack, 'a');
		ft_reverse_rotate(stack, 'a');
	}
	else if (a > b && a < c)
		ft_rotate(stack, 'a');
	else if (a < b && a > c)
		ft_reverse_rotate(stack, 'a');
	else if (a < b && a < c && b > c)
	{
		ft_swap(stack, 'a');
		ft_rotate(stack, 'a');
	}
}

void	ft_sort_five(t_stack *stack_a, t_stack *stack_b)
{
	ft_sort_three(stack_a);
	ft_push(stack_b, stack_a->top->value);
	ft_push(stack_b, stack_a->top->next->value);
	ft_sort_three(stack_a);
	if (stack_b->top->value > stack_b->top->next->value)
		ft_swap(stack_b, 'b');
	while (stack_b->size)
	{
		if (stack_b->top->value > stack_a->top->value)
			ft_push(stack_a, stack_b->top->value);
		else if (stack_b->top->value < stack_a->top->value)
		{
			ft_rotate(stack_a, 'a');
			if (stack_b->top->value > stack_a->top->value || \
					stack_b->top->value < stack_a->top->next->value)
				ft_push(stack_a, stack_b->top->value);
			else
				ft_reverse_rotate(stack_a, 'a');
		}
		ft_pop(stack_b);
	}
}


void	ft_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	len;

	len = stack_a->size;
	if (len <= 3)
		ft_sort_three(stack_a);
	else if (len <= 5)
		ft_sort_five(stack_a, stack_b);
	else
	{
        printf("En cours de construction mgl");
        /*
		ft_split_stack_a(stack_a, stack_b, len);
		ft_sort(stack_a, stack_b);
		ft_merge_stack_b(stack_a, stack_b, len);
        */
	}
}