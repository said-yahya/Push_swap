/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_main_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpolat <edpolat@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 20:02:31 by edpolat           #+#    #+#             */
/*   Updated: 2026/02/21 00:59:24 by edpolat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	parse_and_fill_stack(t_stack **a, int ac, char **av, t_control *ctrl)
{
	int	i;
	int	flag_res;

	i = 1;
	while (i < ac)
	{
		flag_res = handle_flags(av[i], ctrl);
		if (flag_res == -1)
			return (0);
		else if (flag_res == 1)
		{
			i++;
			continue ;
		}
		if (!process_argument_strings(a, av[i]))
			return (0);
		i++;
	}
	return (1);
}

int	is_duplicate(t_stack *stack, int value)
{
	t_node	*temp;
	int		i;

	if (!stack || stack->size == 0)
		return (0);
	temp = stack->top;
	i = 0;
	while (i < stack->size)
	{
		if (temp->value == value)
			return (1);
		temp = temp->next;
		i++;
	}
	return (0);
}

void	free_matrix(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	init_control(t_control *ctrl)
{
	ctrl->a = (t_stack *)malloc(sizeof(t_stack));
	ctrl->b = (t_stack *)malloc(sizeof(t_stack));
	if (!ctrl->a || !ctrl->b)
		return ;
	ctrl->a->top = NULL;
	ctrl->a->size = 0;
	ctrl->b->top = NULL;
	ctrl->b->size = 0;
	ctrl->mode = 0;
	ctrl->bench = 0;
	ctrl->op_count = 0;
	ctrl->disorder = 0.0;
	ctrl->benchmode.pa = 0;
	ctrl->benchmode.pb = 0;
	ctrl->benchmode.sa = 0;
	ctrl->benchmode.sb = 0;
	ctrl->benchmode.ss = 0;
	ctrl->benchmode.ra = 0;
	ctrl->benchmode.rb = 0;
	ctrl->benchmode.rr = 0;
	ctrl->benchmode.rra = 0;
	ctrl->benchmode.rrb = 0;
	ctrl->benchmode.rrr = 0;
	ctrl->doublecheck = 0;
}

int	ft_isdigit(int c)
{
	if (!(c > 47 && c < 58))
		return (0);
	else
		return (1);
}
