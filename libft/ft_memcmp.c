/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lviravon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 14:15:52 by lviravon          #+#    #+#             */
/*   Updated: 2024/10/10 16:00:45 by lviravon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *pnt1, const void *pnt2, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
		return (0);
	while (i < size - 1)
	{
		if (((char *)pnt1)[i] != ((char *)pnt2)[i])
			return (((unsigned char *)pnt1)[i] - ((unsigned char *)pnt2)[i]);
		i++;
	}
	return (((unsigned char *)pnt1)[i] - ((unsigned char *)pnt2)[i]);
}
