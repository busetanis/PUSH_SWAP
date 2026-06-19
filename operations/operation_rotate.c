/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: butanis <butanis@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 15:34:30 by butanis           #+#    #+#             */
/*   Updated: 2026/04/28 18:09:17 by butanis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_node **a, int j, t_bench *bench)
{
	t_node	*first;
	t_node	*last;

	if (!*a || !(*a)->next)
		return ;
	first = *a;
	last = *a;
	while (last->next)
		last = last->next;
	*a = first->next;
	first->next = NULL;
	last->next = first;
	if (j == 0)
	{
		write(1, "ra\n", 3);
		count_op(bench, "ra");
	}
}

void	ft_rb(t_node **b, int j, t_bench *bench)
{
	t_node	*first;
	t_node	*last;

	if (!*b || !(*b)->next)
		return ;
	first = *b;
	last = *b;
	while (last->next)
		last = last->next;
	*b = first->next;
	first->next = NULL;
	last->next = first;
	if (j == 0)
	{
		write(1, "rb\n", 3);
		count_op(bench, "rb");
	}
}

void	ft_rr(t_node **a, t_node **b, int j, t_bench *bench)
{
	ft_ra(a, 1, bench);
	ft_rb(b, 1, bench);
	if (j == 0)
	{
		write(1, "rr\n", 3);
		count_op(bench, "rr");
	}
}
