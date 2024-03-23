/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mualkhid <mualkhid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 11:08:02 by mualkhid          #+#    #+#             */
/*   Updated: 2024/03/08 11:48:14 by mualkhid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	lenstr(const char *str)
{
	int	len;

	len = 0;
	while (str && str[len] != '\0')
		len++;
	return (len);
}

char	*find_character(const char *str, int character)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == (char)character)
			return ((char *)&str[i]);
		i++;
	}
	return (NULL);
}

char	*initialize_string(void)
{
	char	*new_str;

	new_str = (char *)malloc(sizeof(char));
	if (new_str)
		new_str[0] = '\0';
	return (new_str);
}

char	*join_strings(char *frst, char *secnd)
{
	int		i;
	int		j;
	char	*newstr;

	if (!frst)
		frst = initialize_string();
	if (!frst || !secnd)
		return (NULL);
	newstr = (char *)malloc(sizeof(char) * (lenstr(frst) + lenstr(secnd) + 1));
	if (!newstr)
		return (free(frst), NULL);
	i = 0;
	j = 0;
	while (frst[i])
	{
		newstr[i] = frst[i];
		i++;
	}
	while (secnd[j])
		newstr[i++] = secnd[j++];
	newstr[i] = '\0';
	free(frst);
	return (newstr);
}
