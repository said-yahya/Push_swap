/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpolat <edpolat@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 01:05:38 by edpolat           #+#    #+#             */
/*   Updated: 2026/02/13 01:29:49 by edpolat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/* 
-0 veya 1 eleman varsa işlem yapılamaz.
-First, artık Second'ın arkasına geçeceği için, First'in next'i artık Third'ü göstermeli.
-Eğer Third varsa, onun prev'i artık First'ü göstermeli (çünkü Second artık orada değil).
-Second, en başa geçeceği için prev'i NULL olmalı.
-Second'ın next'i artık First'ü göstermeli.
-First'in prev'i artık Second'ı göstermeli.
-Stack'in top işaretçisi artık Second olmalı.
*/
void	swap(t_stack *stack)
{
	t_node	*first;
	t_node	*second;

	if (!stack || !stack->top || !stack->top->next)
		return ;

	first = stack->top;
	second = first->next;

	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	stack->top = second;
}
void	sa(t_stack *a, int print)
{
	swap_logic(a);
	if (print)
		write(1, "sa\n", 3);
}

void	sb(t_stack *b, int print)
{
	swap_logic(b);
	if (print)
		write(1, "sb\n", 3);
}

void	ss(t_stack *a, t_stack *b, int print)
{
	swap_logic(a);
	swap_logic(b);
	if (print)
		write(1, "ss\n", 3);
}

/* 
-Kaynak yığının (örneğin A) en üstündeki düğümü (top) alırız.
-Bu düğümü bir geçici pointer'da tutarız.
-yığınının yeni top değerini, mevcut top'ın bir sonrakine (next) eşitleriz.
-Eğer yığında hala eleman varsa, yeni top'ın arkasını (prev) NULL yaparız ki liste kopmasın.
-Yığının eleman sayısını (size) bir azaltırız.
2. Takma
-Söktüğümüz düğümü hedef yığının (örneğin B) en tepesine yerleştiririz.
-Hedef boşsa: Düğümün next ve prev değerlerini NULL yaparız ve hedef yığının top pointer'ını bu düğüme odaklarız.
-Hedefte eleman varsa: Düğümün next değerini hedefin mevcut top elemanına bağlarız; 
hedefin eski top elemanının prev değerini ise bizim yeni düğümümüze bağlarız.
Düğümün prev değerini NULL yaparak en üstte olduğunu doğrularız.
*/

void	push(t_stack *to, t_stack *from)
{
	t_node	*node_to_push;

	if (!from || !from->top)
		return ;

	node_to_push = from->top;
	from->top = node_to_push->next;
	if (from->top)
		from->top->prev = NULL;
	from->size--; /* ****burayı tam anlamadım*** */
	if (!to->top)
    {
		node_to_push->next = NULL;
		to->top = node_to_push;
	}
	else
    {
		node_to_push->next = to->top;
		to->top->prev = node_to_push;
		to->top = node_to_push;
	}
	node_to_push->prev = NULL;
	to->size++;
}
void	pa(t_stack *a, t_stack *b, int print)
{
	push(a, b);
	if (print)
		write(1, "pa\n", 3);
}
void	pb(t_stack *a, t_stack *b, int print)
{
	push(b, a);
	if (print)
		write(1, "pb\n", 3);
}