/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpolat <edpolat@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 01:06:05 by edpolat           #+#    #+#             */
/*   Updated: 2026/02/15 15:04:15 by edpolat          ###   ########.fr       */
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
-check_duplicate ------> aynı sayı iki defa verildiyse
add_number_to_stack içinde yakalamak için lazım
-assign_index
-is_sorted
-sort_stack
-free_stac
*/
#include "push_swap.h"

/* int	main(int ac, char **av)
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
}*/
/* void	print_stacks(t_control *ctrl)
{
	t_node	*curr_a;
	t_node	*curr_b;
	int		i;

	printf("\n------- CURRENT STACKS -------\n");
	printf("Stack A: ");
	curr_a = ctrl->a->top;
	i = 0;
	while (i < ctrl->a->size)
	{
		printf("%d ", curr_a->value);
		curr_a = curr_a->next;
		i++;
	}
	printf("\nStack B: ");
	curr_b = ctrl->b->top;
	i = 0;
	while (i < ctrl->b->size)
	{
		printf("%d ", curr_b->value);
		curr_b = curr_b->next;
		i++;
	}
	printf("\n------------------------------\n");
} */
int main(int ac, char **av)
{
	t_control ctrl;

	if (ac < 2)
		return (0);
	init_control(&ctrl);
	if (!ctrl.a || !ctrl.b)
		return (1);
	if (!parse_and_fill_stack(&(ctrl.a), ac, av, &ctrl))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	run_adaptive_strategy(&ctrl);
/* 	print_stacks(&ctrl);*/
	free_stack(ctrl.a);
	free_stack(ctrl.b);
	return (0);
}
