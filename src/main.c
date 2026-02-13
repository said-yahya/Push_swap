/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpolat <edpolat@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 01:06:05 by edpolat           #+#    #+#             */
/*   Updated: 2026/02/13 19:17:55 by edpolat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
Maindeki amacımız:
-Argüman var mı kontrol et
-Stack’leri initialize et
-Input’u parse et
-Hata kontrolü yap (invalid, duplicate vs.)
-İndex ata
-Eğer zaten sorted ise çık
-Sort algoritmasını çağır

ihtiyacım olacak helpers'lar:
-init_stack ----->Stack’leri initialize et
-parse_input
-error_exit
-check_duplicate ------> aynı sayı iki defa verildiyse add_number_to_stack içinde yakalamak için lazım
-assign_index
-is_sorted
-sort_stack
-free_stac
*/
#include "push_swap.h"

int main(int ac, char **av)
{
	int i;
	int j;
	char **temp_args;
	t_stack *stack;
	t_control ctrl;
	i = 1;

	init_control(&ctrl); // Default: mode = 0, bench = 0
	if (ac == 1)
		return (0);
	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (0);
	while (i < ac)
	{
		temp_args = ft_split(av[i], ' ');
		if (!temp_args)
			return (0);
		j = 0;
		while (temp_args[j])
		{
			ft_addback(stack, ft_newnode(ft_atoi(temp_args[j])));
			if (!stack->top)
			{
				free_matrix(temp_args);
				return (0);
			}
			j++;
		}
		free_matrix(temp_args);
		i++;
	}
	return (0);
}

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack		*a;
	t_stack		*b;
	t_control	ctrl;
	float		disorder;

	a = (t_stack *)malloc(sizeof(t_stack));
	b = (t_stack *)malloc(sizeof(t_stack));
	if (!a || !b)
		return (1);
	init_stack(a);
	init_stack(b);
	init_control(&ctrl);
	if (ac < 2)
		return (0);
	if (!parse_and_fill_stack(&a, ac, av, &ctrl))
	{
		write(2, "Error\n", 6);
		free_stack(a);
		free_stack(b);
		return (1);
	}
	run_adaptive_strategy(a, b, &ctrl);
	free_stack(a);
	free_stack(b);
	return (0);
}
