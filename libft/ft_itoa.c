/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lviravon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 15:11:03 by lviravon          #+#    #+#             */
/*   Updated: 2024/10/15 16:25:44 by lviravon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len_int(int n)
{
	int	i;

	i = 1;
	if (n < 0)
		i++;
	while (n / 10 != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static void	ft_itoa2(int n, int size, char *str)
{
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
		while (str[size] != '-')
		{
			size--;
			if (size != 0)
			{
				str[size] = (n % 10) + 48;
				n = n / 10;
			}
		}
	}
	else
	{
		while (size > 0)
		{
			size--;
			str[size] = (n % 10) + 48;
			n = n / 10;
		}
	}
}

char	*ft_itoa(int n)
{
	int		size;
	char	*str;

	size = ft_len_int(n);
	if (n == -2147483648)
	{
		str = ft_strdup("-2147483648");
		return (str);
	}
	str = malloc(sizeof(char) * size + 1);
	if (!str)
		return (0);
	str[size] = '\0';
	ft_itoa2(n, size, str);
	return (str);
}
