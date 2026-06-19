/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_quick_pivot.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: butanis <butanis@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 21:23:03 by butanis           #+#    #+#             */
/*   Updated: 2026/05/03 16:07:33 by butanis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_array(int *arr, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - 1 - i)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

int	complex_quick_pivot(t_node *stack, int size)
{
	int	*arr;
	int	i;
	int	pivot;

	if (!stack || size <= 0)
		return (0);
	arr = malloc(sizeof(int) * size);
	if (!arr)
		return (stack->value);
	i = 0;
	while (stack && i < size)
	{
		arr[i] = stack->value;
		stack = stack->next;
		i++;
	}
	sort_array(arr, i);
	pivot = arr[i / 2];
	free(arr);
	return (pivot);
}
