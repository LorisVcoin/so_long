/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lviravon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 14:12:39 by lviravon          #+#    #+#             */
/*   Updated: 2024/10/16 18:53:47 by lviravon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if ((!big && !len) || (!little && !len))
		return (NULL);
	if (big == little)
		return ((char *)big);
	if (little[0] == '\0')
		return ((char *)big);
	i = 0;
	j = ft_strlen(((char *)little));
	while (big[i])
	{
		if (i + j <= len && ft_strncmp(&big[i], little, j) == 0)
			return (&((char *)big)[i]);
		i++;
	}
	return (NULL);
}
