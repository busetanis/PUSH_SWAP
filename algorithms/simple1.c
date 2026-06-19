/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: butanis <butanis@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 15:43:44 by butanis           #+#    #+#             */
/*   Updated: 2026/05/03 16:21:33 by butanis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_5(t_node **a, t_node **b, t_bench *bench)
{
	if (!a || !*a || is_sorted(*a))
		return ;
	while (stack_size(*a) > 3)
	{
		move_min_to_top(a, bench);
		ft_pb(a, b, 0, bench);
	}
	sort_3(a, bench);
	while (*b)
		ft_pa(a, b, 0, bench);
}

void	simple_sort(t_node **a, t_node **b, t_bench *bench)
{
	if (!a || !*a || is_sorted(*a))
		return ;
	if (stack_size(*a) == 2)
		sort_3(a, bench);
	else if (stack_size(*a) == 3)
		sort_3(a, bench);
	else if (stack_size(*a) == 4)
		sort_4(a, b, bench);
	else if (stack_size(*a) == 5)
		sort_5(a, b, bench);
	else
	{
		while (stack_size(*a) > 3)
		{
			move_min_to_top(a, bench);
			ft_pb(a, b, 0, bench);
		}
		sort_3(a, bench);
		while (*b)
			ft_pa(a, b, 0, bench);
	}
}
