/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lviravon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 15:58:56 by lviravon          #+#    #+#             */
/*   Updated: 2024/10/15 18:25:32 by lviravon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	j2;

	j2 = ft_strlen((char *)src);
	if (!dest && size == 0)
		return (j2);
	i = 0;
	j = ft_strlen(dest);
	if (size <= j)
		return (size + j2);
	while (i < (size - j - 1) && ((char *)src)[i] != '\0')
	{
		dest[j + i] = ((char *)src)[i];
		i++;
	}
	dest[j + i] = '\0';
	j += ft_strlen((char *)src);
	return (j);
}
