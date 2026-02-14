/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_algorithm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpolat <edpolat@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 20:17:11 by edpolat           #+#    #+#             */
/*   Updated: 2026/02/15 00:09:29 by edpolat          ###   ########.fr       */
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
	else if (x < y && y > z && x > z)
		rra(ctrl->a, 1, ctrl);
}
void sort_simple(t_stack *a, t_stack *b, t_control *ctrl)
{
	ctrl->b = b;
	if (a->size == 2)
		sa(a, 1, ctrl);
	else if (a->size == 3)
		sort_three(ctrl);
}
