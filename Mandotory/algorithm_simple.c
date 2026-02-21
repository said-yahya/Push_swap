/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_simple.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpolat <edpolat@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 20:17:11 by edpolat           #+#    #+#             */
/*   Updated: 2026/02/20 18:02:27 by edpolat          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	finder_minimum(t_control *ctrl)
{
	t_node	*temp;
	int		min;
	int		size;
	int		i;
	int		j;

	j = ctrl->a->size;
	size = 0;
	i = 0;
	min = ctrl->a->top->value;
	temp = ctrl->a->top;
	while (i <= j)
	{
		if (min > temp->value)
		{
			min = temp->value;
			size = i;
		}
		temp = temp->next;
		i++;
	}
	return (size);
}

void	sort_three(t_control *ctrl)
{
	int	x;
	int	y;
	int	z;

	x = ctrl->a->top->value;
	y = ctrl->a->top->next->value;
	z = ctrl->a->top->next->next->value;
	if (x > y && y < z && x < z)
		sa(ctrl->a, 1, ctrl);
	else if (x > y && y > z)
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

void	sort_simple2(t_control *ctrl)
{
	int	a;

	if (ctrl->a->size == 3)
		sort_three(ctrl);
	else if (ctrl->a->size == 4 || ctrl->a->size == 5)
	{
		a = finder_minimum(ctrl);
		if (a <= ctrl->a->size / 2)
			while (a-- > 0)
				ra(ctrl->a, 1, ctrl);
		else
		{
			a = ctrl->a->size - a;
			while (a-- > 0)
				rra(ctrl->a, 1, ctrl);
		}
		pb(ctrl->a, ctrl->b, 1, ctrl);
		if (ctrl->a->size == 3)
			sort_three(ctrl);
		else
			sort_simple2(ctrl);
		pa(ctrl->a, ctrl->b, 1, ctrl);
	}
}

void	sort_simple(t_control *ctrl)
{
	int	finder_size;

	if (ctrl->mode == 0)
		ctrl->adaptive_checker = 1;
	while (ctrl->a->size > 5)
	{
		finder_size = finder_minimum(ctrl);
		if (finder_size != 0)
		{
			if (finder_size <= ctrl->a->size / 2)
				while (finder_size-- > 0)
					ra(ctrl->a, 1, ctrl);
			else
			{
				finder_size = ctrl->a->size - finder_size;
				while (finder_size-- > 0)
					rra(ctrl->a, 1, ctrl);
			}
		}
		pb(ctrl->a, ctrl->b, 1, ctrl);
	}
	sort_simple2(ctrl);
	while (ctrl->b->top)
		pa(ctrl->a, ctrl->b, 1, ctrl);
}
