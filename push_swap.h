/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbook <macbook@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 17:31:22 by ysaikhuj          #+#    #+#             */
/*   Updated: 2026/02/16 21:07:50 by macbook          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "Libft/libft.h"
#include <stdio.h>

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
	struct s_node	*prev;
}			t_node;

typedef struct s_stack
{
	t_node	*top;
	int		size;
}			t_stack;

typedef struct s_control
{
	t_stack	*a;		// Stack A'nın adresi
	t_stack	*b;		// Stack B'nin adresi
	int		mode;		// 0:Adaptive, 1:Simple, 2:Medium, 3:Complex
	int		bench;		// bu ilerde ihtiyaç duyacağımız bir şey, pdfte sf. 16
	float	disorder; // Başlangıçta hesaplanan düzensizlik oranı sf.16
	int		op_count;	// Toplam yapılan işlem sayısı sf. 16
}			t_control;

t_node	*ft_newnode(int value);
void	ft_addback(t_stack *stack, t_node *new);
void	ft_delone(t_stack *stack, t_node *node);
void	free_matrix(char **str);
void	indexing(t_stack *stack);

void	swap(t_stack *stack);
void	sa(t_stack *a, int print, t_control *ctrl);
void	sb(t_stack *b, int print, t_control *ctrl);
void	ss(t_stack *a, t_stack *b, int print, t_control *ctrl);
void	push(t_stack *to, t_stack *from);
void	pa(t_stack *a, t_stack *b, int print, t_control *ctrl);
void	pb(t_stack *a, t_stack *b, int print, t_control *ctrl);
void	rotate(t_stack *stack);
void	ra(t_stack *a, int print, t_control *ctrl);
void	rb(t_stack *b, int print, t_control *ctrl);
void	rr(t_stack *a, t_stack *b, int print, t_control *ctrl);
void	reverse_rotate(t_stack *stack);
void	rra(t_stack *a, int print, t_control *ctrl);
void	rrb(t_stack *b, int print, t_control *ctrl);
void	rrr(t_stack *a, t_stack *b, int print, t_control *ctrl);

void	free_stack(t_stack *stack);
void	init_stack(t_stack *stack);
void	init_control(t_control *ctrl);
float	disorder_calculate(t_stack *stack);
void	free_matrix(char **str);
int		is_duplicate(t_stack *stack, int value);
int		handle_flags(char *arg, t_control *ctrl);
long	ft_atol(const char *nptr, int *error);
int		add_number_to_stack(t_stack **a, char *str);
int		parse_and_fill_stack(t_stack **a, int ac, char **av, t_control *ctrl);
void	run_adaptive_strategy(t_control *ctrl);
int		process_argument_strings(t_stack **a, char *av);

void	sort_simple(t_control *ctrl);
void	sort_medium(t_control *ctrl);
void	sort_complex_radix(t_control *ctrl);
void	sort_complex(t_control *ctrl);
void	merge_sort_a(t_control *ctrl, int size);
void	merge_sort_b(t_control *ctrl, int size);
void	merge_to_a(t_control *ctrl, int left, int right);
void	merge_to_b(t_control *ctrl, int left, int right);
void	sort_three(t_control *ctrl);
void	sort_three_b(t_control *ctrl);



#endif
