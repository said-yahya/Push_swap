/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpolat <edpolat@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 17:31:22 by ysaikhuj          #+#    #+#             */
/*   Updated: 2026/02/14 02:58:24 by edpolat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include "Libft/libft.h"
typedef struct s_node
{
	int value;
	int index;
	struct s_node *next;
	struct s_node *prev;
} t_node;

typedef struct s_stack
{
	t_node *top;
	int size;
} t_stack;

typedef struct s_control
{
	t_stack *a;		// Stack A'nın adresi
	t_stack *b;		// Stack B'nin adresi
	int mode;		// 0:Adaptive, 1:Simple, 2:Medium, 3:Complex
	int bench;		// bu ilerde ihtiyaç duyacağımız bir şey, pdfte sf. 16
	float disorder; // Başlangıçta hesaplanan düzensizlik oranı sf.16
	int op_count;	// Toplam yapılan işlem sayısı sf. 16
} t_control;

t_node *ft_newnode(int value);
void	ft_addback(t_stack *stack, t_node *new);
void	ft_delone(t_stack *stack, t_node *node);
void	free_matrix(char **str);
int		parse_and_fill_stack(t_stack **a, int ac, char **av, t_control *ctrl);
float 	disorder_calculate(t_stack *stack);
void	swap(t_stack *stack);
void	sa(t_stack *a, int print, t_control *ctrl);
void	sb(t_stack *b, int print, t_control *ctrl);
void	ss(t_stack *a, t_stack *b, int print, t_control *ctrl);
void	push(t_stack *to, t_stack *from);
void	pa(t_stack *a, t_stack *b, int print, t_control *ctrl);
void	pb(t_stack *a, t_stack *b, int print, t_control *ctrl);

void	init_control(t_control *ctrl);
float	disorder_calculate(t_stack *stack);
void	free_matrix(char **str);
int		is_duplicate(t_stack *stack, int value);
int		handle_flags(char *arg, t_control *ctrl);
long	ft_atol(const char *nptr);
int		add_number_to_stack(t_stack **a, char *str);
int		parse_and_fill_stack(t_stack **a, int ac, char **av, t_control *ctrl);
void	run_adaptive_strategy(t_stack *a, t_stack *b, t_control *ctrl);
void	run_adaptive_strategy(t_stack *a, t_stack *b, t_control *ctrl);
int process_argument_strings(t_stack **a, char *av);
#endif
