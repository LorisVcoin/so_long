/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lviravon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 15:48:19 by lviravon          #+#    #+#             */
/*   Updated: 2024/10/15 18:37:13 by lviravon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *str, int c)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = -1;
	while (str[i] != '\0')
	{
		if (str[i] == (unsigned char)c)
		{
			tmp = i;
		}
		i++;
	}
	if ((char)c == 0)
		return (&((char *)str)[i]);
	if (tmp >= 0)
		return (&((char *)str)[tmp]);
	else
		return (0);
}
