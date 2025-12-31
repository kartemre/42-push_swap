/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekart <ekart@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 06:43:04 by ekart             #+#    #+#             */
/*   Updated: 2025/12/31 06:44:53 by ekart            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	st_rotate_up(t_stack *s)
{
	t_node	*n;

	if (s->size < 2)
		return ;
	n = st_pop_top(s);
	n->next = NULL;
	n->prev = s->bot;
	s->bot->next = n;
	s->bot = n;
	s->size++;
}

void	st_rotate_down(t_stack *s)
{
	t_node	*n;

	if (s->size < 2)
		return ;
	n = s->bot;
	s->bot = n->prev;
	s->bot->next = NULL;
	n->prev = NULL;
	n->next = s->top;
	s->top->prev = n;
	s->top = n;
}

void	st_push_bottom(t_stack *s, t_node *n)
{
	if (!n)
		return ;
	if (s->size == 0)
	{
		s->top = n;
		s->bot = n;
		n->prev = NULL;
		n->next = NULL;
		s->size = 1;
		return ;
	}
	n->next = NULL;
	n->prev = s->bot;
	s->bot->next = n;
	s->bot = n;
	s->size++;
}

void	st_clear(t_stack *s)
{
	t_node	*it;
	t_node	*next;

	it = s->top;
	while (it)
	{
		next = it->next;
		free(it);
		it = next;
	}
	st_init(s, s->id);
}
