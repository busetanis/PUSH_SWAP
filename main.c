/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: butanis <butanis@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 16:43:40 by butanis           #+#    #+#             */
/*   Updated: 2026/05/03 16:44:08 by butanis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*get_strategy_flag(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (is_strategy_flag(av[i]))
			return (av[i]);
		i++;
	}
	return (NULL);
}

static int	has_bench(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (is_bench_flag(av[i]))
			return (1);
		i++;
	}
	return (0);
}

static void	set_bench_info(t_bench *bench, char *flag)
{
	if (!flag || flag[2] == 'a')
	{
		bench->strategy = "Adaptive";
		bench->complexity = "adaptive";
	}
	else if (flag[2] == 's')
	{
		bench->strategy = "Simple";
		bench->complexity = "O(n^2)";
	}
	else if (flag[2] == 'm')
	{
		bench->strategy = "Medium";
		bench->complexity = "O(n√n)";
	}
	else if (flag[2] == 'c')
	{
		bench->strategy = "Complex";
		bench->complexity = "O(n log n)";
	}
}

int	main(int ac, char **av)
{
	t_node	*a;
	t_node	*b;
	t_bench	bench;
	char	*flag;
	int		start;

	a = NULL;
	b = NULL;
	if (ac == 1)
		return (0);
	init_bench(&bench);
	bench.enabled = has_bench(ac, av);
	flag = get_strategy_flag(ac, av);
	start = get_start_index(ac, av);
	if (start >= ac)
		return (0);
	validation_args_from_index(ac, av, &a, start);
	bench.disorder = compute_disorder(a);
	set_bench_info(&bench, flag);
	if (!is_sorted(a))
		run_strategy(flag, &a, &b, &bench);
	print_bench(&bench);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
