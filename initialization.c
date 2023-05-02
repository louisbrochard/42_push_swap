/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louisbrochard <louisbrochard@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 15:56:30 by louisbrocha       #+#    #+#             */
/*   Updated: 2023/05/02 16:47:15 by louisbrocha      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_initialisation(t_stack **stack_a, t_stack **stack_b, int argc, char **argv)
{
    int i;

    //Initialisation de stack A
    *stack_a = malloc(sizeof(t_stack));
    (*stack_a)->top = NULL;
    (*stack_a)->size = 0;
    i = argc - 1;
    while(i-- > 0)
        ft_push(*stack_a, ft_atoi(argv[i]));

    //Initialisation de stack B
    *stack_b = malloc(sizeof(t_stack));
    (*stack_b)->top = NULL;
    (*stack_b)->size = 0;
}
