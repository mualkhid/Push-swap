/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mualkhid <mualkhid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 11:06:56 by mualkhid          #+#    #+#             */
/*   Updated: 2024/03/04 11:06:57 by mualkhid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*str;
	char	ch;

	str = (char *)s;
	ch = (int)c;
	i = ft_strlen(str);
	while (i >= 0)
	{
		if (str[i] == ch)
		{
			return (str + i);
		}
		i--;
	}
	return (NULL);
}
