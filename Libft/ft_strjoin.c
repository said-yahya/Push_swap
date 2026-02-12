/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpolat <edpolat@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 17:42:27 by edpolat           #+#    #+#             */
/*   Updated: 2026/01/21 17:43:26 by edpolat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	*join;

	k = 0;
	if (!s1 || !s2)
		return (NULL);
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	join = malloc(sizeof(char) * (i + j + 1));
	if (!join)
		return (NULL);
	while (k < i + j)
	{
		while (k < i)
		{
			join[k] = s1[k];
			k++;
		}
		join[k] = s2[k - i];
		k++;
	}
	join [k] = 0;
	return (join);
}
