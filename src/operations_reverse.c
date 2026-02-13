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
-ra ve rra formatının farkı aşağı ya da yukarı gitmek plduğundan
ra-rra aynı fonksiyonda, rb-rrb aynı fonksiyonda, rb-rrb aynı fonksiyonda 
yönetilecek şekilde yazmaya çalıştım, kontrolünü de i = 1 ve i =-1 ile yapar 
iki döngüyü tek fonksiyona atarız. */

