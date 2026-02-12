/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder_calculate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpolat <edpolat@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 01:05:53 by edpolat           #+#    #+#             */
/*   Updated: 2026/02/13 01:05:54 by edpolat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Neden İç İçe Döngü?
Örnek bir küme üzerinden gidelim: A = {5, 1, 2}
Dış Döngü (i): "Şu an 5 sayısındayım, benden sonra gelen her şeye bakacağım" der.
İç Döngü (j): 5'ten sonra gelen 1'e bakar (Hata!), sonra 2'ye bakar (Hata!).
Eğer sadece tek döngüyle komşu kontrolü yapsaydın:
5 ile 1'i kıyaslardın (Hata var).
1 ile 2'yi kıyaslardın (Sıralı).
Sonuç: Sadece 1 hata bulurdun. Oysa 5 sayısı hem 1'den hem de 2'den önce geldiği için aslında ortada 2 hata vardır. */

#include "push_swap.h"

float	disorder_calculate(t_stack *stack)
{
	t_node	*a;
	t_node	*b;
	float	mistakes;
	float	total_pairs;

	mistakes = 0;
	total_pairs = 0;
	if (!stack || !stack->top || !stack->top->next)
		return (0.0);
	a = stack->top;
	while (a)
	{
		b = a->next;
		while (b)
		{
			total_pairs++;
			if (a->value > b->value)
				mistakes++;
				
			b = b->next;
		}
		a = a->next;
	}
	return (mistakes / total_pairs);
}
