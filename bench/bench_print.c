/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: butanis <butanis@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 16:25:20 by butanis           #+#    #+#             */
/*   Updated: 2026/05/03 16:26:43 by butanis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	putstr_err(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(2, &str[i], 1);
		i++;
	}
}

static void	putnbr_err(int n)
{
	long	nb;
	char	c;

	nb = n;
	if (nb < 0)
	{
		write(2, "-", 1);
		nb = -nb;
	}
	if (nb >= 10)
		putnbr_err(nb / 10);
	c = (nb % 10) + '0';
	write(2, &c, 1);
}

static void	put_double_percent(double value)
{
	int	whole;
	int	decimal;

	value = value * 100.0;
	whole = (int)value;
	decimal = (int)((value - whole) * 100);
	if (decimal < 0)
		decimal = -decimal;
	putnbr_err(whole);
	write(2, ".", 1);
	if (decimal < 10)
		write(2, "0", 1);
	putnbr_err(decimal);
	write(2, "%", 1);
}

static void	print_bench_ops(t_bench *bench)
{
	putstr_err("\n[bench] total_ops: ");
	putnbr_err(bench->total);
	putstr_err("\n[bench] sa: ");
	putnbr_err(bench->sa);
	putstr_err(" sb: ");
	putnbr_err(bench->sb);
	putstr_err(" ss: ");
	putnbr_err(bench->ss);
	putstr_err(" pa: ");
	putnbr_err(bench->pa);
	putstr_err(" pb: ");
	putnbr_err(bench->pb);
	putstr_err("\n[bench] ra: ");
	putnbr_err(bench->ra);
	putstr_err(" rb: ");
	putnbr_err(bench->rb);
	putstr_err(" rr: ");
	putnbr_err(bench->rr);
	putstr_err(" rra: ");
	putnbr_err(bench->rra);
	putstr_err(" rrb: ");
	putnbr_err(bench->rrb);
	putstr_err(" rrr: ");
	putnbr_err(bench->rrr);
	putstr_err("\n");
}

void	print_bench(t_bench *bench)
{
	if (!bench || !bench->enabled)
		return ;
	putstr_err("[bench] disorder: ");
	put_double_percent(bench->disorder);
	putstr_err("\n[bench] strategy: ");
	putstr_err(bench->strategy);
	putstr_err(" / ");
	putstr_err(bench->complexity);
	print_bench_ops(bench);
}
