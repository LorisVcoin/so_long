/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lviravon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:43:39 by lviravon          #+#    #+#             */
/*   Updated: 2025/01/27 17:19:00 by lviravon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*read_line(char **save, int fd)
{
	char	*tmp;
	int		byte;

	byte = 1;
	tmp = ft_strdup(*save);
	if (!tmp)
		return (NULL);
	while (byte > 0)
	{
		free(*save);
		*save = ft_calloc(42 + 1, 1);
		byte = read(fd, *save, 42);
		if ((byte == 0 && **save == '\0' && *tmp == '\0') || byte == -1)
		{
			free(tmp);
			free(*save);
			return (*save = NULL);
		}
		tmp = ft_strjoin(tmp, *save);
		if ((ft_strchr(tmp, '\n')) || byte == 0)
			break ;
	}
	return (tmp);
}

char	*cut_occ(char *str, int c)
{
	int		i;
	int		size;
	char	*line;

	size = 0;
	while (str[size] != c)
		size++;
	size++;
	line = ft_calloc(size + 1, 1);
	if (!line)
		return (NULL);
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
		{
			line[i] = str[i];
			break ;
		}
		line[i] = str[i];
		i++;
	}
	return (line);
}

char	*get_next_n(char *line)
{
	int		i;
	char	*line2;
	int		j;

	i = 0;
	j = 0;
	if (!line)
		return (NULL);
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i] == '\n')
		i++;
	line2 = ft_calloc(i + 1, 1);
	if (!line)
		return (NULL);
	while (j < i)
	{
		line2[j] = line[j];
		j++;
	}
	free (line);
	return (line2);
}

char	*update_save(char *save)
{
	char	*str;
	int		i;

	i = 0;
	if (!save)
		return (NULL);
	if (ft_strchr(save, '\n'))
	{
		while (save[i] != '\n')
			i++;
		i++;
	}
	str = ft_strdup(&save[i]);
	free(save);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*line;

	if (42 <= 0 || fd < 0 || fd >= 1024)
		return (NULL);
	if (!save)
		save = ft_calloc(42 + 1, 1);
	if (!save)
		return (NULL);
	if (ft_strchr(save, '\n'))
	{
		line = cut_occ(save, '\n');
		if (!line)
		{
			free(save);
			save = NULL;
		}
		save = update_save(save);
		return (line);
	}
	line = read_line(&save, fd);
	line = get_next_n(line);
	save = update_save(save);
	return (line);
}
