/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mualkhid <mualkhid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 11:09:37 by mualkhid          #+#    #+#             */
/*   Updated: 2024/03/31 12:22:24 by mualkhid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_words(char const *s, char c)
{
	int		count;
	bool	inside_word;

	count = 0;
	while (*s)
	{
		inside_word = false;
		while (*s == c)
			++s;
		while (*s != c && *s)
		{
			if (!inside_word)
			{
				++count;
				inside_word = true;
			}
			++s;
		}
	}
	return (count);
}

static char	*skip_delimiters(char *s, char c)
{
	while (*s && *s == c)
	{
		s++;
	}
	return (s);
}

static char	*copystr(const char *s, char c)
{
	size_t	i;
	char	*str;

	i = 0;
	while (s[i] && s[i] != c)
	{
		i++;
	}
	str = (char *)ft_calloc((i + 1), sizeof(char));
	if (!str)
	{
		return (free(str), NULL);
	}
	ft_memcpy(str, s, i);
	return (str);
}

void	ft_undoalloc(char **s, int i)
{
	while (i >= 0)
	{
		free(s[i]);
		i--;
	}
	free(s);
}

char	**split(char *s, char c)
{
	char	**split;
	int		count;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	count = count_words(s, c);
	split = (char **)malloc(sizeof(char *) * (count + 1));
	if (!split)
		return (free(split), NULL);
	while (i < count)
	{
		s = skip_delimiters(s, c);
		split[i] = copystr(s, c);
		if (!split[i])
		{
			ft_undoalloc(split, i);
			return (NULL);
		}
		s += ft_strlen(split[i]);
		i++;
	}
	split[i] = (NULL);
	return (split);
}
