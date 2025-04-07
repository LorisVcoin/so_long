/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lviravon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 14:06:13 by lviravon          #+#    #+#             */
/*   Updated: 2024/10/16 18:59:33 by lviravon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_empty_string(void)
{
	char	*str;

	str = malloc(1);
	if (!str)
		return (0);
	str[0] = '\0';
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	size_max;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (ft_strlen((char *)s) < start)
		return (ft_empty_string());
	size_max = len;
	if (ft_strlen(&((char *)s)[start]) <= len)
		size_max = ft_strlen(&((char *)s)[start]);
	str = malloc(sizeof(char) * size_max + 1);
	if (!str)
		return (0);
	while (i < size_max)
	{
		str[i] = ((char *)s)[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
