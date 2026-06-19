/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: butanis <butanis@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 16:23:09 by butanis           #+#    #+#             */
/*   Updated: 2026/05/03 16:25:07 by butanis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_strcmp_bench(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	is_bench_flag(char *str)
{
	if (!str)
		return (0);
	if (ft_strcmp_bench(str, "--bench") == 0)
		return (1);
	return (0);
}

void	init_bench(t_bench *bench)
{
	bench->enabled = 0;
	bench->total = 0;
	bench->sa = 0;
	bench->sb = 0;
	bench->ss = 0;
	bench->pa = 0;
	bench->pb = 0;
	bench->ra = 0;
	bench->rb = 0;
	bench->rr = 0;
	bench->rra = 0;
	bench->rrb = 0;
	bench->rrr = 0;
	bench->disorder = 0.0;
	bench->strategy = "Adaptive";
	bench->complexity = "adaptive";
}

void	count_op(t_bench *bench, char *op)
{
	if (!bench || !bench->enabled)
		return ;
	bench->total++;
	if (ft_strcmp_bench(op, "sa") == 0)
		bench->sa++;
	else if (ft_strcmp_bench(op, "sb") == 0)
		bench->sb++;
	else if (ft_strcmp_bench(op, "ss") == 0)
		bench->ss++;
	else if (ft_strcmp_bench(op, "pa") == 0)
		bench->pa++;
	else if (ft_strcmp_bench(op, "pb") == 0)
		bench->pb++;
	else if (ft_strcmp_bench(op, "ra") == 0)
		bench->ra++;
	else if (ft_strcmp_bench(op, "rb") == 0)
		bench->rb++;
	else if (ft_strcmp_bench(op, "rr") == 0)
		bench->rr++;
	else if (ft_strcmp_bench(op, "rra") == 0)
		bench->rra++;
	else if (ft_strcmp_bench(op, "rrb") == 0)
		bench->rrb++;
	else if (ft_strcmp_bench(op, "rrr") == 0)
		bench->rrr++;
}
