/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lviravon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 18:35:23 by lviravon          #+#    #+#             */
/*   Updated: 2024/10/11 13:54:24 by lviravon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*str;
	int		size;
	int		i;

	i = 0;
	size = ft_strlen((char *)src);
	str = malloc(sizeof(char) * size + 1);
	if (str == NULL)
		return (0);
	while (((char *)src)[i] != '\0')
	{
		str[i] = ((char *)src)[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
