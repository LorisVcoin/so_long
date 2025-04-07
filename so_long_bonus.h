/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lviravon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:06:21 by lviravon          #+#    #+#             */
/*   Updated: 2025/03/04 17:46:50 by lviravon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "libft/libft.h"
# include "MacroLibX/includes/mlx.h"
# include "MacroLibX/includes/mlx_extended.h"
# include <sys/stat.h>
# include <time.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

char		**ft_get_map(int fd);
void		free_2d(char **ptr);
int			parse_map(char *av, int fd);
void		flood_fill2(char **map);
void		flood_fill(char **pixel, int j, int i);
int			ft_verif_map(char **map, int i, int j);
int			last_verif(char	**map);
int			is_rectange(char **map);
int			verif_map_size(char *av);
int			verif_file(char *av);
int			ft_error(int ac, char **av);

typedef struct s_image
{
	int			y;
	int			x;
	int			pos_x;
	int			pos_y;
	mlx_image	img;
}	t_image;

typedef struct s_player
{
	int			choose;
	int			y;
	int			x;
	int			pos_x;
	int			pos_y;
	mlx_context	mlx;
	mlx_image	img[2];
}	t_player;

typedef struct s_enemis
{
	int			choose;
	int			tab[2];
	int			y;
	int			x;
	int			pos_x;
	int			pos_y;
	mlx_context	mlx;
	mlx_image	img[2];
}	t_enemis;

typedef struct s_move
{
	int	up;
	int	right;
}	t_move;

typedef struct s_images
{
	t_image		w;
	t_image		c;
	t_image		c2;
	t_image		c3;
	t_image		e;
	t_image		e2;
	t_image		mel;
	t_image		g;
	t_enemis	enm;
	t_player	p;
}	t_images;

typedef struct s_init
{
	char					**map;
	mlx_context				mlx;
	mlx_window				win;
	mlx_window_create_info	info;
}	t_init;

typedef struct mlx_data
{
	t_init		init;
	t_images	img;
	t_move		m;
	int			fd;
}	t_data;

int			just_one_collectible(char **map);
int			init_img(t_images *img, t_init *init);
int			check_map_is_fine(char **map);
void		init_all(int fd, t_data *data);
void		init_map(t_init mlx, int fd, t_images *textures, int i);
void		aff_melik(t_init init, t_images *text);
void		aff_wall(t_init init, t_images *text, char **map);
void		aff_ground(t_init init, t_images *text, char **map);
void		aff_collect(t_init init, t_images *text, char **map);
void		aff_collect2(t_init init, t_images *text, char **map);
void		aff_collect3(t_init init, t_images *text, char **map);
void		aff_exit(t_init init, t_images *text, char **map);
void		aff_exit2(t_init init, t_images *text, char **map);
void		aff_player(t_init init, t_images *text, t_move *move);
void		aff_player2(t_init init, t_images *text, t_move *move);
void		aff_enemis(t_init init, t_images *text, char **map);
void		aff_enemis2(t_init init, t_images *text, char **map);
void		init_window(t_init *init);
void		destroy(t_init *init, t_images *textures);
int			is_valid_textures(void);
void		key_hook(int key, void *param);
void		mouse_hook(int event, void *param);
void		player_move(int key, void *param);
int			move_utils(int *direction, int operator, int *index);
void		loop_hook(void *param);
void		replace_map(t_data *data);
int			*get_player(t_init init);

#endif
