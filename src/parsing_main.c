/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpolat <edpolat@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 20:02:31 by edpolat           #+#    #+#             */
/*   Updated: 2026/02/13 20:04:09 by edpolat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int parse_and_fill_stack(t_stack **a, int ac, char **av, t_control *ctrl)
{
	int i;
	int flag_res;

	i = 1;
	while (i < ac)
	{
		flag_res = handle_flags(av[i], ctrl);
		if (flag_res == -1)
			return (0);
		if (flag_res == 1)
		{
			i++;
			continue;
		}
		if (!process_argument_strings(a, av[i]))
			return (0);
		i++;
	}
	return (1);
}

int is_duplicate(t_stack *stack, int value)
{
	t_node *temp;
	int i;

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

void free_matrix(char **str)
{
	int i;

	i = 0;
	if (!str)
		return;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	init_control(t_control *ctrl)
{
	/* 1. Stack yapıları için yer ayır */
	ctrl->a = (t_stack *)malloc(sizeof(t_stack));
	ctrl->b = (t_stack *)malloc(sizeof(t_stack));
	if (!ctrl->a || !ctrl->b)
		return;/*  Hata yönetimi burada yapılabilir */
/* 	2. Stack'leri temizle (Sıfır noktası) */
	ctrl->a->top = NULL;
	ctrl->a->size = 0;
	ctrl->b->top = NULL;
	ctrl->b->size = 0;
	ctrl->mode = 0;/* Default: --adaptive */
	ctrl->bench = 0; /*  Default: Benchmark kapalı */
	ctrl->op_count = 0;
	ctrl->disorder = 0.0;
}

