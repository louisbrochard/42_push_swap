/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louisbrochard <louisbrochard@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 17:09:21 by louisbrocha       #+#    #+#             */
/*   Updated: 2023/05/15 14:19:26 by louisbrocha      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int main(int argc, char **argv)
{
    t_stack *stack_a;
    t_stack *stack_b;

    if (argc == 1)
        return (0);
    if (ft_check_arg(argv) == 1)
        ft_exit_error(NULL, NULL);
    if (argc <= 2)
        return (0);
    if (ft_is_sorted(argv) == 0)
        return (0);
    ft_init(&stack_a, &stack_b, argc, argv);
    if (argc == 3)
		ft_op_rotate(stack_a, 'a');
    else if (argc == 4)
        ft_sort_3_elem(stack_a);
    else
        quick_sort(stack_a, stack_b);


/*
	printf("===================STACK A====================\n");
	t_node *curr = stack_a->top;
    while(curr)
    {
        printf("%d\n", curr->value);
        curr = curr->next;
    }
	printf("===================STACK B=====================\n");
	t_node *curr2 = stack_b->top;
    while(curr2)
    {
        printf("%d\n", curr2->value);
        curr2 = curr2->next;
    }
    printf("=================PARAMETRES=====================\n");
    printf("Size A : %d\n", stack_a->size);
    printf("Size B : %d\n", stack_b->size);
    printf("====================FIN========================\n");
*/



    ft_lst_del(&stack_a);
    ft_lst_del(&stack_b);
    free(stack_a);
    free(stack_b);
    return (0);
}
