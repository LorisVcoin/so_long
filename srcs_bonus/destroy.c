/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lviravon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 19:37:36 by lviravon          #+#    #+#             */
/*   Updated: 2025/03/04 14:18:16 by lviravon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	__destroy(void *mlx, void *img)
{
	if (img != NULL)
		mlx_destroy_image(mlx, img);
}

void	destroy(t_init *init, t_images *textures)
{
	__destroy(init->mlx, textures->w.img);
	__destroy(init->mlx, textures->c.img);
	__destroy(init->mlx, textures->c2.img);
	__destroy(init->mlx, textures->c3.img);
	__destroy(init->mlx, textures->g.img);
	__destroy(init->mlx, textures->e.img);
	__destroy(init->mlx, textures->enm.img[0]);
	__destroy(init->mlx, textures->enm.img[1]);
	__destroy(init->mlx, textures->mel.img);
	__destroy(init->mlx, textures->e2.img);
	__destroy(init->mlx, textures->p.img[0]);
	__destroy(init->mlx, textures->p.img[1]);
	mlx_destroy_window(init->mlx, init->win);
	mlx_destroy_context(init->mlx);
}
