/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louisbrochard <louisbrochard@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 14:23:45 by louisbrocha       #+#    #+#             */
/*   Updated: 2023/05/15 14:16:43 by louisbrocha      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

int     ft_get_median(t_stack *stack_a, int len, int pile)
{
    int median;
    t_node  *tmp;
    int *tab;
    int i;

    i = 0;
    tmp = stack_a->top;
	if (!(tab = (int *)malloc(sizeof(int) * (len))))
		exit(1);
    while (i < len)
    {
        tab[i] = tmp->value;
        i++;
        tmp = tmp->next;
    }
    ft_sort_tab(tab, len);
    if (len % 2 == 0 && pile == 2)
        median = tab[(len / 2) - 1];
    else
        median = tab[(len / 2)];
    free(tab);
    return (median);
}

void quick_sort(t_stack *stack_a, t_stack *stack_b)
{
	ft_quick_sort_a(stack_a, stack_b, stack_a->size);
	return ;
}