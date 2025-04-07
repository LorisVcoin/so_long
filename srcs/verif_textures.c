/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lviravon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:39:13 by lviravon          #+#    #+#             */
/*   Updated: 2025/03/04 14:33:59 by lviravon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	no_null_img(t_images *img)
{
	if (img->p.img[0] == NULL)
		return (-1);
	if (img->p.img[1] == NULL)
		return (-1);
	if (img->c.img == NULL)
		return (-1);
	if (img->e.img == NULL)
		return (-1);
	if (img->g.img == NULL)
		return (-1);
	if (img->w.img == NULL)
		return (-1);
	return (0);
}

int	init_img(t_images *img, t_init	*init)
{
	img->p.img[0] = mlx_new_image_from_file(init->mlx, "png/perso.png",
			&img->p.pos_x, &img->p.pos_y);
	img->p.img[1] = mlx_new_image_from_file(init->mlx, "png/perso2.png",
			&img->p.pos_x, &img->p.pos_y);
	img->c.img = mlx_new_image_from_file(init->mlx, "png/money.png",
			&img->c.pos_x, &img->c.pos_y);
	img->e.img = mlx_new_image_from_file(init->mlx, "png/exit.png",
			&img->e.pos_x, &img->e.pos_y);
	img->g.img = mlx_new_image_from_file(init->mlx, "png/ground.png",
			&img->g.pos_x, &img->g.pos_y);
	img->w.img = mlx_new_image_from_file(init->mlx, "png/wall.png",
			&img->w.pos_x, &img->w.pos_y);
	if (no_null_img(img) == -1)
		return (-1);
	return (0);
}
