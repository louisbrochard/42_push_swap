/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louisbrochard <louisbrochard@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 14:23:45 by louisbrocha       #+#    #+#             */
/*   Updated: 2023/05/11 14:15:20 by louisbrocha      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_tab(int *tab, int len)
{
	int		i;
	int		tmp;
	int		n;

	i = 0;
	n = i;
	while (i < len - 1)
	{
		if (tab[i] > tab[i + 1])
		{
			tmp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = tmp;
			i = n;
		}
		else
			i++;
	}
	i = n;
}

int     ft_get_median(t_stack *stack_a, int len)
{
    int median;
    t_node  *tmp;
    int *tab;
    int i;

    i = 0;
    tmp = stack_a->top;
	if (!(tab = (int *)malloc(sizeof(int) * (len + 1))))
		exit(1);
    while (i < len)
    {
        tab[i] = tmp->value;
        i++;
        tmp = tmp->next;
    }
    ft_sort_tab(tab, len);
    if (len % 2 == 0)
        median = tab[(len / 2)];
    else
        median = tab[(len / 2)];
    free(tab);
    return (median);
}

// Fonction de tri rapide (quicksort)
void quick_sort(t_stack *stack_a, t_stack *stack_b)
{	
	int median;
	int	i;

	if (stack_a->size <= 3)
	{
		ft_insertion_sort(stack_a, stack_b);
		return ;
	}
	i = 0;
	median = ft_get_median(stack_a, stack_a->size);
	while (i <= stack_a->size)
	{
		if (stack_a->top->value <= median)
			ft_op_push(stack_a, stack_b, 'b');
		else
			ft_op_rotate(stack_a, 'a');
		i++;
	}
	quick_sort(stack_a, stack_b);
	quick_sort(stack_b, stack_a);

	// Fusionner les sous-ensembles triés
	while (stack_b->size > 0)
	{
		ft_op_push(stack_b, stack_a, 'a');
	}

	// Effectuer d'autres opérations nécessaires pour obtenir le stack A trié
	// ...

	// Mettre à jour le compteur de mouvements
	// ...
}