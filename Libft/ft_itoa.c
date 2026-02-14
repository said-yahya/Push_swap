/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpolat <edpolat@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 12:22:59 by edpolat           #+#    #+#             */
/*   Updated: 2026/01/23 15:47:00 by edpolat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_lencalc(int n)
{
	int	i;

	i = 0;
	if (n <= 0)
		i++;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*new;
	int		j;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	j = ft_lencalc(n);
	new = malloc(sizeof(char) * (j + 1));
	if (!new)
		return (NULL);
	if (n == 0)
		new[0] = '0';
	if (n < 0)
		new[0] = '-';
	if (n < 0)
		n = -n;
	new[j] = 0;
	while (n > 0)
	{
		new[j - 1] = n % 10 + 48;
		n = n / 10;
		j--;
	}
	return (new);
}
