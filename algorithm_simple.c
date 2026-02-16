/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_simple.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpolat <edpolat@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 20:17:11 by edpolat           #+#    #+#             */
/*   Updated: 2026/02/17 01:14:22 by edpolat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
stack a'daki en küçüğü bulup sürekli stack b'ye attığım bir algoritma
hayal ediyorum.  bulması için node node gezsin, sonrasında size'ına baksın,
başa ya da sona yakın olmasına göre reverse ya da rotate etsin, b'de
sıralanmış halde oluyor. en son a'ya geri yollasın şeklinde bir algoritma
tasarladım kafamda. Normalde de varmış, selection/min extraction adaptasyon oluyomuş.
*/

int finder_minimum(t_control *ctrl)
{
	t_node *temp;
	int min;
	int size;
	int i;
	int j;
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

void sort_simple(t_control *ctrl)
{
	int finder_size;

	if(ctrl->mode == 0)
		ctrl->adaptive_checker = 1;
	while (ctrl->a->top)
	{
		finder_size = finder_minimum(ctrl);
		if (finder_size != 0)
		{
			if (finder_size <= ctrl->a->size / 2)
			{
				while (finder_size-- > 0)
					ra(ctrl->a, 1, ctrl);
			}
			else
			{
				finder_size = ctrl->a->size - finder_size;
				while (finder_size-- > 0)
					rra(ctrl->a, 1, ctrl);
			}
		}
		pb(ctrl->a, ctrl->b, 1, ctrl);
	}
	while (ctrl->b->top)
		pa(ctrl->a, ctrl->b, 1, ctrl);
}
