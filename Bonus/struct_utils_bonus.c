/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpolat <edpolat@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 09:19:19 by ysaikhuj          #+#    #+#             */
/*   Updated: 2026/02/21 00:59:35 by edpolat          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

t_node	*ft_newnode(int value)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->value = value;
	new->index = -1;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void	ft_addback(t_stack *stack, t_node *new)
{
	t_node	*last;

	if (!stack || !new)
		return ;
	if (!(stack->top))
	{
		stack->top = new;
		new->next = new;
		new->prev = new;
	}
	else
	{
		last = stack->top->prev;
		last->next = new;
		new->prev = last;
		new->next = stack->top;
		stack->top->prev = new;
	}
	stack->size++;
}

void	ft_delone(t_stack *stack, t_node *node)
{
	if (!stack || !stack->top || !node)
		return ;
	if (stack->size == 1)
		stack->top = NULL;
	else
	{
		if (stack->top == node)
			stack->top = node->next;
		node->prev->next = node->next;
		node->next->prev = node->prev;
	}
	free(node);
	stack->size--;
}

void	free_stack(t_stack *stack)
{
	t_node	*temp;
	t_node	*next;
	int		i;

	if (!stack && stack->size == 0)
		return ;
	temp = stack->top;
	i = 0;
	while (i < stack->size)
	{
		next = temp->next;
		free(temp);
		temp = next;
		i++;
	}
	free(stack);
}

void	indexing(t_stack *stack)
{
	t_node	*curr;
	t_node	*compare;
	int		i;
	int		j;
	int		idx;

	curr = stack->top;
	i = 0;
	while (i < stack->size)
	{
		idx = 0;
		compare = stack->top;
		j = 0;
		while (j < stack->size)
		{
			if (curr->value > compare->value)
				idx++;
			compare = compare->next;
			j++;
		}
		curr->index = idx;
		curr = curr->next;
		i++;
	}
}
