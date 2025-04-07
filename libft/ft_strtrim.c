/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lviravon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 13:28:16 by lviravon          #+#    #+#             */
/*   Updated: 2024/10/16 19:34:27 by lviravon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	len;
	char	*str;

	if (s1 == NULL)
		return (NULL);
	start = 0;
	len = ft_strlen(s1) - 1;
	if (set != NULL)
	{
		while (s1[start] && ft_strchr(set, s1[start]))
			start++;
		while (len && ft_strchr(set, s1[len]))
			len--;
		str = ft_substr(s1, start, len - start + 1);
		return (str);
	}
	return (NULL);
}
