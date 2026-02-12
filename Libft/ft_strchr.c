/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpolat <edpolat@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 12:07:13 by edpolat           #+#    #+#             */
/*   Updated: 2026/01/21 20:03:06 by edpolat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	j;

	j = 0;
	while (s[j] != '\0')
	{
		if (s[j] == (char)c)
			return ((char *)&s[j]);
		j++;
	}
	if ((char)c == '\0')
		return ((char *)&s[j]);
	return (NULL);
}
