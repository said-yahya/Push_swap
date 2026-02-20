/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpolat <edpolat@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 15:07:18 by edpolat           #+#    #+#             */
/*   Updated: 2026/02/17 12:17:59 by edpolat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*pop_from_stack(t_stack *from)
{
	t_node	*node;

	if (!from || from->size == 0)
		return (NULL);
	node = from->top;
	if (from->size == 1)
		from->top = NULL;
	else
	{
		node->prev->next = node->next;
		node->next->prev = node->prev;
		from->top = node->next;
	}
	from->size--;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

static void	push_to_stack(t_stack *to, t_node *node)
{
	t_node	*last;

	if (to->size == 0)
	{
		node->next = node;
		node->prev = node;
		to->top = node;
	}
	else
	{
		last = to->top->prev;
		node->next = to->top;
		node->prev = last;
		last->next = node;
		to->top->prev = node;
		to->top = node;
	}
	to->size++;
}

void	push(t_stack *to, t_stack *from)
{
	t_node	*node;

	node = pop_from_stack(from);
	if (!node)
		return ;
	push_to_stack(to, node);
}

void	pa(t_stack *a, t_stack *b, int print, t_control *control)
{
	push(a, b);
	if (print)
		write(1, "pa\n", 3);
	control->op_count++;
	control->benchmode.pa++;
}

void	pb(t_stack *a, t_stack *b, int print, t_control *control)
{
	push(b, a);
	if (print)
		write(1, "pb\n", 3);
	control->op_count++;
	control->benchmode.pb++;
}
