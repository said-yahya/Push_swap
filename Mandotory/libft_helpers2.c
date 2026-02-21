/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_helpers2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaikhuj <ysaikhuj@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 16:11:58 by ysaikhuj          #+#    #+#             */
/*   Updated: 2026/02/21 16:12:02 by ysaikhuj         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != 0)
	{
		i++;
	}
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*new;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	new = malloc(sizeof(char) *(len + 1));
	if (!new)
		return (NULL);
	while (i < len)
	{
		new[i] = s[start + i];
		i++;
	}
	new[i] = 0;
	return (new);
}

char	*ft_strdup(const char *s)
{
	size_t	i;
	size_t	j;
	char	*cpy;

	i = ft_strlen(s);
	cpy = malloc((sizeof(char)) * (i + 1));
	j = 0;
	if (!cpy)
		return (NULL);
	while (j < i)
	{
		cpy[j] = s[j];
		j++;
	}
	cpy[j] = 0;
	return (cpy);
}
