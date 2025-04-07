/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lviravon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:10:40 by lviravon          #+#    #+#             */
/*   Updated: 2025/03/04 14:34:40 by lviravon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	main(int ac, char **av)
{
	int		fd;
	t_data	data;

	if (ft_error(ac, av) == -1)
		return (-1);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (-1);
	init_all(fd, &data);
	close(fd);
}

int	ft_error(int ac, char **av)
{
	if (ac != 2)
	{
		ft_putstr_fd("Error : Invalid args (try with 1 arg)\n", 2);
		return (-1);
	}
	if (verif_file(av[1]) == -1)
	{
		ft_putstr_fd("Error : please try with .ber map\n", 2);
		return (-1);
	}
	if (parse_map(av[1], 0) == -1 || verif_map_size(av[1]) == -1)
	{
		ft_putstr_fd("Error : invalid map\n", 2);
		return (-1);
	}
	return (0);
}
