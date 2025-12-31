/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekart <ekart@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 15:28:20 by ekart             #+#    #+#             */
/*   Updated: 2025/12/30 20:05:43 by ekart            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>
# include <stdbool.h>
# include "../42-Libft/libft.h"

typedef struct s_node
{
	int				val;
	int				idx;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	t_node	*bot;
	int		size;
	int		id;
}	t_stack;

void	st_init(t_stack *s, char id);
t_node	*nd_new(int val);
void	st_push_top(t_stack *s, t_node *n);
void	st_push_bottom(t_stack *s, t_node *n);
t_node	*st_pop_top(t_stack *s);
void	st_swap_top2(t_stack *s);
void	st_rotate_up(t_stack *s);
void	st_rotate_down(t_stack *s);
void	st_clear(t_stack *s);

void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);

void	ps_puts(const char *s);

void	error_exit(void);
void	parse_and_fill_stack(t_stack *a, int argc, char **argv);
void	free_split(char **split);
int		is_valid_number(const char *str);
long	ft_atol(const char *str);
int		check_limits(const char *str);
int		has_duplicate(t_stack *stack, int value);

void	print_stack(t_stack *s);
int		is_sorted(t_stack *a);

void	sort_two(t_stack *a);
void	sort_three(t_stack *a);
void	sort_four(t_stack *a, t_stack *b);
void	sort_five(t_stack *a, t_stack *b);
void	radix_sort(t_stack *a, t_stack *b);

#endif
