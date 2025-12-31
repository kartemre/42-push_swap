/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekart <ekart@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 15:28:36 by ekart             #+#    #+#             */
/*   Updated: 2025/12/30 19:00:00 by ekart            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	st_init(t_stack *s, char id)
{
	s->top = NULL;
	s->bot = NULL;
	s->size = 0;
	s->id = id;
}

t_node	*nd_new(int val)
{
	t_node	*n;

	n = (t_node *)malloc(sizeof(t_node));
	if (!n)
		return (NULL);
	n->val = val;
	n->idx = -1;
	n->prev = NULL;
	n->next = NULL;
	return (n);
}

static void	_link_as_only(t_stack *s, t_node *n)
{
	s->top = n;
	s->bot = n;
	n->prev = NULL;
	n->next = NULL;
	s->size = 1;
}

void	st_push_top(t_stack *s, t_node *n)
{
	if (!n)
		return ;
	if (s->size == 0)
		return (_link_as_only(s, n));
	n->prev = NULL;
	n->next = s->top;
	s->top->prev = n;
	s->top = n;
	s->size++;
}

t_node	*st_pop_top(t_stack *s)
{
	t_node	*n;

	if (s->size == 0)
		return (NULL);
	n = s->top;
	if (s->size == 1)
	{
		s->top = NULL;
		s->bot = NULL;
		s->size = 0;
		return (n);
	}
	s->top = n->next;
	s->top->prev = NULL;
	n->next = NULL;
	s->size--;
	return (n);
}
