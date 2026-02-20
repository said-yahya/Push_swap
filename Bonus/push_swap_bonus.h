/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpolat <edpolat@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 16:07:42 by edpolat           #+#    #+#             */
/*   Updated: 2026/02/21 01:10:54 by edpolat          ###   ########.fr       */
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
	int			doublecheck;
}				t_control;

t_node	*ft_newnode(int value);
void	ft_addback(t_stack *stack, t_node *new);
void	ft_delone(t_stack *stack, t_node *node);
void	free_matrix(char **str);
void	indexing(t_stack *stack);

/* char	*ft_substr(char *s, unsigned int start, size_t len); */
char	*ft_strjoin_f(char *s1, char *s2);
char	*ft_strchr(char *s, int c);
/* size_t	ft_strlen(char *s); */
char	*line_here(char *remainder);
char	*nextline(char *remainder);
char	*get_next_line(int fd);
void	free_stackss(t_control ctrl);
void	ok_or_ko(t_control ctrl);

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
void	run_adaptive_strategy(t_control *ctrl);
int		parse_and_fill_stack(t_stack **a, int ac, char **av, t_control *ctrl);
int		process_argument_strings(t_stack **a, char *av);

int		ft_isdigit(int c);
char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strdup(const char *s);


#endif
