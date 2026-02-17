/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpolat <edpolat@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 16:07:42 by edpolat           #+#    #+#             */
/*   Updated: 2026/02/17 17:06:45 by edpolat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>
# include "push_swap.h"

/* typedef struct s_node
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

typedef struct s_benchmode
{
	int	pa;
	int	pb;
	int	sa;
	int	sb;
	int	ss;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
}		t_benchmode;

typedef struct s_control
{
	t_stack		*a;
	t_stack		*b;
	t_benchmode	benchmode;
	int			mode;
	int			adaptive_checker;
	int			bench;
	float		disorder;
	int			op_count;
}				t_control; */

/* char	*ft_substr(char *s, unsigned int start, size_t len); */
char	*ft_strjoin_f(char *s1, char *s2);
char	*ft_strchr(char *s, int c);
/* size_t	ft_strlen(char *s); */
char	*line_here(char *remainder);
char	*nextline(char *remainder);
char	*get_next_line(int fd);
#endif
