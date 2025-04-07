/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lviravon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 15:57:41 by lviravon          #+#    #+#             */
/*   Updated: 2024/10/16 18:47:56 by lviravon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_memmove2(void *dest, const void *src, size_t size, size_t i)
{
	if (src < dest)
	{
		while (i > 0)
		{
			((char *)dest)[i] = ((char *)src)[i];
			i--;
		}
		((char *)dest)[i] = ((char *)src)[i];
	}
	else
	{
		i = 0;
		while (i != size)
		{
			((char *)dest)[i] = ((char *)src)[i];
			i++;
		}
	}
}

void	*ft_memmove(void *dest, const void *src, size_t size)
{
	size_t	i;

	if (src == NULL && dest == NULL)
		return (dest);
	if (size == 0)
		return (dest);
	i = size - 1;
	ft_memmove2(dest, src, size, i);
	return (dest);
}
