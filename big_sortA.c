/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sortA.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louisbrochard <louisbrochard@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 17:13:52 by louisbrocha       #+#    #+#             */
/*   Updated: 2023/05/05 17:13:58 by louisbrocha      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void		ft_median_sort(t_begin *begin, int len, int *r, int *p)
{
	int		i;
	int		median;
	t_pile	*tmp;

	i = 0;
	median = ft_median(&begin->ba, 1, len);
	while (ft_compare_with_median(begin, len - i, median, 1) && i++ < len)
	{
		if (begin->ba->data < median)
		{
			tmp = begin->ba->next;
			begin->bb = ft_push_pile(&begin->bb, &begin->ba);
			begin->ba = tmp;
			ft_instruction(&begin->inst, 4);
			*p = *p + 1;
		}
		else
		{
			begin->ba = ft_rotate_pile(&begin->ba);
			ft_instruction(&begin->inst, 5);
			*r = *r + 1;
		}
	}
}

static void		ft_place(t_begin *begin, int *r)
{
	int		lena;

	lena = ft_find_len(&begin->ba);
	if (*r > (lena / 2) && lena > 3)
	{
		while (*r < lena)
		{
			begin->ba = ft_rotate_pile(&begin->ba);
			ft_instruction(&begin->inst, 5);
			*r = *r + 1;
		}
	}
	else if (lena > 3)
	{
		while (*r)
		{
			begin->ba = ft_reverse_rotate_pile(&begin->ba);
			ft_instruction(&begin->inst, 7);
			*r = *r - 1;
		}
	}
}

void			ft_work_a(t_begin *begin, int len)
{
	int			r;
	int			p;
	t_pile		*tmp;

	r = 0;
	p = 0;
	if (len <= 3)
	{
		ft_sort_min_a(begin);
		return ;
	}
	if (begin->ba != NULL && ft_is_sort(&begin->ba, 1) == 0)
		return ;
	ft_median_sort(begin, len, &r, &p);
	ft_place(begin, &r);
	ft_work_a(begin, (len - p));
	ft_work_b(begin, p);
	while (p-- && begin->bb != NULL)
	{
		tmp = begin->bb->next;
		begin->ba = ft_push_pile(&begin->ba, &begin->bb);
		begin->bb = tmp;
		ft_instruction(&begin->inst, 3);
	}
}