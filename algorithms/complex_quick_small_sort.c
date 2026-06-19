/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_quick_small_sort.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: butanis <butanis@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 14:44:23 by butanis           #+#    #+#             */
/*   Updated: 2026/05/03 16:09:43 by butanis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two_a(t_node **a, t_bench *bench)
{
	if (!a || !*a || !(*a)->next)
		return ;
	if ((*a)->value > (*a)->next->value)
		ft_sa(a, 0, bench);
}

void	sort_two_b(t_node **a, t_node **b, t_bench *bench)
{
	if (!b || !*b || !(*b)->next)
		return ;
	if ((*b)->value < (*b)->next->value)
		ft_sb(b, 0, bench);
	ft_pa(a, b, 0, bench);
	ft_pa(a, b, 0, bench);
}

static int	max_value(t_node *a)
{
	int	max;

	max = a->value;
	while (a)
	{
		if (a->value > max)
			max = a->value;
		a = a->next;
	}
	return (max);
}

void	sort_three_a(t_node **a, t_bench *bench)
{
	int	max;

	if (!a || !*a || !(*a)->next)
		return ;
	if (is_sorted(*a))
		return ;
	max = max_value(*a);
	if ((*a)->value == max)
		ft_ra(a, 0, bench);
	else if ((*a)->next->value == max)
		ft_rra(a, 0, bench);
	if ((*a)->value > (*a)->next->value)
		ft_sa(a, 0, bench);
}
