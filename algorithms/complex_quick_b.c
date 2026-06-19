/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_quick_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: butanis <butanis@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 15:39:23 by butanis           #+#    #+#             */
/*   Updated: 2026/05/03 16:06:20 by butanis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	restore_b(t_node **b, int rotated, t_bench *bench)
{
	while (rotated > 0)
	{
		ft_rrb(b, 0, bench);
		rotated--;
	}
}

static void	partition_b(t_node **a, t_node **b, int *info, t_bench *bench)
{
	int	pivot;

	pivot = complex_quick_pivot(*b, info[0]);
	info[1] = 0;
	info[2] = 0;
	while (info[0] > 0)
	{
		if ((*b)->value >= pivot)
		{
			ft_pa(a, b, 0, bench);
			info[1]++;
		}
		else
		{
			ft_rb(b, 0, bench);
			info[2]++;
		}
		info[0]--;
	}
}

void	quick_sort_b(t_node **a, t_node **b, int size, t_bench *bench)
{
	int	info[3];
	int	original;

	if (size <= 0)
		return ;
	if (size == 1)
	{
		ft_pa(a, b, 0, bench);
		return ;
	}
	if (size == 2)
		return (sort_two_b(a, b, bench));
	original = size;
	info[0] = size;
	partition_b(a, b, info, bench);
	restore_b(b, info[2], bench);
	quick_sort_a(a, b, info[1], bench);
	quick_sort_b(a, b, original - info[1], bench);
}
