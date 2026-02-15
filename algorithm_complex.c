/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_complex.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpolat <edpolat@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 11:46:29 by edpolat           #+#    #+#             */
/*   Updated: 2026/02/15 11:49:25 by edpolat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_control *ctrl)
{
	if (ctrl->a->size == 2)
		sa(ctrl->a, 1, ctrl);
}

void	sort_three(t_control *ctrl)
{
	int x;
	int y;
	int z;

	x = ctrl->a->top->value;
	y = ctrl->a->top->next->value;
	z = ctrl->a->top->next->next->value;

	if (x > y && y < z && x < z)
		sa(ctrl->a, 1, ctrl);
	else if (x > y && y > z && x > z)
	{
		sa(ctrl->a, 1, ctrl);
		rra(ctrl->a, 1, ctrl);
	}
	else if (x > y && y < z && x > z)
		ra(ctrl->a, 1, ctrl);
	else if (x < y && y > z && x < z)
	{
		sa(ctrl->a, 1, ctrl);
		ra(ctrl->a, 1, ctrl);
	}
	else
		rra(ctrl->a, 1, ctrl);
}
