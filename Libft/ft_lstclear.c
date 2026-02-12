/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpolat <edpolat@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 21:50:34 by edpolat           #+#    #+#             */
/*   Updated: 2026/01/17 19:02:18 by edpolat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*clr;
	t_list	*temp;

	if (!lst || !del || !*lst)
		return ;
	clr = *lst;
	while (clr)
	{
		temp = clr->next;
		ft_lstdelone(clr, del);
		clr = temp;
	}
	*lst = NULL;
}
