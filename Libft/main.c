/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpolat <edpolat@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 16:18:42 by edpolat           #+#    #+#             */
/*   Updated: 2026/01/23 20:04:46 by edpolat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>

int	main(void)
{
	char	a[] = "abcde";
	char	b[] = "abcde";

	ft_memmove(a + 2, a, 3);
	ft_memcpy(b + 2, b, 3);
	printf(" move : %s \n cpy : %s", a, b);
}
