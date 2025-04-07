/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_settings.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lviravon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:24:44 by lviravon          #+#    #+#             */
/*   Updated: 2025/02/13 18:07:36 by lviravon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	move_utils(int *direction, int operator, int *index)
{
	if (operator == '+')
	{
		(*direction) += 64;
		return ((*index)++);
	}
	else if (operator == '-')
	{
		(*direction) -= 64;
		return ((*index)--);
	}
	return (*direction);
}
