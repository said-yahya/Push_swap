/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpolat <edpolat@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 17:28:39 by edpolat           #+#    #+#             */
/*   Updated: 2026/02/17 12:18:46 by edpolat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack *stack)
{
	if (!stack || stack->size < 2)
		return ;
	stack->top = stack->top->next;
}

void	ra(t_stack *a, int print, t_control *ctrl)
{
	rotate(a);
	if (print)
		write(1, "ra\n", 3);
	ctrl->op_count++;
	ctrl->benchmode.ra++;
}

void	rb(t_stack *b, int print, t_control *ctrl)
{
	rotate(b);
	if (print)
		write(1, "rb\n", 3);
	ctrl->op_count++;
	ctrl->benchmode.rb++;
}

void	rr(t_stack *a, t_stack *b, int print, t_control *ctrl)
{
	rotate(a);
	rotate(b);
	if (print)
		write(1, "rr\n", 3);
	ctrl->op_count++;
	ctrl->benchmode.rr++;
}
