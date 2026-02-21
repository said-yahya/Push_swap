/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpolat <edpolat@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 16:14:20 by edpolat           #+#    #+#             */
/*   Updated: 2026/02/20 20:44:59 by edpolat          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	is_sorted(t_control *ctrl)
{
	t_node	*curr;
	int		i;

	if (!ctrl->a || ctrl->a->size < 2)
		return (1);
	curr = ctrl->a->top;
	i = 0;
	while (i < ctrl->a->size - 1)
	{
		if (curr->value > curr->next->value)
			return (0);
		curr = curr->next;
		i++;
	}
	return (1);
}

int	apply_operation(char *op, t_control *ctrl)
{
	if (ft_strncmp(op, "pa", 2) == 0 && op[2] == '\0')
		pa(ctrl->a, ctrl->b, 0, ctrl);
	else if (ft_strncmp(op, "pb", 2) == 0 && op[2] == '\0')
		pb(ctrl->a, ctrl->b, 0, ctrl);
	else if (ft_strncmp(op, "sa", 2) == 0 && op[2] == '\0')
		sa(ctrl->a, 0, ctrl);
	else if (ft_strncmp(op, "sb", 2) == 0 && op[2] == '\0')
		sb(ctrl->b, 0, ctrl);
	else if (ft_strncmp(op, "ss", 2) == 0 && op[2] == '\0')
		ss(ctrl->a, ctrl->b, 0, ctrl);
	else if (ft_strncmp(op, "rra", 3) == 0 && op[3] == '\0')
		rra(ctrl->a, 0, ctrl);
	else if (ft_strncmp(op, "rrb", 3) == 0 && op[3] == '\0')
		rrb(ctrl->b, 0, ctrl);
	else if (ft_strncmp(op, "rrr", 3) == 0 && op[3] == '\0')
		rrr(ctrl->a, ctrl->b, 0, ctrl);
	else if (ft_strncmp(op, "ra", 2) == 0 && op[2] == '\0')
		ra(ctrl->a, 0, ctrl);
	else if (ft_strncmp(op, "rb", 2) == 0 && op[2] == '\0')
		rb(ctrl->b, 0, ctrl);
	else if (ft_strncmp(op, "rr", 2) == 0 && op[2] == '\0')
		rr(ctrl->a, ctrl->b, 0, ctrl);
	else
		return (0);
	return (1);
}

int	read_and_apply(t_control *ctrl)
{
	char	*operation;
	int		len;

	operation = get_next_line(0);
	while (operation)
	{
		len = ft_strlen(operation);
		if (len > 0 && operation[len - 1] == '\n')
			operation[len - 1] = '\0';
		if (!apply_operation(operation, ctrl))
		{
			free(operation);
			return (0);
		}
		free(operation);
		operation = get_next_line(0);
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_control	ctrl;
	int			str;

	if (ac < 2)
		return (0);
	init_control(&ctrl);
	if (!ctrl.a || !ctrl.b)
		return (1);
	if (!parse_and_fill_stack(&(ctrl.a), ac, av))
	{
		free_stackss(ctrl);
		write(2, "Error\n", 6);
		return (1);
	}
	str = read_and_apply(&ctrl);
	if (str == 0)
	{
		free_stackss(ctrl);
		write(2, "Error\n", 6);
		return (1);
	}
	ok_or_ko(ctrl);
	free_stackss(ctrl);
	return (0);
}

void	ok_or_ko(t_control ctrl)
{
	if (is_sorted(&ctrl) && ctrl.b->size == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}
