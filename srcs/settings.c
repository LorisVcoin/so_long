/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lviravon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:58:33 by lviravon          #+#    #+#             */
/*   Updated: 2025/02/11 17:20:16 by lviravon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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
	init_map(data->init, data->fd, &data->img, &data->m);
	if (i < 30)
		aff_player(data->init, &data->img, &data->m);
	if (i >= 30)
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
