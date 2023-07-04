/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrochar <lbrochar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 14:27:42 by louisbrocha       #+#    #+#             */
/*   Updated: 2023/07/04 13:07:09 by lbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

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

void	ft_checker(t_stack *stack_a, t_stack *stack_b)
{
	char	*str;

	str = get_next_line(0);
	while (str != NULL)
	{
		ft_move(str, stack_a, stack_b);
		free(str);
		str = get_next_line(0);
	}
	free(str);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
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
	if (ft_is_stack_sorted(stack_a) == 0)
		return (ft_free_total(&stack_a, &stack_b));
	ft_checker(stack_a, stack_b);
	ft_check_stack(stack_a, stack_b);
	ft_clean(stack_a, stack_b);
	return (0);
}
