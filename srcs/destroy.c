/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lviravon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 19:37:36 by lviravon          #+#    #+#             */
/*   Updated: 2025/03/04 14:46:11 by lviravon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	destroy(t_init *init, t_images *textures)
{
	if (textures->w.img)
		mlx_destroy_image(init->mlx, textures->w.img);
	if (textures->c.img)
		mlx_destroy_image(init->mlx, textures->c.img);
	if (textures->g.img)
		mlx_destroy_image(init->mlx, textures->g.img);
	if (textures->e.img)
		mlx_destroy_image(init->mlx, textures->e.img);
	if (textures->p.img[0])
		mlx_destroy_image(init->mlx, textures->p.img[0]);
	if (textures->p.img[1])
		mlx_destroy_image(init->mlx, textures->p.img[1]);
	if (init->win)
		mlx_destroy_window(init->mlx, init->win);
	if (init->mlx)
		mlx_destroy_context(init->mlx);
	free_2d(init->map);
}
