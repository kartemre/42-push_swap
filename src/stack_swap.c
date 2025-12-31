/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekart <ekart@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 06:43:16 by ekart             #+#    #+#             */
/*   Updated: 2025/12/31 06:44:42 by ekart            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	st_swap_top2(t_stack *s)
{
	t_node	*a;
	t_node	*b;

	if (s->size < 2)
		return ;
	a = s->top;
	b = a->next;
	a->next = b->next;
	if (b->next)
		b->next->prev = a;
	else
		s->bot = a;
	b->prev = NULL;
	b->next = a;
	a->prev = b;
	s->top = b;
}
