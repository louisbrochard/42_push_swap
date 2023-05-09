/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sortB.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louisbrochard <louisbrochard@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 17:14:10 by louisbrocha       #+#    #+#             */
/*   Updated: 2023/05/05 17:14:44 by louisbrocha      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		ft_median_sort(t_begin *begin, int len, int *r, int *p)
{
	int		i;
	int		median;
	t_pile	*tmp;

	i = 0;
	median = ft_median(&begin->bb, 2, len);
	while (ft_compare_with_median(begin, len - i, median, 2) && i++ < len)
	{
		if (begin->bb->data > median)
		{
			tmp = begin->bb->next;
			begin->ba = ft_push_pile(&begin->ba, &begin->bb);
			begin->bb = tmp;
			ft_instruction(&begin->inst, 3);
			*p = *p + 1;
		}
		else
		{
			begin->bb = ft_rotate_pile(&begin->bb);
			ft_instruction(&begin->inst, 6);
			*r = *r + 1;
		}
	}
}

static void		ft_place(t_begin *begin, int *r)
{
	int		lenb;

	lenb = ft_find_len(&begin->bb);
	if (*r > (lenb / 2) && lenb > 3)
	{
		while (*r < lenb)
		{
			begin->bb = ft_rotate_pile(&begin->bb);
			ft_instruction(&begin->inst, 6);
			*r = *r + 1;
		}
	}
	else if (lenb > 3)
	{
		while (*r)
		{
			begin->bb = ft_reverse_rotate_pile(&begin->bb);
			ft_instruction(&begin->inst, 8);
			*r = *r - 1;
		}
	}
}

void			ft_work_b(t_begin *begin, int len)
{
	int			r;
	int			p;
	t_pile		*tmp;

	r = 0;
	p = 0;
	if (len <= 3)
	{
		ft_sort_min_b(begin);
		return ;
	}
	ft_median_sort(begin, len, &r, &p);
	ft_work_a(begin, p);
	ft_place(begin, &r);
	ft_work_b(begin, len - p);
	if (begin->bb != NULL && ft_is_sort(&begin->bb, 2) == 1)
	{
		while (p--)
		{
			tmp = begin->ba->next;
			begin->bb = ft_push_pile(&begin->bb, &begin->ba);
			begin->ba = tmp;
			ft_instruction(&begin->inst, 4);
		}
	}
}