/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_complex.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpolat <edpolat@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 11:46:29 by edpolat           #+#    #+#             */
/*   Updated: 2026/02/16 05:30:38 by edpolat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void merge_sort_a(t_control *ctrl, int size)
{
	int half;

	if (size <= 1)
		return;
	if (size == 2)
	{
		if (ctrl->a->top->value > ctrl->a->top->next->value)
			sa(ctrl->a, 1, ctrl);
		return;
	}
	if (size == 3)
	{
		sort_three(ctrl);
		return;
	}
	half = size / 2;
	int i;
	i = 0;
	while (i < half)
	{
		pb(ctrl->a, ctrl->b, 1, ctrl);
		i++;
	}
	merge_sort_a(ctrl, size - half);
	merge_sort_b(ctrl, half);
	merge_to_a(ctrl, size - half, half);
}

void merge_sort_b(t_control *ctrl, int size)
{
	int half;

	if (size <= 1)
		return;
	if (size == 2)
	{
		if (ctrl->b->top->value < ctrl->b->top->next->value)
			sb(ctrl->b, 1, ctrl);
		return;
	}
	if (size == 3)
	{
		sort_three_b(ctrl);
		return;
	}
	half = size / 2;
	for (int i = 0; i < half; i++)
		pa(ctrl->a, ctrl->b, 1, ctrl);
	merge_sort_a(ctrl, half);
	merge_sort_b(ctrl, size - half);
	merge_to_b(ctrl, half, size - half);
}
void help_merge_to_a(t_control *ctrl, int rotated, int right)
{
	while (right > 0)
	{
		pa(ctrl->a, ctrl->b, 1, ctrl);
		right--;
	}
	while (rotated > 0)
	{
		rra(ctrl->a, 1, ctrl);
		rotated--;
	}
}
void merge_to_a(t_control *ctrl, int left, int right)
{
	int rotated;

	rotated = 0;
	while (left > 0 && right > 0)
	{
		if (ctrl->a->top->value <= ctrl->b->top->value)
		{
			ra(ctrl->a, 1, ctrl);
			rotated++;
			left--;
		}
		else
		{
			pa(ctrl->a, ctrl->b, 1, ctrl);
			right--;
		}
	}
	help_merge_to_a(ctrl, rotated, right);
}
void merge_to_b(t_control *ctrl, int left, int right)
{
	int rotated;

	rotated = 0;
	while (left > 0 && right > 0)
	{
		if (ctrl->b->top->value >= ctrl->a->top->value)
		{
			rb(ctrl->b, 1, ctrl);
			rotated++;
			right--;
		}
		else
		{
			pb(ctrl->a, ctrl->b, 1, ctrl);
			left--;
		}
	}
	while (left > 0)
	{
		pb(ctrl->a, ctrl->b, 1, ctrl);
		left--;
	}
	while (rotated > 0)
	{
		rrb(ctrl->b, 1, ctrl);
		rotated--;
	}
}
