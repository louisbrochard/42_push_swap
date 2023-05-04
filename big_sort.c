/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louisbrochard <louisbrochard@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 22:25:47 by louisbrocha       #+#    #+#             */
/*   Updated: 2023/05/03 23:05:30 by louisbrocha      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int cmpfunc(const void *a, const void *b)
{
    return (*(int*)a - *(int*)b);
}

int get_median(t_stack *stack)
{
    int size = stack->size;
    int *sorted_arr = malloc(sizeof(int) * size);

    if (!sorted_arr)
        exit_error("Error: malloc failed\n");

    // copier les éléments de la pile dans un tableau
    int i = 0;
    while (!is_empty_stack(stack))
    {
        sorted_arr[i] = stack->top->value;
        pop_stack(stack);
        i++;
    }

    // trier le tableau en ordre croissant
    qsort(sorted_arr, size, sizeof(int), cmpfunc);

    // récupérer la valeur médiane
    int median = sorted_arr[size / 2];

    // remettre les éléments dans la pile
    i = size - 1;
    while (i >= 0)
    {
        push_stack(stack, sorted_arr[i]);
        i--;
    }

    free(sorted_arr);

    return median;
}

void quick_sort(t_stack *stack_a, t_stack *stack_b, int size)
{
    if (size <= 1)
        return;

    int pivot = get_median(stack_a);
    int i = -1;
    while (++i < size)
    {
        if (stack_a->top->value < pivot)
            do_pb(stack_a, stack_b);
        else
            do_ra(stack_a);
    }

    int pos_pivot = get_elem_position(stack_a, pivot);
    int size_lower = pos_pivot;
    int size_upper = size - pos_pivot - 1;

    quick_sort(stack_a, stack_b, size_lower);
    while (size_lower--)
        do_ra(stack_a);

    quick_sort(stack_a, stack_b, size_upper);
    while (size_upper--)
        do_rra(stack_a);

    while (!is_empty_stack(stack_b))
    {
        if (stack_b->top->value < pivot)
            do_pa(stack_a, stack_b);
        else
            do_rra(stack_b);
    }
}
