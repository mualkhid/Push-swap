/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mualkhid <mualkhid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 11:02:57 by mualkhid          #+#    #+#             */
/*   Updated: 2024/03/04 11:02:57 by mualkhid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	if (size != 0 && count > UINT_MAX / size)
		return (NULL);
	ptr = (void *)malloc(count * size);
	if (ptr == NULL)
		return (free(ptr), NULL);
	ft_bzero(ptr, (count * size));
	return (ptr);
}
