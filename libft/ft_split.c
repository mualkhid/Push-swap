/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mualkhid <mualkhid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 11:05:48 by mualkhid          #+#    #+#             */
/*   Updated: 2024/03/04 11:05:48 by mualkhid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wordcount(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			i++;
		}
		else
		{
			count++;
			while (s[i] && s[i] != c)
			{
				i++;
			}
		}
	}
	return (count);
}

static const char	*skip_delimiters(const char *s, char c)
{
	while (*s && *s == c)
	{
		s++;
	}
	return (s);
}

static char	*ft_copystr(char const *s, char c)
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
		return (NULL);
	}
	ft_memcpy(str, s, i);
	return (str);
}

static void	ft_undoalloc(char **s, int i)
{
	while (i >= 0)
	{
		free(s[i]);
		i--;
	}
	free(s);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		count;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	count = ft_wordcount(s, c);
	split = (char **)malloc(sizeof(char *) * (count + 1));
	if (!split)
		return (NULL);
	while (i < count)
	{
		s = skip_delimiters(s, c);
		split[i] = ft_copystr(s, c);
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
