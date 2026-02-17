/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpolat <edpolat@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 16:14:20 by edpolat           #+#    #+#             */
/*   Updated: 2026/02/17 17:08:57 by edpolat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	is_sorted(t_control *ctrl)
{
	int	i;
	int	j;
	int	k;
	t_node	*node;
	t_node	*temp;

	i = 0;
	k = ctrl->a->size;
	node = ctrl->a->top;
	temp = ctrl->a->top->next;
	while (i < k)
	{
		j = 0;
		while(j < k - i)
		{
			if(node->value > temp->value)
				return (0);
			temp = temp->next;
			j++;
		}
		node = node->next;
		i++;
	}
	return(1);
}
int apply_operation(char *op, t_control *ctrl)
{
	if (ft_strncmp(op, "pa\n", 3) == 0)
		pa(ctrl->a, ctrl->b, 0, ctrl);
	else if (ft_strncmp(op, "pb\n", 3) == 0)
		pb(ctrl->a, ctrl->b, 0, ctrl);
	else if (ft_strncmp(op, "sa\n", 3) == 0)
		sa(ctrl->a, 0, ctrl);
	else if (ft_strncmp(op, "sb\n", 3) == 0)
		sb(ctrl->b, 0, ctrl);
	else if (ft_strncmp(op, "ss\n", 3) == 0)
		ss(ctrl->a, ctrl->b, 0, ctrl);
	else if (ft_strncmp(op, "ra\n", 3) == 0)
		ra(ctrl->a, 0, ctrl);
	else if (ft_strncmp(op, "rb\n", 3) == 0)
		rb(ctrl->b, 0, ctrl);
	else if (ft_strncmp(op, "rr\n", 3) == 0)
		rr(ctrl->a, ctrl->b, 0, ctrl);
	else if (ft_strncmp(op, "rra\n", 4) == 0)
		rra(ctrl->a, 0, ctrl);
	else if (ft_strncmp(op, "rrb\n", 4) == 0)
		rrb(ctrl->b, 0, ctrl);
	else if (ft_strncmp(op, "rrr\n", 4) == 0)
		rrr(ctrl->a, ctrl->b, 0, ctrl);
	else
		return (0);
	return (1);
}

int	read_and_apply(t_control *ctrl)
{
	char *operation;

	while ((operation = get_next_line(0)))
	{
		if (!apply_operation(operation, ctrl))
		{
			free(operation);
			return (0);
		}
		free(operation);
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_control	ctrl;

	if (ac < 2)
		return (0);
	init_control(&ctrl);
	if (!ctrl.a || !ctrl.b)
		return (1);
	if (!parse_and_fill_stack(&(ctrl.a), ac, av, &ctrl))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	read_and_apply(&ctrl);
	if(is_sorted(&ctrl))
		write(2, "KO\n", 3);
	else
		write(1, "OK\n", 3);
	free_stack(ctrl.a);
	free_stack(ctrl.b);
	return (0);
}
