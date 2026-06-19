/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_quick_sort.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: butanis <butanis@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 21:14:48 by butanis           #+#    #+#             */
/*   Updated: 2026/05/06 17:06:22 by butanis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	complex_sort_three(t_node **a, t_bench *bench)
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

static void	complex_sort_five(t_node **a, t_node **b, t_bench *bench)
{
	move_min_to_top(a, bench);
	ft_pb(a, b, 0, bench);
	move_min_to_top(a, bench);
	ft_pb(a, b, 0, bench);
	complex_sort_three(a, bench);
	ft_pa(a, b, 0, bench);
	ft_pa(a, b, 0, bench);
}

void	complex_quick_sort(t_node **a, t_node **b, t_bench *bench)
{
	int	size;

	size = stack_size(*a);
	if (size <= 1 || is_sorted(*a))
		return ;
	if (size == 2)
		return (sort_two_a(a, bench));
	if (size == 3)
		return (complex_sort_three(a, bench));
	if (size == 4)
		return (sort_4(a, b, bench));
	if (size == 5)
		return (complex_sort_five(a, b, bench));
	quick_sort_a(a, b, size, bench);
}
