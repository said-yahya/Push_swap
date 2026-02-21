/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_complex_radix.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaikhuj <ysaikhuj@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 16:05:54 by ysaikhuj          #+#    #+#             */
/*   Updated: 2026/02/21 16:05:56 by ysaikhuj         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_complex_radix(t_control *ctrl)
{
	int	i;
	int	j;
	int	size;
	int	max_bits;

	indexing(ctrl->a);
	size = ctrl->a->size;
	max_bits = 0;
	while (((size - 1) >> max_bits) != 0)
		max_bits++;
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j++ < size)
		{
			if (((ctrl->a->top->index >> i) & 1) == 1)
				ra(ctrl->a, 1, ctrl);
			else
				pb(ctrl->a, ctrl->b, 1, ctrl);
		}
		while (ctrl->b->size > 0)
			pa(ctrl->a, ctrl->b, 1, ctrl);
		i++;
	}
}
