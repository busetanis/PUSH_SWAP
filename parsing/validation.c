/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: butanis <butanis@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 15:16:33 by busetanis         #+#    #+#             */
/*   Updated: 2026/05/03 19:42:45 by butanis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_value_to_stack(t_node **a, char *str)
{
	long	value;
	t_node	*new;

	if (!validation_number(str))
		error_exit(a);
	value = ft_atol(str);
	if (value < INT_MIN || value > INT_MAX)
		error_exit(a);
	if (validation_duplicate(*a, (int)value))
		error_exit(a);
	new = new_node((int)value);
	if (!new)
		error_exit(a);
	add_back(a, new);
}

void	validation_args(int arg_count, char **arg_value, t_node **a)
{
	int	index;

	index = 1;
	while (index < arg_count)
	{
		add_value_to_stack(a, arg_value[index]);
		index++;
	}
}

void	add_split_values(t_node **a, char **split)
{
	int		i;
	long	value;
	t_node	*new;

	i = 0;
	while (split[i])
	{
		if (!validation_number(split[i]))
			error_exit_split(a, split);
		value = ft_atol(split[i]);
		if (value < INT_MIN || value > INT_MAX)
			error_exit_split(a, split);
		if (validation_duplicate(*a, (int)value))
			error_exit_split(a, split);
		new = new_node((int)value);
		if (!new)
			error_exit_split(a, split);
		add_back(a, new);
		i++;
	}
}
