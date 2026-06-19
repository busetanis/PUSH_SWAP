/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_chunk_small_sort.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: butanis <butanis@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 20:24:30 by butanis           #+#    #+#             */
/*   Updated: 2026/05/06 17:06:14 by butanis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ps_small_get_min_pos(t_node *stack)
{
	int		min;
	int		pos;
	int		min_pos;
	t_node	*tmp;

	tmp = stack;
	min = tmp->value;
	pos = 0;
	min_pos = 0;
	while (tmp)
	{
		if (tmp->value < min)
		{
			min = tmp->value;
			min_pos = pos;
		}
		tmp = tmp->next;
		pos++;
	}
	return (min_pos);
}

static void	ps_small_move_min_top(t_node **a, t_bench *bench)
{
	int	min_pos;
	int	size;

	min_pos = ps_small_get_min_pos(*a);
	size = stack_size(*a);
	if (min_pos <= size / 2)
	{
		while (min_pos-- > 0)
			ft_ra(a, 0, bench);
	}
	else
	{
		while (min_pos++ < size)
			ft_rra(a, 0, bench);
	}
}

void	small_sort_3(t_node **a, t_bench *bench)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->value;
	second = (*a)->next->value;
	third = (*a)->next->next->value;
	if (first > second && second < third && first < third)
		ft_sa(a, 0, bench);
	else if (first > second && second > third)
	{
		ft_sa(a, 0, bench);
		ft_rra(a, 0, bench);
	}
	else if (first > second && second < third && first > third)
		ft_ra(a, 0, bench);
	else if (first < second && second > third && first < third)
	{
		ft_sa(a, 0, bench);
		ft_ra(a, 0, bench);
	}
	else if (first < second && second > third && first > third)
		ft_rra(a, 0, bench);
}

void	sort_small(t_node **a, t_node **b, t_bench *bench)
{
	int	size;

	size = stack_size(*a);
	if (size == 2)
	{
		if ((*a)->value > (*a)->next->value)
			ft_sa(a, 0, bench);
	}
	else if (size == 3)
		sort_3(a, bench);
	else
	{
		while (size > 3)
		{
			ps_small_move_min_top(a, bench);
			ft_pb(a, b, 0, bench);
			size--;
		}
		sort_3(a, bench);
		while (*b)
			ft_pa(a, b, 0, bench);
	}
}
