/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekart <ekart@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 06:41:01 by ekart             #+#    #+#             */
/*   Updated: 2025/12/31 06:41:12 by ekart            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

void	ra(t_stack *a)
{
	st_rotate_up(a);
	ps_puts("ra");
}

void	rb(t_stack *b)
{
	st_rotate_up(b);
	ps_puts("rb");
}

void	rr(t_stack *a, t_stack *b)
{
	st_rotate_up(a);
	st_rotate_up(b);
	ps_puts("rr");
}

void	rra(t_stack *a)
{
	st_rotate_down(a);
	ps_puts("rra");
}

void	rrb(t_stack *b)
{
	st_rotate_down(b);
	ps_puts("rrb");
}
