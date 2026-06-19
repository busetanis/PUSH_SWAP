/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_quick_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: butanis <butanis@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 15:38:56 by butanis           #+#    #+#             */
/*   Updated: 2026/05/06 15:33:22 by butanis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	restore_a(t_node **a, int rotated, t_bench *bench)
{
	while (rotated > 0)
	{
		ft_rra(a, 0, bench);
		rotated--;
	}
}

static void	partition_a(t_node **a, t_node **b, int *info, t_bench *bench)
{
	int	pivot;

	pivot = complex_quick_pivot(*a, info[0]);
	info[1] = 0;
	info[2] = 0;
	while (info[0] > 0)
	{
		if ((*a)->value < pivot)
		{
			ft_pb(a, b, 0, bench);
			info[1]++;
		}
		else
		{
			ft_ra(a, 0, bench);
			info[2]++;
		}
		info[0]--;
	}
}

void	quick_sort_a(t_node **a, t_node **b, int size, t_bench *bench)
{
	int	info[3];
	int	original;

	if (size <= 1 || is_sorted(*a))
		return ;
	if (size == 2)
		return (sort_two_a(a, bench));
	original = size;
	info[0] = size;
	partition_a(a, b, info, bench);
	restore_a(a, info[2], bench);
	quick_sort_a(a, b, original - info[1], bench);
	quick_sort_b(a, b, info[1], bench);
}
