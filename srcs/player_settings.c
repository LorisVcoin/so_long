/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_settings.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lviravon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:33:25 by lviravon          #+#    #+#             */
/*   Updated: 2025/02/11 17:20:22 by lviravon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move(int key, t_data *data, int *tab)
{
	static int	i = 0;
	static int	j = 0;

	if (key == 26 && data->init.map[tab[0] + j - 1][tab[1] + i] != '1')
	{
		data->m.up -= 64;
		return (j--);
	}
	if (key == 22 && data->init.map[tab[0] + j + 1][tab[1] + i] != '1')
	{
		data->m.up += 64;
		return (j++);
	}
	if (key == 4 && data->init.map[tab[0] + j][tab[1] + i - 1] != '1')
	{
		data->m.right -= 64;
		return (i--);
	}
	if (key == 7 && data->init.map[tab[0] + j][tab[1] + i + 1] != '1')
	{
		data->m.right += 64;
		return (i++);
	}
	return (-2147483648);
}

void	player_move(int key, void *param)
{
	t_data		*data;
	int			*tab;
	static int	count = 0;

	data = param;
	tab = get_player(data->init);
	if (move(key, data, tab) != -2147483648)
	{
		ft_putstr_fd("Your score is ", 1);
		ft_putnbr_fd(count++, 1);
		ft_putstr_fd("\n", 1);
	}
	replace_map(data);
	free(tab);
}

int	*get_player(t_init init)
{
	int	j;
	int	i;
	int	*tab;

	tab = malloc(sizeof(int *) * (2 + 1));
	j = 0;
	i = 0;
	while (init.map[j])
	{
		i = 0;
		while (init.map[j][i])
		{
			if (init.map[j][i] == 'P')
			{
				tab[0] = j;
				tab[1] = i;
				return (tab);
			}
			i++;
		}
		j++;
	}
	return (0);
}

void	aff_player(t_init init, t_images *text, t_move *move)
{
	int			*tab;

	tab = get_player(init);
	text->p.pos_y = tab[0] * 64;
	text->p.pos_x = tab[1] * 64;
	mlx_put_image_to_window(init.mlx, init.win, text->p.img[0],
		text->p.pos_x + move->right, text->p.pos_y + move->up);
	free(tab);
}

void	aff_player2(t_init init, t_images *text, t_move *move)
{
	int			*tab;

	tab = get_player(init);
	text->p.pos_y = tab[0] * 64;
	text->p.pos_x = tab[1] * 64;
	mlx_put_image_to_window(init.mlx, init.win, text->p.img[1],
		text->p.pos_x + move->right, text->p.pos_y + move->up);
	free(tab);
}
