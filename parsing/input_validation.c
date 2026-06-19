/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: butanis <butanis@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 14:25:41 by busetanis         #+#    #+#             */
/*   Updated: 2026/05/03 16:37:41 by butanis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	validation_number(char *string)
{
	int	index;

	index = 0;
	if (!string || !string[0])
		return (0);
	if (string[index] == '+' || string[index] == '-')
		index++;
	if (!string[index])
		return (0);
	while (string[index])
	{
		if (string[index] < '0' || string[index] > '9')
			return (0);
		index++;
	}
	return (1);
}

long	ft_atol(const char *str)
{
	int		index;
	int		sign;
	long	result;

	index = 0;
	sign = 1;
	result = 0;
	if (str[index] == '+' || str[index] == '-')
	{
		if (str[index] == '-')
			sign = -1;
		index++;
	}
	while (str[index])
	{
		result = result * 10 + (str[index] - '0');
		index++;
	}
	return (result * sign);
}

int	validation_duplicate(t_node *stack, int value)
{
	while (stack)
	{
		if (stack->value == value)
			return (1);
		stack = stack->next;
	}
	return (0);
}
