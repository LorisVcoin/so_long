/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_settings.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lviravon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 19:55:40 by lviravon          #+#    #+#             */
/*   Updated: 2025/02/18 19:36:11 by lviravon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long_bonus.h"

void	replace_map(t_data *data)
{
	int	*tab;

	tab = get_player(data->init);
	if (data->init.map[tab[0] + (data->m.up / 64)]
		[tab[1] + (data->m.right / 64)] == 'C')
		data->init.map[tab[0] + (data->m.up / 64)]
		[tab[1] + (data->m.right / 64)] = '0';
	if (data->init.map[tab[0] + (data->m.up / 64)]
		[tab[1] + (data->m.right / 64)] == 'E'
		&& check_map_is_fine(data->init.map) != -1)
		mlx_loop_end(data->init.mlx);
	if (data->init.map[tab[0] + (data->m.up / 64)]
		[tab[1] + (data->m.right / 64)] == 'e')
	{
		ft_putstr_fd("Well then Melik. F*CKING LOOSER !\n", 1);
		mlx_loop_end(data->init.mlx);
	}
	free(tab);
}

void	aff_wall(t_init init, t_images *text, char **map)
{
	int		j;
	int		i;

	j = 0;
	text->w.pos_x = 0;
	while (map[j])
	{
		i = 0;
		text->w.pos_y = 0;
		while (map[j][i])
		{
			if (map[j][i] == '1')
				mlx_put_image_to_window(init.mlx, init.win, text->w.img,
					text->w.pos_y, text->w.pos_x);
			i++;
			text->w.pos_y += 64;
		}
		j++;
		text->w.pos_x += 64;
	}
}

void	aff_ground(t_init init, t_images *text, char **map)
{
	int		j;
	int		i;

	j = 0;
	text->g.pos_x = 0;
	while (map[j])
	{
		i = 0;
		text->g.pos_y = 0;
		while (map[j][i])
		{
			if (map[j][i] == '0' || map[j][i] == 'P'
					|| map[j][i] == 'C' || map[j][i] == 'E' || map[j][i] == 'e')
				mlx_put_image_to_window(init.mlx, init.win, text->g.img,
					text->g.pos_y, text->g.pos_x);
			i++;
			text->g.pos_y += 64;
		}
		j++;
		text->g.pos_x += 64;
	}
}

void	aff_exit(t_init init, t_images *text, char **map)
{
	int		j;
	int		i;

	j = 0;
	text->e.pos_x = 0;
	while (map[j])
	{
		i = 0;
		text->e.pos_y = 0;
		while (map[j][i])
		{
			if (map[j][i] == 'E')
				mlx_put_image_to_window(init.mlx, init.win, text->e.img,
					text->e.pos_y, text->e.pos_x);
			i++;
			text->e.pos_y += 64;
		}
		j++;
		text->e.pos_x += 64;
	}
}

void	aff_collect(t_init init, t_images *text, char **map)
{
	int		j;
	int		i;

	j = 0;
	text->c.pos_x = 0;
	while (map[j])
	{
		i = 0;
		text->c.pos_y = 0;
		while (map[j][i])
		{
			if (map[j][i] == 'C')
				mlx_put_image_to_window(init.mlx, init.win, text->c.img,
					text->c.pos_y, text->c.pos_x);
			i++;
			text->c.pos_y += 64;
		}
		j++;
		text->c.pos_x += 64;
	}
}
