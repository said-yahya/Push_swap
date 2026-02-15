/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbook <macbook@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 20:04:23 by edpolat           #+#    #+#             */
/*   Updated: 2026/02/15 19:50:49 by macbook          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "push_swap.h"
void run_adaptive_strategy(t_control *ctrl)
{
	float disorder;

	disorder = disorder_calculate(ctrl->a);
	/* 	if (ctrl->a->size <= 3)
		{
			sort_simple(ctrl);
			return ;
		} */
	if (disorder == 0.0)
	{
		return;
	}
	if (ctrl->mode == 1 || (ctrl->mode == 0 && disorder < 0.2))
	{
		sort_simple(ctrl);
	}
	else if (ctrl->mode == 2 || (ctrl->mode == 0 && disorder < 0.5))
			sort_medium(ctrl);
	/* else if (ctrl->mode == 3 || ctrl->mode == 0)
		sort_complex(ctrl); */
}

static float mistake_calculater(t_stack *stack)
{
	t_node *a;
	t_node *b;
	int i;
	int j;
	float mistakes;

	mistakes = 0;
	a = stack->top;
	i = 0;
	while (i < stack->size - 1)
	{
		b = a->next;
		j = i + 1;
		while (j < stack->size)
		{
			if (a->value > b->value)
				mistakes++;
			b = b->next;
			j++;
		}
		a = a->next;
		i++;
	}
	return (mistakes);
}

float disorder_calculate(t_stack *stack)
{
	float mistakes;
	float total;
	int x;

	if (!stack || stack->size < 2)
		return (0.0);
	x = stack->size;
	total = x * (x - 1) / 2;
	mistakes = mistake_calculater(stack);
	return (mistakes / total);
}
