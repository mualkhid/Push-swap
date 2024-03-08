/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mualkhid <mualkhid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 11:08:11 by mualkhid          #+#    #+#             */
/*   Updated: 2024/03/08 16:55:39 by mualkhid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*read_from_fd(int fd, char *accumulated_str)
{
	char	*buffer;
	int		read_length;

	buffer = malloc((size_t)BUFFER_SIZE + 2 * sizeof(char));
	if (!buffer)
	{
		free(buffer);
		return (NULL);
	}
	read_length = 1;
	while (!find_character(accumulated_str, '\n') && read_length != 0)
	{
		read_length = read(fd, buffer, BUFFER_SIZE);
		if (read_length == -1)
		{
			free(buffer);
			free(accumulated_str);
			return (NULL);
		}
		buffer[read_length] = '\0';
		accumulated_str = join_strings(accumulated_str, buffer);
	}
	free(buffer);
	return (accumulated_str);
}

char	*extract_line_from_str(char *str)
{
	int		i;
	char	*line;

	i = 0;
	if (!str || !str[i])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (free(line),free(str), NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		line[i] = str[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char *skip_to_next_line(char *current_str)
{
    int i;
    int j;
    char *next_str;

    i = 0;
    while (current_str[i] != '\0' && current_str[i] != '\n')
        i++;
    if (current_str[i] == '\0')
        return free(current_str), NULL;
    next_str = malloc(sizeof(char) * (lenstr(current_str + i + 1) + 1));
    if (!next_str)
        return free(current_str), NULL;

    i++;
    j = 0;
    while (current_str[i])
        next_str[j++] = current_str[i++];

    next_str[j] = '\0';
    free(current_str);
    return next_str;
}


// char	*skip_to_next_line(char *current_str)
// {
// 	int		i;
// 	int		j;
// 	char	*next_str;

// 	i = 0;
// 	while (current_str[i] != '\0' && current_str[i] != '\n')
// 		i++;
// 	if (current_str[i] == '\0')
// 		return (free(current_str), NULL);
// 	next_str = malloc(sizeof(char) * ((lenstr(current_str) - i) + 1));
// 	if (!next_str)
// 		return (free(next_str), free(current_str), NULL);
// 	i++;
// 	j = 0;
// 	while (current_str[i])
// 		next_str[j++] = current_str[i++];
// 	next_str[j] = '\0';
// 	free(current_str);
// 	return (next_str);
// }

char	*get_next_line(int fd, char *line)
{
	static char	*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > 2147483647)
		return (NULL);
	buffer = read_from_fd(fd, buffer);
	if (!buffer)
	{
		free(buffer);
		return (NULL);
	}
	line = extract_line_from_str(buffer);
	buffer = skip_to_next_line(buffer);
	return (line);
}
