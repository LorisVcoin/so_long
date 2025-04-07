/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lviravon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 16:18:59 by lviravon          #+#    #+#             */
/*   Updated: 2025/01/27 18:59:22 by lviravon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_strjoin2(char *str, char const *s1, char const *s2)
{
	size_t	i;
	size_t	i2;

	i = 0;
	i2 = 0;
	while (s1[i2] != '\0')
	{
		str[i] = ((char *)s1)[i2];
		i++;
		i2++;
	}
	i2 = 0;
	while (s2[i2] != '\0')
	{
		str[i + i2] = ((char *)s2)[i2];
		i2++;
	}
	str[i + i2] = '\0';
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	i2;
	size_t	max;

	if (!s1)
		return (NULL);
	max = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	i = 0;
	i2 = 0;
	str = malloc(sizeof(char) * max + 1);
	if (!str)
		return (0);
	ft_strjoin2(str, s1, s2);
	free((char *)s1);
	return (str);
}
