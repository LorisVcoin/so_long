/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_settings2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lviravon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 09:21:51 by lviravon          #+#    #+#             */
/*   Updated: 2025/02/13 16:06:03 by lviravon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	aff_exit2(t_init init, t_images *text, char **map)
{
	int		j;
	int		i;

	j = 0;
	text->e2.pos_x = 0;
	while (map[j])
	{
		i = 0;
		text->e2.pos_y = 0;
		while (map[j][i])
		{
			if (map[j][i] == 'E')
				mlx_put_image_to_window(init.mlx, init.win, text->e2.img,
					text->e2.pos_y, text->e2.pos_x);
			i++;
			text->e2.pos_y += 64;
		}
		j++;
		text->e2.pos_x += 64;
	}
}

void	aff_melik(t_init init, t_images *text)
{
	mlx_put_image_to_window(init.mlx, init.win, text->mel.img,
		1520, 10);
}

void	aff_collect2(t_init init, t_images *text, char **map)
{
	int		j;
	int		i;

	j = 0;
	text->c2.pos_x = 0;
	while (map[j])
	{
		i = 0;
		text->c2.pos_y = 0;
		while (map[j][i])
		{
			if (map[j][i] == 'C')
				mlx_put_image_to_window(init.mlx, init.win, text->c2.img,
					text->c2.pos_y, text->c2.pos_x);
			i++;
			text->c2.pos_y += 64;
		}
		j++;
		text->c2.pos_x += 64;
	}
}

void	aff_collect3(t_init init, t_images *text, char **map)
{
	int		j;
	int		i;

	j = 0;
	text->c3.pos_x = 0;
	while (map[j])
	{
		i = 0;
		text->c3.pos_y = 0;
		while (map[j][i])
		{
			if (map[j][i] == 'C')
				mlx_put_image_to_window(init.mlx, init.win, text->c3.img,
					text->c3.pos_y, text->c3.pos_x);
			i++;
			text->c3.pos_y += 64;
		}
		j++;
		text->c3.pos_x += 64;
	}
}
