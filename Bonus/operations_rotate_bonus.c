/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaikhuj <ysaikhuj@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 16:09:00 by ysaikhuj          #+#    #+#             */
/*   Updated: 2026/02/21 16:09:03 by ysaikhuj         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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
