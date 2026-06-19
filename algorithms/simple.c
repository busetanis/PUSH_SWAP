/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: butanis <butanis@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 16:04:32 by butanis           #+#    #+#             */
/*   Updated: 2026/05/03 16:20:08 by butanis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min_position(t_node **stack)
{
	t_node	*temp;
	int		min;
	int		pos;
	int		min_pos;

	temp = *stack;
	min = temp->value;
	pos = 0;
	min_pos = 0;
	while (temp)
	{
		if (temp->value < min)
		{
			min = temp->value;
			min_pos = pos;
		}
		temp = temp->next;
		pos++;
	}
	return (min_pos);
}

void	move_min_to_top(t_node **a, t_bench *bench)
{
	int	min_pos;
	int	size;

	min_pos = get_min_position(a);
	size = stack_size(*a);
	if (min_pos <= size / 2)
	{
		while (min_pos > 0)
		{
			ft_ra(a, 0, bench);
			min_pos--;
		}
	}
	else
	{
		while (min_pos < size)
		{
			ft_rra(a, 0, bench);
			min_pos++;
		}
	}
}

void	sort_3(t_node **a, t_bench *bench)
{
	int		highest;
	t_node	*temp;

	if (!a || !*a || !(*a)->next || is_sorted(*a))
		return ;
	highest = (*a)->value;
	temp = *a;
	while (temp)
	{
		if (temp->value > highest)
			highest = temp->value;
		temp = temp->next;
	}
	if ((*a)->value == highest)
		ft_ra(a, 0, bench);
	else if ((*a)->next->value == highest)
		ft_rra(a, 0, bench);
	if ((*a)->value > (*a)->next->value)
		ft_sa(a, 0, bench);
}

void	sort_4(t_node **a, t_node **b, t_bench *bench)
{
	int	min_pos;

	if (!a || !*a || is_sorted(*a))
		return ;
	min_pos = get_min_position(a);
	if (min_pos == 1)
		ft_ra(a, 0, bench);
	else if (min_pos == 2)
	{
		ft_ra(a, 0, bench);
		ft_ra(a, 0, bench);
	}
	else if (min_pos == 3)
		ft_rra(a, 0, bench);
	ft_pb(a, b, 0, bench);
	sort_3(a, bench);
	ft_pa(a, b, 0, bench);
}
