/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekart <ekart@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 17:57:41 by ekart             #+#    #+#             */
/*   Updated: 2025/12/31 06:42:57 by ekart            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_min_pos(t_stack *s)
{
	t_node	*current;
	int		min_val;
	int		min_pos;
	int		pos;

	current = s->top;
	min_val = current->val;
	min_pos = 0;
	pos = 0;
	while (current)
	{
		if (current->val < min_val)
		{
			min_val = current->val;
			min_pos = pos;
		}
		current = current->next;
		pos++;
	}
	return (min_pos);
}

void	sort_two(t_stack *a)
{
	if (a->top->val > a->top->next->val)
		sa(a);
}

void	sort_three(t_stack *a)
{
	int	top;
	int	mid;
	int	bot;

	top = a->top->val;
	mid = a->top->next->val;
	bot = a->bot->val;
	if (top > mid && mid < bot && top < bot)
		sa(a);
	else if (top > mid && mid > bot)
	{
		sa(a);
		rra(a);
	}
	else if (top > mid && mid < bot && top > bot)
		ra(a);
	else if (top < mid && mid > bot && top < bot)
	{
		sa(a);
		ra(a);
	}
	else if (top < mid && mid > bot && top > bot)
		rra(a);
}

void	sort_four(t_stack *a, t_stack *b)
{
	int	min_pos;

	min_pos = find_min_pos(a);
	if (min_pos == 1)
		sa(a);
	else if (min_pos == 2)
	{
		rra(a);
		rra(a);
	}
	else if (min_pos == 3)
		rra(a);
	pb(a, b);
	sort_three(a);
	pa(a, b);
}

void	sort_five(t_stack *a, t_stack *b)
{
	int	min_pos;

	min_pos = find_min_pos(a);
	if (min_pos == 1)
		sa(a);
	else if (min_pos == 2)
	{
		ra(a);
		ra(a);
	}
	else if (min_pos == 3)
	{
		rra(a);
		rra(a);
	}
	else if (min_pos == 4)
		rra(a);
	pb(a, b);
	sort_four(a, b);
	pa(a, b);
}
