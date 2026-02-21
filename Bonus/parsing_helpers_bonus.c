/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_helpers_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpolat <edpolat@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 19:59:43 by edpolat           #+#    #+#             */
/*   Updated: 2026/02/21 15:05:35 by edpolat          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

long	ft_atol(const char *nptr, int *error)
{
	long	result;
	long	sign;
	int		i;

	*error = 1;
	result = 0;
	sign = 1;
	i = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i++] == '-')
			sign = -1;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		if (result > (LONG_MAX - (nptr[i] - '0')) / 10)
		{
			*error = 0;
			return (0);
		}
		result = (result * 10) + (nptr[i++] - '0');
	}
	return (result * sign);
}

int	is_number(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	add_number_to_stack(t_stack **a, char *str)
{
	long	value;
	t_node	*new;
	int		error;

	if (!is_number(str))
		return (0);
	if (!str || !a || !*a)
		return (0);
	value = ft_atol(str, &error);
	if (value < INT_MIN || value > INT_MAX || !error)
		return (0);
	if (is_duplicate(*a, (int)value))
		return (0);
	new = ft_newnode((int)value);
	if (!new)
		return (0);
	ft_addback(*a, new);
	return (1);
}

int	process_argument_strings(t_stack **a, char *av)
{
	char	**temp_args;
	int		j;

	temp_args = ft_split(av, ' ');
	if (!temp_args || !temp_args[0])
	{
		free_matrix(temp_args);
		return (0);
	}
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
	return (1);
}
