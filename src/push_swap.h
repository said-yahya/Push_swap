/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpolat <edpolat@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 17:31:22 by ysaikhuj          #+#    #+#             */
/*   Updated: 2026/02/13 01:30:55 by edpolat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	int		size;
}	t_stack;

t_node	*ft_newnode(int value);
void	ft_addback(t_stack *stack, t_node *new);
void	ft_delone(t_stack *stack, t_node *node);
void	free_matrix(char **str);
int		parse_and_fill_stack(t_stack **a, int ac, char **av);
float	disorder_calculate(t_stack *stack);
void	swap(t_stack *stack);
void	sa(t_stack *a, int print);
void	sb(t_stack *b, int print);
void	ss(t_stack *a, t_stack *b, int print);
void	push(t_stack *from, t_stack *to);
void	pa(t_stack *a, t_stack *b, int print);
void	pb(t_stack *a, t_stack *b, int print);


#endif
