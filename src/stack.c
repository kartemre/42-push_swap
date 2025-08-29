/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekart <ekart@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 15:28:36 by ekart             #+#    #+#             */
/*   Updated: 2025/08/29 17:05:34 by ekart            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	st_init(t_stack *s, char id){
	s->top = NULL;
	s->bot = NULL;
	s->size = 0;
	s->id = id;
}

t_node	*nd_new(int val)
{
	t_node *n = (t_node*)malloc(sizeof(t_node));
	if (!n) return NULL;
	n->val = val;
	n->idx = -1;
	n->prev = NULL;
	n->next = NULL;
	return n;
}

static void _link_as_only(t_stack *s, t_node *n)
{
	s->top = n;
	s->bot = n;
	n->prev = NULL;
	n->next = NULL;
	s->size = 1; 
}

void    st_push_top(t_stack *s, t_node *n)
{
	if (!n) return;
	if (s->size == 0)
		return _link_as_only(s, n);
	n->prev = NULL;
	n->next = s->top;
	s->top->prev = n;
	s->top = n;
	s->size++;
}

t_node *st_pop_top(t_stack *s)
{
	t_node *n;
	if (s->size == 0) return NULL;
	n = s->top;
	if (s->size == 1) {
		s->top = NULL;
		s->bot = NULL;
		s->size = 0;
		return n;
	}
	s->top = n->next;
	s->top->prev = NULL;
	n->next = NULL;
	s->size--;
	return n;
}

void st_swap_top2(t_stack *s)
{
	t_node *a, *b;
	if (s->size < 2) return;
	a = s->top;
	b = a->next;
	a->next = b->next;
	if (b->next) b->next->prev = a;
	else s->bot = a;
	b->prev = NULL;
	b->next = a;
	a->prev = b;
	s->top = b;
}

void st_rotate_up(t_stack *s)
{
	t_node *n;
	if (s->size < 2) return;
	n = st_pop_top(s);
	// push to bottom
	n->next = NULL;
	n->prev = s->bot;
	s->bot->next = n;
	s->bot = n;
	s->size++; // st_pop_top azalttı, geri artır
}

void st_rotate_down(t_stack *s)
{
	t_node *n;
	if (s->size < 2) return;
	n = s->bot;
	// detach bottom
	s->bot = n->prev;
	s->bot->next = NULL;
	n->prev = NULL;
	// push to top
	n->next = s->top;
	s->top->prev = n;
	s->top = n;
	/* size değişmedi */
}

void st_clear(t_stack *s)
{
	t_node *it = s->top, *next;
	while (it) { next = it->next; free(it); it = next; }
	st_init(s, s->id);
}
