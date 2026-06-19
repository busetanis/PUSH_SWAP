/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: butanis <butanis@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 15:16:00 by butanis           #+#    #+#             */
/*   Updated: 2026/04/28 18:09:02 by butanis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_node **a, int j, t_bench *bench)
{
	t_node	*first;
	t_node	*second;

	if (!*a || !(*a)->next)
		return ;
	first = *a;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*a = second;
	if (j == 0)
	{
		write(1, "sa\n", 3);
		count_op(bench, "sa");
	}
}

void	ft_sb(t_node **b, int j, t_bench *bench)
{
	t_node	*first;
	t_node	*second;

	if (!*b || !(*b)->next)
		return ;
	first = *b;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*b = second;
	if (j == 0)
	{
		write(1, "sb\n", 3);
		count_op(bench, "sb");
	}
}

void	ft_ss(t_node **a, t_node **b, int j, t_bench *bench)
{
	ft_sa(a, 1, bench);
	ft_sb(b, 1, bench);
	if (j == 0)
	{
		write(1, "ss\n", 3);
		count_op(bench, "ss");
	}
}
