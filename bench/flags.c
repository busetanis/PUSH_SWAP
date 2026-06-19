/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: butanis <butanis@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 16:26:58 by butanis           #+#    #+#             */
/*   Updated: 2026/05/03 16:28:40 by butanis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	is_strategy_flag(char *str)
{
	if (!str)
		return (0);
	if (ft_strcmp(str, "--simple") == 0)
		return (1);
	if (ft_strcmp(str, "--medium") == 0)
		return (1);
	if (ft_strcmp(str, "--complex") == 0)
		return (1);
	if (ft_strcmp(str, "--adaptive") == 0)
		return (1);
	return (0);
}

int	is_any_flag(char *str)
{
	if (is_strategy_flag(str) || is_bench_flag(str))
		return (1);
	return (0);
}

int	get_start_index(int ac, char **av)
{
	int	i;
	int	strategy_count;
	int	bench_count;

	i = 1;
	strategy_count = 0;
	bench_count = 0;
	while (i < ac && is_any_flag(av[i]))
	{
		if (is_strategy_flag(av[i]))
			strategy_count++;
		if (is_bench_flag(av[i]))
			bench_count++;
		i++;
	}
	if (strategy_count > 1 || bench_count > 1)
		error_exit(NULL);
	return (i);
}

void	run_strategy(char *flag, t_node **a, t_node **b, t_bench *bench)
{
	if (!flag || ft_strcmp(flag, "--adaptive") == 0)
		sort_dispatcher(a, b, bench);
	else if (ft_strcmp(flag, "--simple") == 0)
		simple_sort(a, b, bench);
	else if (ft_strcmp(flag, "--medium") == 0)
		medium_chunk_sort(a, b, bench);
	else if (ft_strcmp(flag, "--complex") == 0)
		complex_quick_sort(a, b, bench);
}
