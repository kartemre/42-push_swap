/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekart <ekart@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 15:28:32 by ekart             #+#    #+#             */
/*   Updated: 2025/08/29 19:40:53 by ekart            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ps_puts(const char *s)
{
    size_t len = 0;
    if (!s)
        return;
    while (s[len])
        len++;
    write(1, s, len);
}

void sa(t_stack *a) { if (a->size >= 2) st_swap_top2(a); ps_puts("sa\n"); }
void sb(t_stack *b) { if (b->size >= 2) st_swap_top2(b); ps_puts("sb\n"); }
void ss(t_stack *a, t_stack *b)
{
	if (a->size >= 2) st_swap_top2(a);
	if (b->size >= 2) st_swap_top2(b);
	ps_puts("ss\n");
}

void pa(t_stack *a, t_stack *b)
{
	t_node *n = st_pop_top(b);
	if (!n) return;          // komut yazmıyoruz; spec: "Do nothing if empty"
	st_push_top(a, n);
	ps_puts("pa\n");
}
void pb(t_stack *a, t_stack *b)
{
	t_node *n = st_pop_top(a);
	if (!n) return;
	st_push_top(b, n);
	ps_puts("pb\n");
}

void ra(t_stack *a) { if (a->size >= 2) st_rotate_up(a);  ps_puts("ra\n"); }
void rb(t_stack *b) { if (b->size >= 2) st_rotate_up(b);  ps_puts("rb\n"); }
void rr(t_stack *a, t_stack *b)
{
	if (a->size >= 2) st_rotate_up(a);
	if (b->size >= 2) st_rotate_up(b);
	ps_puts("rr\n");
}

void rra(t_stack *a) { if (a->size >= 2) st_rotate_down(a); ps_puts("rra\n"); }
void rrb(t_stack *b) { if (b->size >= 2) st_rotate_down(b); ps_puts("rrb\n"); }
void rrr(t_stack *a, t_stack *b)
{
	if (a->size >= 2) st_rotate_down(a);
	if (b->size >= 2) st_rotate_down(b);
	ps_puts("rrr\n");
}

int	ft_atoi(const char *nptr)
{
	int res = 0;
	int sign = 1;
	int i = 0;
	
	while (nptr[i] == '\v' || nptr[i] == '\f'
		|| nptr[i] == '\r' || nptr[i] == '\t'
		|| nptr[i] == '\n' || nptr[i] == ' ')
		i++;
	if (nptr[i] != '\0' && (nptr[i] == '-' || nptr[i] == '+'))
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] && nptr[i] > '0' && nptr[i] < '9')
		res = (res * 10) + (nptr[i++] - '0');
	return (sign * res);
}
