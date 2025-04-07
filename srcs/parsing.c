/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lviravon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 16:13:00 by lviravon          #+#    #+#             */
/*   Updated: 2025/03/06 14:44:49 by lviravon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	parse_map(char *av, int fd)
{
	char	**map;

	fd = open(av, O_RDONLY);
	if (fd == -1)
		return (-1);
	map = ft_get_map(fd);
	close(fd);
	if (!map)
		return (-1);
	if (just_one_collectible(map) == -1 || is_rectange(map) == -1
		|| ft_verif_map(map, 0, 0) == -1)
	{
		free_2d(map);
		return (-1);
	}
	flood_fill2(map);
	if (last_verif(map) == -1)
	{
		free_2d(map);
		return (-1);
	}
	free_2d(map);
	return (1);
}

int	ft_verif_map(char **map, int i, int j)
{
	while (map[j][i])
	{
		if (map[j][i] != '1')
			return (-1);
		i++;
	}
	i--;
	while (map[j])
	{
		if (map[j][0] != '1')
			return (-1);
		if (map[j][i] != '1')
			return (-1);
		j++;
	}
	i = 0;
	j--;
	while (map[j][i])
	{
		if (map[j][i] != '1')
			return (-1);
		i++;
	}
	return (0);
}

void	flood_fill2(char **map)
{
	int	i;
	int	j;

	j = 1;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] == 'P')
				flood_fill(map, j, i);
			i++;
		}
		j++;
	}
}

void	flood_fill(char **pixel, int j, int i)
{
	if (pixel[j][i] == '0' || pixel[j][i] == 'C'
			|| pixel[j][i] == 'E' || pixel[j][i] == 'P')
	{
		pixel[j][i] = '1';
		flood_fill(pixel, j - 1, i);
		flood_fill(pixel, j + 1, i);
		flood_fill(pixel, j, i + 1);
		flood_fill(pixel, j, i - 1);
	}
}

int	last_verif(char	**map)
{
	int	i;
	int	j;

	j = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] != '1' && map[j][i] != '0')
				return (-1);
			i++;
		}
		j++;
	}
	return (1);
}
