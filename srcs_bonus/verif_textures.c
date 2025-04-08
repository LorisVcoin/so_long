/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lviravon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:39:13 by lviravon          #+#    #+#             */
/*   Updated: 2025/03/04 14:40:31 by lviravon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

static int	no_null_img_2(t_images *img)
{
	if (img->p.img[0] == NULL)
		return (-1);
	if (img->p.img[1] == NULL)
		return (-1);
	if (img->enm.img[0] == NULL)
		return (-1);
	if (img->enm.img[1] == NULL)
		return (-1);
	if (img->c.img == NULL)
		return (-1);
	if (img->e.img == NULL)
		return (-1);
	return (0);
}

int	no_null_img(t_images *img)
{
	if (img->e2.img == NULL)
		return (-1);
	if (img->mel.img == NULL)
		return (-1);
	if (img->g.img == NULL)
		return (-1);
	if (img->w.img == NULL)
		return (-1);
	if (img->c.img == NULL)
		return (-1);
	if (img->c2.img == NULL)
		return (-1);
	if (img->c3.img == NULL)
		return (-1);
	return (no_null_img_2(img));
}

static int	init_img_2(t_images *img, t_init *init)
{
	img->e.img = mlx_new_image_from_file(init->mlx, "png_bonus/exit.png",
			&img->e.pos_x, &img->e.pos_y);
	img->mel.img = mlx_new_image_from_file(init->mlx, "png_bonus/Melik.png",
			&img->mel.pos_x, &img->mel.pos_y);
	img->e2.img = mlx_new_image_from_file(init->mlx, "png_bonus/exit2.png",
			&img->e2.pos_x, &img->e2.pos_y);
	img->g.img = mlx_new_image_from_file(init->mlx, "png_bonus/ground.png",
			&img->g.pos_x, &img->g.pos_y);
	img->w.img = mlx_new_image_from_file(init->mlx, "png_bonus/wall.png",
			&img->w.pos_x, &img->w.pos_y);
	img->enm.img[0] = mlx_new_image_from_file(init->mlx, "png_bonus/enemis.png",
			&img->w.pos_x, &img->w.pos_y);
	img->enm.img[1] = mlx_new_image_from_file(init->mlx,
			"png_bonus/enemis2.png", &img->w.pos_x, &img->w.pos_y);
	if (no_null_img(img) == -1)
		return (-1);
	return (0);
}

int	init_img(t_images *img, t_init *init)
{
	img->p.img[0] = mlx_new_image_from_file(init->mlx, "png_bonus/perso.png",
			&img->p.pos_x, &img->p.pos_y);
	img->p.img[1] = mlx_new_image_from_file(init->mlx, "png_bonus/perso2.png",
			&img->p.pos_x, &img->p.pos_y);
	img->c.img = mlx_new_image_from_file(init->mlx, "png_bonus/money.png",
			&img->c.pos_x, &img->c.pos_y);
	img->c2.img = mlx_new_image_from_file(init->mlx, "png_bonus/money2.png",
			&img->c2.pos_x, &img->c2.pos_y);
	img->c3.img = mlx_new_image_from_file(init->mlx, "png_bonus/money3.png",
			&img->c3.pos_x, &img->c3.pos_y);
	return (init_img_2(img, init));
}
