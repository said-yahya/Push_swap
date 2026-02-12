/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpolat <edpolat@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 15:40:06 by edpolat           #+#    #+#             */
/*   Updated: 2026/01/21 17:59:49 by edpolat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	j;
	size_t	ld;
	size_t	ls;

	ld = 0;
	while (ld < size && dest[ld] != 0)
		ld++;
	ls = ft_strlen(src);
	if (size == ld)
		return (size + ls);
	j = 0;
	while (ld + j < size - 1 && src[j] != 0)
	{
		dest[ld + j] = src[j];
		j++;
	}
	if (ld + j < size)
		dest[ld + j] = '\0';
	return (ld + ls);
}
