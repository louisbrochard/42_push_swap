/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_del.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louisbrochard <louisbrochard@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 00:17:47 by louisbrocha       #+#    #+#             */
/*   Updated: 2023/05/17 15:00:43 by lbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_lst_del(t_stack **stack)
{
	t_node	*tmp;
	t_node	*elem;

	elem = (*stack)->top;
	while (elem != NULL)
	{
		tmp = elem->next;
		free(elem);
		elem = tmp;
	}
	free(elem);
}
