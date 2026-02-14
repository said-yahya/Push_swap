/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpolat <edpolat@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 22:19:31 by edpolat           #+#    #+#             */
/*   Updated: 2026/01/31 11:06:43 by edpolat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*list;
	t_list	*node;
	t_list	*temp;

	if (!lst || !f || !del)
		return (NULL);
	list = NULL;
	while (lst)
	{
		temp = f(lst->content);
		node = ft_lstnew(temp);
		if (!node)
		{
			del(temp);
			ft_lstclear(&list, del);
			return (NULL);
		}
		ft_lstadd_back(&list, node);
		lst = lst->next;
	}
	return (list);
}

void	*add_one(void *x)
{
	int	*n;

	n = malloc(sizeof(int));
	*n = *(int *)x + 1;
	return (n);
}
