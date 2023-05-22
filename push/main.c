/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrochar <lbrochar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 17:09:21 by louisbrocha       #+#    #+#             */
/*   Updated: 2023/05/22 18:02:36 by lbrochar         ###   ########.fr       */
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

int	argv_len(char **argv)
{
	int	i;

	i = 0;
	while (argv[i] != 0)
		i++;
	return (i);
}

int	ft_need_parse(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc != 2)
		return (1);
	if (ft_check_space(argv[1]) == 0)
		return (1);
	while (argv[1][i] != 0)
	{
		if (digit(argv[1][i]) == 0 && sign(argv[1][i]) == 0
			&& s(argv[1][i]) == 0)
			return (1);
		if (sign(argv[1][i]) == 1 && digit(argv[1][i + 1]) == 0)
			return (1);
		if (i == 0 && digit(argv[1][i]) == 0 && sign(argv[1][i]) == 0)
			return (1);
		if (digit(argv[1][i + 1]) == 0 && sign(argv[1][i + 1]) == 0
			&& s(argv[1][i]) == 1)
			return (1);
		i++;
	}
	if (digit(argv[1][ft_strlen(argv[1]) - 1]) == 0)
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_head	*head;

	if (argc <= 2 && ft_need_parse(argc, argv) == 1)
		return (0);
	if (argc == 2 && ft_need_parse(argc, argv) == 0)
	{
		argv = ft_split(argv[1], ' ');
		ft_init2(&stack_a, &stack_b, argv_len(argv), argv);
	}
	else
	{
		if (ft_check_arg(argv) == 1)
			ft_exit_error(NULL, NULL);
		ft_init(&stack_a, &stack_b, argv_len(argv), argv);
	}
	ft_init_head(&head, stack_a, stack_b);
	if (ft_is_stack_sorted(stack_a) == 0)
		return (0);
	quick_sort(stack_a, stack_b, head, argc);
	ft_clean(stack_a, stack_b);
	free(head);
	return (0);
}
