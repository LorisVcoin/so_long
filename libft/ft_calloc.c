/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lviravon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 18:52:57 by lviravon          #+#    #+#             */
/*   Updated: 2024/10/17 16:35:34 by lviravon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t element, size_t size)
{
	void	*tab;
	size_t	i;
	size_t	size_max;

	size_max = -1;
	i = 0;
	if (element != 0 && size > size_max / element)
		return (malloc(0));
	tab = malloc(sizeof(char) * (element * size));
	if (tab == NULL)
		return (0);
	while (i != (size * element))
	{
		((char *)tab)[i] = 0;
		i++;
	}
	return (tab);
}
