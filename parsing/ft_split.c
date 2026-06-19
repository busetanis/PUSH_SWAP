/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: butanis <butanis@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 17:48:03 by butanis           #+#    #+#             */
/*   Updated: 2026/04/30 17:48:12 by butanis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_count_words(const char *s, char c)
{
	int	i;
	int	count;
	int	in_word;

	i = 0;
	count = 0;
	in_word = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			if (in_word == 0)
			{
				count++;
				in_word = 1;
			}
		}
		else
			in_word = 0;
		i++;
	}
	return (count);
}

static char	*ft_strdup_word(const char *s, int start, int end)
{
	char	*word;
	int		i;

	word = malloc(sizeof(char) * (end - start + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (start < end)
	{
		word[i] = s[start];
		i++;
		start++;
	}
	word[i] = '\0';
	return (word);
}

static void	ft_free_all(char **array, int size)
{
	while (size > 0)
		free(array[--size]);
	free(array);
}

static char	*get_word(const char *s, int *i, char c)
{
	int	start;

	while (s[*i] && s[*i] == c)
		(*i)++;
	start = *i;
	while (s[*i] && s[*i] != c)
		(*i)++;
	if (*i == start)
		return (NULL);
	return (ft_strdup_word(s, start, *i));
}

char	**ft_split(const char *s, char c)
{
	char	**res;
	int		i;
	int		j;
	int		words;

	if (!s)
		return (NULL);
	words = ft_count_words(s, c);
	res = malloc(sizeof(char *) * (words + 1));
	if (!res)
		return (NULL);
	i = 0;
	j = 0;
	while (j < words)
	{
		res[j] = get_word(s, &i, c);
		if (!res[j])
			return (ft_free_all(res, j), NULL);
		j++;
	}
	res[j] = NULL;
	return (res);
}
