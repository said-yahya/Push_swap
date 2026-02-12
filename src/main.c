/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpolat <edpolat@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 01:06:05 by edpolat           #+#    #+#             */
/*   Updated: 2026/02/13 01:06:06 by edpolat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	parse_and_fill_stack(t_stack **a, int ac, char **av)
{
	int		i;
	int		j;
	char	**temp_args;

	i = 1;
	while (i < ac)
	{
		temp_args = ft_split(av[i], ' ');
		if (!temp_args)
			return (0);
		j = 0;
		while (temp_args[j])
		{
			if (!add_number_to_stack(a, temp_args[j]))
			{
				free_matrix(temp_args);
				return (0);
			}
			j++;
		}
		free_matrix(temp_args);
		i++;
	}
	return (1);
}
int main(int ac, char **av)
{
	int		i;
	int		j;
	char	**temp_args;
	t_stack	*stack;
	if (ac == 1)
		return (0);
	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)		
		return (0);
	i = 1;
	while (i < ac)
	{
		temp_args = ft_split(av[i], ' ');
		if (!temp_args)
			return (0);
		j = 0;
		while (temp_args[j])
		{
			ft_addback(stack, ft_newnode(ft_atoi(temp_args[j])));
			if (!stack->top)
			{
				free_matrix(temp_args);
				return (0);
			}
			j++;
		}
		free_matrix(temp_args);
		i++;
	}
	return (0);
}
/* int main(int ac, char **av)
{
    t_stack *stack;
    char    **nums;
    int     i;

    if (ac == 1)
        return (0);
    nums = ft_split(av[1], ' ');
    if (!nums)
        return (NULL);
    i = 0;
    while (nums[i])
    {
        ft_addback(stack, ft_newnode(ft_atoi(nums[i])));
        i++;
    }
} */

