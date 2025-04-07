/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lviravon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 16:11:40 by lviravon          #+#    #+#             */
/*   Updated: 2025/03/06 14:54:49 by lviravon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	just_one_collectible(char **map)
{
	int	i;
	int	j;

	j = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] == 'C')
				return (0);
			i++;
		}
		j++;
	}
	return (-1);
}

int	verif_map_size(char *av)
{
	int		i;
	int		j;
	char	**map;
	int		fd;

	fd = open(av, O_RDONLY);
	map = ft_get_map(fd);
	if (!map)
		return (-1);
	j = 0;
	while (map[j])
	{
		if (j > 15)
			return (-1);
		j++;
	}
	i = 0;
	while (map[0][i])
	{
		if (i++ > 23)
			return (-1);
	}
	close(fd);
	free_2d(map);
	return (0);
}

int	is_rectange(char **map)
{
	int		j;
	size_t	tmp;

	j = 0;
	tmp = ft_strlen(map[j]);
	j++;
	while (map[j])
	{
		if (tmp != ft_strlen(map[j]))
			return (-1);
		j++;
	}
	return (1);
}

int	verif_file(char *av)
{
	int	i;

	i = ft_strlen(av);
	if (i == 4)
	{
		if (ft_strnstr(av, ".ber", 4))
			return (-1);
	}
	if (ft_strnstr(&av[i - 4], ".ber", 4))
		return (1);
	return (-1);
}

char	**ft_get_map(int fd)
{
	char	*tmp;
	char	*mapi;
	char	**map;
	int		j;

	j = 0;
	mapi = ft_strdup("");
	tmp = get_next_line(fd);
	while (tmp != NULL)
	{
		mapi = ft_strjoin(mapi, tmp);
		free(tmp);
		tmp = get_next_line(fd);
	}
	while (mapi[j])
	{
		j++;
		if (mapi[j] == '\n' && mapi[j + 1] == '\n')
			return (NULL);
	}
	map = ft_split(mapi, '\n');
	free(mapi);
	return (map);
}
