/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_reverse.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpolat <edpolat@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 15:08:09 by edpolat           #+#    #+#             */
/*   Updated: 2026/02/13 16:23:37 by edpolat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
ra (döndür a): A yığınının tüm elemanlarını 1 yukarı kaydır (ilk eleman son eleman olur)
rb (b'yi döndür): B yığınının tüm elemanlarını 1 yukarı kaydır
rr: ra ve rb aynı anda
rra (ters döndürme a): A yığınının tüm elemanlarını 1 aşağı kaydırın (sonuncu ilk olur)
rrb (ters döndürme b): B yığınının tüm elemanlarını 1 aşağı kaydır
rrr: rra ve rrb aynı anda */
/*
-ra ve rra formatının farkı aşağı ya da yukarı gitmek olduğundan
ra-rra aynı fonksiyonda, rb-rrb aynı fonksiyonda, rb-rrb aynı fonksiyonda 
yönetilecek şekilde yazmaya çalıştım, kontrolünü de i = 1 ve i =-1 ile yapar 
iki döngüyü tek fonksiyona atarız. */

#include "push_swap.h"

void	rotate(t_stack *stack)
{
	if (!stack || stack->size < 2)
		return ;
	stack->top = stack->top->next;
}

void    reverse_rotate(t_stack *stack)
{
    if (!stack || stack->size < 2)
		return ;
	stack->top = stack->top->prev;
}

void	ra(t_stack *a, int print, t_control *control)
{
	rotate(a);
	if (print)
		write(1, "ra\n", 3);
	if (control)
		control->op_count++;
}

void	rb(t_stack *b, int print, t_control *control)
{
	rotate(b);
	if (print)
		write(1, "rb\n", 3);
	if (control)
		control->op_count++;
}

void	rr(t_stack *a, t_stack *b, int print, t_control *control)
{
	rotate(a);
	rotate(b);
	if (print)
		write(1, "rr\n", 3);
	if (control)
		control->op_count++;
}

void    rra(t_stack *a, int print, t_control *control)
{
    reverse_rotate(a);
	if (print)
		write(1, "rra\n", 4);
	if (control)
		control->op_count++;
}

void    rrb(t_stack *b, int print, t_control *control)
{
    reverse_rotate(b);
	if (print)
		write(1, "rrb\n", 4);
	if (control)
		control->op_count++;
}

void    rrr(t_stack *a, t_stack *b, int print, t_control *control)
{
    reverse_rotate(a);
    reverse_rotate(b);
	if (print)
		write(1, "rrr\n", 4);
	if (control)
		control->op_count++;
}
