/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpolat <edpolat@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 15:07:18 by edpolat           #+#    #+#             */
/*   Updated: 2026/02/14 14:13:20 by edpolat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
-Kaynak yığının (örneğin A) en üstündeki düğümü (top) alırız.
-Bu düğümü bir geçici pointer'da tutarız.
-yığınının yeni top değerini, mevcut top'ın bir sonrakine (next) eşitleriz.
-Eğer yığında hala eleman varsa, yeni top'ın arkasını (prev) NULL yaparız ki 
liste kopmasın.
-Yığının eleman sayısını (size) bir azaltırız.
2. Takma
-Söktüğümüz düğümü hedef yığının (örneğin B) en tepesine yerleştiririz.
-Hedef boşsa: Düğümün next ve prev değerlerini NULL yaparız ve hedef 
yığının top pointer'ını bu düğüme odaklarız.
-Hedefte eleman varsa: Düğümün next değerini hedefin mevcut top elemanına 
bağlarız; hedefin eski top elemanının prev değerini ise bizim yeni 
düğümümüze bağlarız.
Düğümün prev değerini NULL yaparak en üstte olduğunu doğrularız.
--struct circular olduğu için ilk yazdığım algoritma loop'a giriyordu, düzelttim.
*/

#include "push_swap.h"

t_node	*pop_from_stack(t_stack *from)
{
	t_node	*node;

	if (!from || from->size == 0)
		return (NULL);
	node = from->top;
	if (from->size == 1)
		from->top = NULL;
	else
	{
		node->prev->next = node->next;
		node->next->prev = node->prev;
		from->top = node->next;
	}
	from->size--;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

static void	push_to_stack(t_stack *to, t_node *node)
{
	t_node	*last;

	if (to->size == 0)
	{
		node->next = node;
		node->prev = node;
		to->top = node;
	}
	else
	{
		last = to->top->prev;
		node->next = to->top;
		node->prev = last;
		last->next = node;
		to->top->prev = node;
		to->top = node;
	}
	to->size++;
}

void	push(t_stack *to, t_stack *from)
{
	t_node	*node;

	node = pop_from_stack(from);
	if (!node)
		return ;
	push_to_stack(to, node);
}

void	pa(t_stack *a, t_stack *b, int print, t_control *control)
{
	push(a, b);
	if (print)
		write(1, "pa\n", 3);
	control->op_count++;
}

void	pb(t_stack *a, t_stack *b, int print, t_control *control)
{
	push(b, a);
	if (print)
		write(1, "pb\n", 3);
	control->op_count++;
}
