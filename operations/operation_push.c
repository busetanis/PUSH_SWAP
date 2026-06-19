/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: butanis <butanis@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 15:28:10 by butanis           #+#    #+#             */
/*   Updated: 2026/04/28 18:08:49 by butanis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pa(t_node **a, t_node **b, int j, t_bench *bench)
{
	t_node	*tmp;

	if (!*b)
		return ;
	tmp = *b;
	*b = (*b)->next;
	tmp->next = *a;
	*a = tmp;
	if (j == 0)
	{
		write(1, "pa\n", 3);
		count_op(bench, "pa");
	}
}

void	ft_pb(t_node **a, t_node **b, int j, t_bench *bench)
{
	t_node	*tmp;

	if (!*a)
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = *b;
	*b = tmp;
	if (j == 0)
	{
		write(1, "pb\n", 3);
		count_op(bench, "pb");
	}
}
