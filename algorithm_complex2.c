/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_complex2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpolat <edpolat@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 05:28:52 by edpolat           #+#    #+#             */
/*   Updated: 2026/02/16 05:30:28 by edpolat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_three(t_control *ctrl)
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
void sort_three_b(t_control *ctrl)
{
	int x;
	int y;
	int z;

	x = ctrl->b->top->value;
	y = ctrl->b->top->next->value;
	z = ctrl->b->top->next->next->value;

	if (x > y && y < z && x < z)
		pb(ctrl->a, ctrl->b, 1, ctrl);
	else if (x > y && y > z && x > z)
	{
		pb(ctrl->a, ctrl->b, 1, ctrl);
		rrb(ctrl->b, 1, ctrl);
	}
	else if (x > y && y < z && x > z)
		ra(ctrl->b, 1, ctrl);
	else if (x < y && y > z && x < z)
	{
		pb(ctrl->a, ctrl->b, 1, ctrl);
		ra(ctrl->b, 1, ctrl);
	}
	else
		rrb(ctrl->a, 1, ctrl);
}
void reverse_sorted_fastpath(t_control *ctrl)
{
	int size;

	size = ctrl->a->size;

	while (ctrl->a->size > 0)
		pb(ctrl->a, ctrl->b, 1, ctrl);

	while (ctrl->b->size > 0)
	{
		pa(ctrl->a, ctrl->b, 1, ctrl);
		ra(ctrl->a, 1, ctrl);
	}
}
void sort_complex(t_control *ctrl)
{
	int size;
	double disorder;

	disorder = disorder_calculate(ctrl->a);

	if (disorder == 1.0)
	{
		reverse_sorted_fastpath(ctrl);
		return;
	}
	size = ctrl->a->size;
	merge_sort_a(ctrl, size);
}
