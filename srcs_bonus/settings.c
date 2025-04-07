/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lviravon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:58:33 by lviravon          #+#    #+#             */
/*   Updated: 2025/02/18 19:31:33 by lviravon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	key_hook(int key, void *param)
{
	t_data		*data;

	data = param;
	if (key == 41)
		mlx_loop_end(data->init.mlx);
}

void	mouse_hook(int event, void *param)
{
	t_data		*data;

	data = param;
	if (event == 0)
		mlx_loop_end(data->init.mlx);
}

void	loop_hook(void *param)
{
	t_data		*data;
	mlx_color	color;
	static int	i = 1;

	i = (i + 1) % 60;
	data = (t_data *)param;
	color.rgba = 74165275;
	mlx_clear_window(data->init.mlx, data->init.win, color);
	init_map(data->init, data->fd, &data->img, i);
	if (check_map_is_fine(data->init.map) != 1)
		aff_exit(data->init, &data->img, data->init.map);
	if (check_map_is_fine(data->init.map) == 1)
		aff_exit2(data->init, &data->img, data->init.map);
	if (data->img.p.choose == 0)
		aff_player(data->init, &data->img, &data->m);
	if (data->img.p.choose == 1)
		aff_player2(data->init, &data->img, &data->m);
}

int	check_map_is_fine(char **map)
{
	int	j;
	int	i;

	j = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] == 'C')
				return (-1);
			i++;
		}
		j++;
	}
	return (1);
}
