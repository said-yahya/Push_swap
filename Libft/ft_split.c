/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpolat <edpolat@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 20:30:34 by edpolat           #+#    #+#             */
/*   Updated: 2026/01/22 11:12:37 by edpolat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	wordcount(char const *ptr, char c)
{
	size_t	i;
	size_t	k;

	k = 0;
	i = 0;
	if (!ptr)
		return (0);
	while (ptr[i])
	{
		if (ptr[i] != c && (i == 0 || ptr[i - 1] == c))
			k++;
		i++;
	}
	return (k);
}

static void	freeptr(char **ptr, size_t l)
{
	while (l > 0)
	{
		free(ptr[l]);
		l--;
	}
	free(ptr[0]);
	free(ptr);
}

static char	**fill_words(char **ptr, char const *s, char c)
{
	size_t	a;
	size_t	b;
	size_t	l;

	a = 0;
	l = 0;
	while (s[a])
	{
		while (s[a] == c && s[a])
			a++;
		if (s[a])
		{
			b = 0;
			while (s[a + b] && s[a + b] != c)
				b++;
			ptr[l] = ft_substr(s, a, b);
			if (!ptr[l++])
				return (freeptr(ptr, l - 1), NULL);
			a += b;
		}
	}
	ptr[l] = NULL;
	return (ptr);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;

	if (!s)
		return (NULL);
	ptr = malloc(sizeof(char *) * (wordcount(s, c) + 1));
	if (!ptr)
		return (NULL);
	return (fill_words(ptr, s, c));
}
