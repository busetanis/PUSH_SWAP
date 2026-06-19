/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_dispatcher.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: butanis <butanis@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 17:51:22 by butanis           #+#    #+#             */
/*   Updated: 2026/05/03 16:38:42 by butanis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set_adaptive_bench(t_bench *bench, char *strategy, char *complexity)
{
	if (bench)
	{
		bench->strategy = strategy;
		bench->complexity = complexity;
	}
}

void	sort_dispatcher(t_node **a, t_node **b, t_bench *bench)
{
	double	disorder;

	if (!a || !*a || is_sorted(*a))
		return ;
	disorder = compute_disorder(*a);
	if (disorder < 0.2)
	{
		set_adaptive_bench(bench, "Adaptive -> Simple", "O(n^2)");
		simple_sort(a, b, bench);
	}
	else if (disorder < 0.5)
	{
		set_adaptive_bench(bench, "Adaptive -> Medium", "O(n√n)");
		medium_chunk_sort(a, b, bench);
	}
	else
	{
		set_adaptive_bench(bench, "Adaptive -> Complex", "O(n log n)");
		complex_quick_sort(a, b, bench);
	}
}
