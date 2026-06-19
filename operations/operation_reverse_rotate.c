/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_reverse_rotate.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: butanis <butanis@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 15:46:23 by butanis           #+#    #+#             */
/*   Updated: 2026/04/28 18:09:30 by butanis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rra(t_node **a, int j, t_bench *bench)
{
	t_node	*prev;
	t_node	*last;

	if (!*a || !(*a)->next)
		return ;
	prev = NULL;
	last = *a;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *a;
	*a = last;
	if (j == 0)
	{
		write(1, "rra\n", 4);
		count_op(bench, "rra");
	}
}

void	ft_rrb(t_node **b, int j, t_bench *bench)
{
	t_node	*prev;
	t_node	*last;

	if (!*b || !(*b)->next)
		return ;
	prev = NULL;
	last = *b;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *b;
	*b = last;
	if (j == 0)
	{
		write(1, "rrb\n", 4);
		count_op(bench, "rrb");
	}
}

void	ft_rrr(t_node **a, t_node **b, int j, t_bench *bench)
{
	ft_rra(a, 1, bench);
	ft_rrb(b, 1, bench);
	if (j == 0)
	{
		write(1, "rrr\n", 4);
		count_op(bench, "rrr");
	}
}
