/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_disorder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: butanis <butanis@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 16:31:20 by butanis           #+#    #+#             */
/*   Updated: 2026/05/03 16:34:11 by butanis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	count_pairs(t_node *i, double *mistakes, double *total_pairs)
{
	t_node	*j;

	j = i->next;
	while (j)
	{
		(*total_pairs)++;
		if (i->value > j->value)
			(*mistakes)++;
		j = j->next;
	}
}

double	compute_disorder(t_node *a)
{
	t_node	*i;
	double	mistakes;
	double	total_pairs;

	mistakes = 0;
	total_pairs = 0;
	i = a;
	while (i)
	{
		count_pairs(i, &mistakes, &total_pairs);
		i = i->next;
	}
	if (total_pairs == 0)
		return (0.0);
	return (mistakes / total_pairs);
}
