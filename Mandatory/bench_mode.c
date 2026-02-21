/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_mode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpolat <edpolat@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 00:54:49 by edpolat           #+#    #+#             */
/*   Updated: 2026/02/21 14:27:56 by edpolat          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	enp_putnbr_fd(int n)
{
	char	c;

	if (n == -2147483648)
	{
		write(2, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(2, "-", 1);
		n = -n;
	}
	if (n >= 10)
		enp_putnbr_fd(n / 10);
	c = (n % 10) + '0';
	write(2, &c, 1);
}

void	adaptive_writer(t_control *control)
{
	if (control->adaptive_checker == 1)
		write(2, "Adaptive / O(n²)\n", 20);
	else if (control->adaptive_checker == 2)
		write(2, "Adaptive / O(n√n)\n", 21);
	else if (control->adaptive_checker == 3)
		write(2, "Adaptive / O(nlogn) \n", 22);
}

void	operation_type_writer(t_control *control)
{
	write(2, "sa: ", 5);
	enp_putnbr_fd(control->benchmode.sa);
	write(2, " sb: ", 5);
	enp_putnbr_fd(control->benchmode.sb);
	write(2, " ss: ", 5);
	enp_putnbr_fd(control->benchmode.ss);
	write(2, " pa: ", 4);
	enp_putnbr_fd(control->benchmode.pa);
	write(2, " pb: ", 5);
	enp_putnbr_fd(control->benchmode.pb);
	write(2, "\nra: ", 5);
	enp_putnbr_fd(control->benchmode.ra);
	write(2, " rb: ", 5);
	enp_putnbr_fd(control->benchmode.rb);
	write(2, " rr: ", 5);
	enp_putnbr_fd(control->benchmode.rr);
	write(2, " rra: ", 6);
	enp_putnbr_fd(control->benchmode.rra);
	write(2, " rrb: ", 6);
	enp_putnbr_fd(control->benchmode.rrb);
	write(2, " rrr: ", 6);
	enp_putnbr_fd(control->benchmode.rrr);
	write(2, " ", 1);
}

void	bench_mode_print(t_control *control)
{
	int	x;

	x = (int)(control->disorder * 10000) % 100;
	write(2, "disorder: ", 10);
	enp_putnbr_fd(control->disorder * 100);
	write(2, ".", 1);
	enp_putnbr_fd(x);
	write(2, "%\n", 2);
	if (control->mode == 0)
		adaptive_writer(control);
	else if (control->mode == 1)
		write(2, "strategy: Simple / O(n²)\n", 17);
	else if (control->mode == 2)
		write(2, "strategy: Medium / O(n√n)\n", 17);
	else if (control->mode == 3)
		write(2, "strategy: Complex / O(nlogn) \n", 18);
	write(2, "totat_ops: ", 12);
	enp_putnbr_fd(control->op_count);
	write(2, "\n", 1);
	operation_type_writer(control);
}
