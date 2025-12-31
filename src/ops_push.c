/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekart <ekart@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 06:40:02 by ekart             #+#    #+#             */
/*   Updated: 2025/12/31 06:40:48 by ekart            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack *a, t_stack *b)
{
	t_node	*n;

	n = st_pop_top(b);
	if (n)
	{
		st_push_top(a, n);
		ps_puts("pa");
	}
}

void	pb(t_stack *a, t_stack *b)
{
	t_node	*n;

	n = st_pop_top(a);
	if (n)
	{
		st_push_top(b, n);
		ps_puts("pb");
	}
}
