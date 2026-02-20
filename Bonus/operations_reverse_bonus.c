/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_reverse_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpolat <edpolat@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 15:08:09 by edpolat           #+#    #+#             */
/*   Updated: 2026/02/21 00:59:05 by edpolat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	reverse_rotate(t_stack *stack)
{
	if (!stack || stack->size < 2)
		return ;
	stack->top = stack->top->prev;
}

void	rra(t_stack *a, int print, t_control *ctrl)
{
	reverse_rotate(a);
	if (print)
		write(1, "rra\n", 4);
	ctrl->op_count++;
	ctrl->benchmode.rra++;
}

void	rrb(t_stack *b, int print, t_control *ctrl)
{
	reverse_rotate(b);
	if (print)
		write(1, "rrb\n", 4);
	ctrl->op_count++;
	ctrl->benchmode.rrb++;
}

void	rrr(t_stack *a, t_stack *b, int print, t_control *ctrl)
{
	reverse_rotate(a);
	reverse_rotate(b);
	if (print)
		write(1, "rrr\n", 4);
	ctrl->op_count++;
	ctrl->benchmode.rrr++;
}
