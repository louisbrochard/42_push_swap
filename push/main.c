/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrochar <lbrochar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 17:09:21 by louisbrocha       #+#    #+#             */
/*   Updated: 2023/05/17 17:16:16 by lbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_init_head(t_head **head, t_stack *stack_a, t_stack *stack_b)
{
	*head = malloc(sizeof(t_stack));
	if (!(*head))
		return ;
	(*head)->a = stack_a;
	(*head)->b = stack_b;
}

static void	ft_clean(t_stack *stack_a, t_stack *stack_b)
{
	ft_lst_del(&stack_a);
	ft_lst_del(&stack_b);
	free(stack_a);
	free(stack_b);
}	

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_head	*head;

	if (argc == 1)
		return (0);
	if (ft_check_arg(argv) == 1)
		ft_exit_error(NULL, NULL);
	if (argc <= 2)
		return (0);
	if (ft_is_sorted(argv) == 0)
		return (0);
	ft_init(&stack_a, &stack_b, argc, argv);
	ft_init_head(&head, stack_a, stack_b);
	if (argc == 3)
		ft_op_rotate(stack_a, 'a');
	else if (argc == 4)
		ft_sort_3_elem(stack_a);
	else
		quick_sort(stack_a, stack_b, head);
	ft_clean(stack_a, stack_b);
	free(head);
	return (0);
}
