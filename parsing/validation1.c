/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: butanis <butanis@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 16:40:18 by butanis           #+#    #+#             */
/*   Updated: 2026/05/03 18:56:43 by butanis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	has_space(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			return (1);
		i++;
	}
	return (0);
}

void	validation_args_from_index(int ac, char **av, t_node **a, int start)
{
	int		index;
	char	**split;

	index = start;
	while (index < ac)
	{
		if (!is_any_flag(av[index]))
		{
			if (has_space(av[index]))
			{
				split = ft_split(av[index], ' ');
				if (!split)
					error_exit(a);
				if (!split[0])
					error_exit_split(a, split);
				add_split_values(a, split);
				free_split(split);
			}
			else
				add_value_to_stack(a, av[index]);
		}
		index++;
	}
}
