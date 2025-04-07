/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings_enemies.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lviravon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:22:23 by lviravon          #+#    #+#             */
/*   Updated: 2025/02/18 18:54:34 by lviravon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	aff_enemis(t_init init, t_images *text, char **map)
{
	int		j;
	int		i;

	j = 0;
	text->enm.pos_x = 0;
	while (map[j])
	{
		i = 0;
		text->enm.pos_y = 0;
		while (map[j][i])
		{
			if (map[j][i] == 'e')
				mlx_put_image_to_window(init.mlx, init.win, text->enm.img[0],
					text->enm.pos_y, text->enm.pos_x);
			i++;
			text->enm.pos_y += 64;
		}
		j++;
		text->enm.pos_x += 64;
	}
}

void	aff_enemis2(t_init init, t_images *text, char **map)
{
	int		j;
	int		i;

	j = 0;
	text->enm.pos_x = 0;
	while (map[j])
	{
		i = 0;
		text->enm.pos_y = 0;
		while (map[j][i])
		{
			if (map[j][i] == 'e')
				mlx_put_image_to_window(init.mlx, init.win, text->enm.img[1],
					text->enm.pos_y, text->enm.pos_x);
			i++;
			text->enm.pos_y += 64;
		}
		j++;
		text->enm.pos_x += 64;
	}
}
