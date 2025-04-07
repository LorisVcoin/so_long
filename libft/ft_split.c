/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lviravon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 17:14:57 by lviravon          #+#    #+#             */
/*   Updated: 2024/10/27 18:29:45 by lviravon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_count_str(char const *s, char c)
{
	unsigned int	i;
	unsigned int	count_str;
	unsigned int	j;

	i = 0;
	j = 0;
	count_str = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c && s[i + 1] != '\0' && s[i + 1] != c)
			count_str++;
		i++;
	}
	i = 0;
	while (s[i] != '\0')
	{
		if (s[j] == c)
			j++;
		i++;
	}
	if (i == j)
		return (0);
	return (count_str + 1);
}

static unsigned int	ft_len_str(char const *s, char c)
{
	unsigned int	len;

	len = 0;
	while (*s && *s == c)
		s++;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

static char	**ft_free_all(char **strs, unsigned int j)
{
	while (j != 0)
	{
		free(strs[j]);
		j--;
	}
	free(strs[j]);
	free(strs);
	return (0);
}

static char	**ft_split2(char **strs, const char *s, char c, unsigned int size)
{
	unsigned int	j;
	unsigned int	len;
	unsigned int	i;

	j = 0;
	while (j < size)
	{
		i = 0;
		len = ft_len_str(s, c);
		strs[j] = malloc(sizeof(char) * (len + 1));
		if (!strs[j])
			return (ft_free_all(strs, j));
		while (*s && *s == c)
			s++;
		while (*s != '\0' && *s != c)
		{
			strs[j][i] = *s;
			i++;
			s++;
		}
		strs[j][i] = '\0';
		j++;
	}
	return (strs);
}

char	**ft_split(char const *s, char c)
{
	unsigned int	size_strs;
	char			**strs;
	unsigned int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] && s[i] == c)
		i++;
	size_strs = ft_count_str(&((char *)s)[i], c);
	strs = malloc(sizeof(char *) * (size_strs + 1));
	if (!strs)
		return (NULL);
	strs = ft_split2(strs, &((char *)s)[i], c, size_strs);
	if (!strs)
		return (NULL);
	strs[size_strs] = NULL;
	return (strs);
}
