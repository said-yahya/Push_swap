/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpolat <edpolat@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 12:19:02 by edpolat           #+#    #+#             */
/*   Updated: 2026/01/21 18:52:11 by edpolat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*to;
	unsigned char	*from;
	size_t			i;

	if (!dest && !src)
		return (NULL);
	from = (unsigned char *)src;
	to = (unsigned char *)dest;
	i = 0;
	while (i < n)
	{
		to[i] = from[i];
		i++;
	}
	return (to);
}
