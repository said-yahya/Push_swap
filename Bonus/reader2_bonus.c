/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_reader2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpolat <edpolat@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 16:12:52 by edpolat           #+#    #+#             */
/*   Updated: 2026/02/20 18:30:18 by edpolat          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

char	*ft_strjoin_f(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	*join;

	k = 0;
	if (!s1)
		return (ft_strdup(s2));
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
	join[k] = 0;
	return (free(s1), join);
}

char	*ft_strchr(char *s, int c)
{
	size_t	j;

	if (!s)
		return (NULL);
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
