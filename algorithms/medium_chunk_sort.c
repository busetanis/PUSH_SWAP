/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_chunk_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: butanis <butanis@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 15:41:38 by butanis           #+#    #+#             */
/*   Updated: 2026/05/05 20:40:36 by butanis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	index_stack(t_node **stack)
{
	t_node	*curr;
	t_node	*min_node;
	int		current_index;
	int		size;
	int		i;

	size = stack_size(*stack);
	current_index = 0;
	i = 0;
	while (i < size)
	{
		curr = *stack;
		min_node = NULL;
		while (curr)
		{
			if (curr->index == -1
				&& (!min_node || curr->value < min_node->value))
				min_node = curr;
			curr = curr->next;
		}
		if (min_node)
			min_node->index = current_index++;
		i++;
	}
}

void	push_chunks_to_b(t_node **a, t_node **b, int chunk_size,
		t_bench *bench)
{
	int	pushed;

	pushed = 0;
	while (*a)
	{
		if ((*a)->index <= pushed)
		{
			ft_pb(a, b, 0, bench);
			ft_rb(b, 0, bench);
			pushed++;
		}
		else if ((*a)->index <= pushed + chunk_size)
		{
			ft_pb(a, b, 0, bench);
			pushed++;
		}
		else
			ft_ra(a, 0, bench);
	}
}

int	get_max_position(t_node **b)
{
	t_node	*curr;
	int		max_index;
	int		max_pos;
	int		current_pos;

	curr = *b;
	max_index = -1;
	max_pos = 0;
	current_pos = 0;
	while (curr)
	{
		if (curr->index > max_index)
		{
			max_index = curr->index;
			max_pos = current_pos;
		}
		curr = curr->next;
		current_pos++;
	}
	return (max_pos);
}

void	pull_to_a(t_node **a, t_node **b, t_bench *bench)
{
	int	max_pos;
	int	size;

	while (*b)
	{
		size = stack_size(*b);
		max_pos = get_max_position(b);
		if (max_pos == 0)
			ft_pa(a, b, 0, bench);
		else if (max_pos <= size / 2)
			ft_rb(b, 0, bench);
		else
			ft_rrb(b, 0, bench);
	}
}

void	medium_chunk_sort(t_node **a, t_node **b, t_bench *bench)
{
	int	size;
	int	chunk_size;

	if (!a || !*a || is_sorted(*a))
		return ;
	size = stack_size(*a);
	if (size <= 5)
	{
		sort_small(a, b, bench);
		return ;
	}
	index_stack(a);
	chunk_size = (size / 20) + 10;
	push_chunks_to_b(a, b, chunk_size, bench);
	pull_to_a(a, b, bench);
}
