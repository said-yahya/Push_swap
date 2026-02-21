/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpolat <edpolat@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 01:05:38 by edpolat           #+#    #+#             */
/*   Updated: 2026/02/17 12:18:56 by edpolat          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack)
{
	t_node	*first;
	t_node	*second;
	t_node	*third;
	t_node	*last;

	if (!stack || stack->size < 2)
		return ;
	else if (stack->size == 2)
	{
		stack->top = stack->top->next;
		return ;
	}
	first = stack->top;
	second = first->next;
	third = second->next;
	last = first->prev;
	last->next = second;
	second->prev = last;
	second->next = first;
	first->prev = second;
	first->next = third;
	third->prev = first;
	stack->top = second;
}

void	sa(t_stack *a, int print, t_control *ctrl)
{
	swap(a);
	if (print)
		write(1, "sa\n", 3);
	ctrl->op_count++;
	ctrl->benchmode.sa++;
}

void	sb(t_stack *b, int print, t_control *ctrl)
{
	swap(b);
	if (print)
		write(1, "sb\n", 3);
	ctrl->op_count++;
	ctrl->benchmode.sb++;
}

void	ss(t_stack *a, t_stack *b, int print, t_control *ctrl)
{
	swap(a);
	swap(b);
	if (print)
		write(1, "ss\n", 3);
	ctrl->op_count++;
	ctrl->benchmode.ss++;
}
