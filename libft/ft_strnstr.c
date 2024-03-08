/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mualkhid <mualkhid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 11:06:51 by mualkhid          #+#    #+#             */
/*   Updated: 2024/03/04 11:06:52 by mualkhid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	needle_len;

	needle_len = ft_strlen(needle);
	if (len == 0 && haystack == 0)
	{
		return (NULL);
	}
	if (needle_len == '\0')
	{
		return ((char *)haystack);
	}
	while (*haystack && len >= needle_len)
	{
		if (*haystack == *needle && ft_strncmp(haystack, needle,
				needle_len) == 0)
		{
			return ((char *)haystack);
		}
		haystack++;
		len--;
	}
	return (NULL);
}
