/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpolat <edpolat@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 01:06:05 by edpolat           #+#    #+#             */
/*   Updated: 2026/02/20 18:31:37 by edpolat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_control	ctrl;

	if (ac < 2)
		return (0);
	init_control(&ctrl);
	if (!ctrl.a || !ctrl.b)
		return (1);
	if (!parse_and_fill_stack(&(ctrl.a), ac, av, &ctrl))
	{
		free_stack(ctrl.a);
		free_stack(ctrl.b);
		write(2, "Error\n", 6);
		return (1);
	}
	run_adaptive_strategy(&ctrl);
	if (ctrl.bench == 1)
		bench_mode_print(&ctrl);
	free_stack(ctrl.a);
	free_stack(ctrl.b);
	return (0);
}
