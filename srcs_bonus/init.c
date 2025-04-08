/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lviravon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 16:29:17 by lviravon          #+#    #+#             */
/*   Updated: 2025/03/04 14:00:08 by lviravon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	init_all(int fd, t_data *data)
{
	data->init.map = ft_get_map(fd);
	data->m.up = 0;
	data->m.right = 0;
	data->fd = fd;
	data->init.info = (mlx_window_create_info){0};
	init_window(&data->init);
	if (init_img(&data->img, &data->init) == -1)
	{
		destroy(&data->init, &data->img);
		free_2d(data->init.map);
		close(fd);
		return ;
	}
	mlx_on_event(data->init.mlx, data->init.win, MLX_KEYDOWN,
		key_hook, data);
	mlx_on_event(data->init.mlx, data->init.win, MLX_KEYDOWN,
		player_move, data);
	mlx_on_event(data->init.mlx, data->init.win, MLX_WINDOW_EVENT,
		mouse_hook, data);
	mlx_add_loop_hook(data->init.mlx, loop_hook, data);
	mlx_loop(data->init.mlx);
	close(fd);
	free_2d(data->init.map);
	destroy(&data->init, &data->img);
}

void	init_window(t_init *init)
{
	init->mlx = mlx_init();
	mlx_set_fps_goal(init->mlx, 60);
	init->info.title = "The Melik game";
	init->info.width = 1920;
	init->info.height = 1080;
	init->win = mlx_new_window(init->mlx, &init->info);
}

void	init_map(t_init init, int fd, t_images *textures, int i)
{
	(void)fd;
	aff_wall(init, textures, init.map);
	aff_ground(init, textures, init.map);
	if (i <= 30)
		aff_enemis(init, textures, init.map);
	if (i > 30)
		aff_enemis2(init, textures, init.map);
	if (i <= 20)
		aff_collect(init, textures, init.map);
	if (i <= 40 && i > 20)
		aff_collect2(init, textures, init.map);
	if (i <= 60 && i > 40)
		aff_collect3(init, textures, init.map);
	aff_melik(init, textures);
}
