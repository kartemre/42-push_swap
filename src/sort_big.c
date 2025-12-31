/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekart <ekart@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 17:57:42 by ekart             #+#    #+#             */
/*   Updated: 2025/12/31 06:42:34 by ekart            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	assign_index(t_stack *a)
{
	t_node	*current;
	t_node	*compare;
	int		index;

	current = a->top;
	while (current)
	{
		index = 0;
		compare = a->top;
		while (compare)
		{
			if (current->val > compare->val)
				index++;
			compare = compare->next;
		}
		current->idx = index;
		current = current->next;
	}
}

static int	get_max_bits(int size)
{
	int	max_bits;

	max_bits = 0;
	while (size > 0)
	{
		size >>= 1;
		max_bits++;
	}
	return (max_bits);
}

static void	process_bit(t_stack *a, t_stack *b, int bit)
{
	int	size;
	int	i;

	size = a->size;
	i = 0;
	while (i < size)
	{
		if (((a->top->idx >> bit) & 1) == 0)
			pb(a, b);
		else
			ra(a);
		i++;
	}
}

void	radix_sort(t_stack *a, t_stack *b)
{
	int	max_bits;
	int	bit;

	assign_index(a);
	max_bits = get_max_bits(a->size - 1);
	bit = 0;
	while (bit < max_bits)
	{
		process_bit(a, b, bit);
		while (b->size > 0)
			pa(a, b);
		bit++;
	}
}
