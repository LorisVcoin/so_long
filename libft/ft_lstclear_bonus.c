/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lviravon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 11:50:53 by lviravon          #+#    #+#             */
/*   Updated: 2024/10/17 16:23:38 by lviravon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*lst_c;

	if (!lst || !del)
		return ;
	while ((*lst) != NULL)
	{
		lst_c = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = lst_c;
	}
}
