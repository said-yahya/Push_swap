/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpolat <edpolat@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 17:09:55 by edpolat           #+#    #+#             */
/*   Updated: 2026/01/17 17:26:51 by edpolat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && s1[i] != 0 && s2[i] != 0 && s1[i] == s2[i])
		i++;
	if (n == 0 || i == n)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
