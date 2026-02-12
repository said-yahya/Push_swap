/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpolat <edpolat@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 16:18:00 by edpolat           #+#    #+#             */
/*   Updated: 2026/01/17 16:38:39 by edpolat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*a;
	size_t	j;

	if (size != 0 && nmemb > (size_t)-1 / size)
		return (NULL);
	j = nmemb * size;
	a = malloc((sizeof(char)) * j);
	if (!a)
		return (NULL);
	ft_bzero(a, j);
	return (a);
}
