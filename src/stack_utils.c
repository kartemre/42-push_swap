/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekart <ekart@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 06:43:32 by ekart             #+#    #+#             */
/*   Updated: 2025/12/31 06:44:08 by ekart            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *a)
{
	t_node	*current;

	if (a->size <= 1)
		return (1);
	current = a->top;
	while (current->next)
	{
		if (current->val > current->next->val)
			return (0);
		current = current->next;
	}
	return (1);
}

void	print_stack(t_stack *s)
{
	t_node	*current;

	current = s->top;
	ft_putstr_fd("Stack ", 1);
	ft_putchar_fd(s->id, 1);
	ft_putstr_fd(": ", 1);
	while (current)
	{
		ft_putnbr_fd(current->val, 1);
		if (current->next)
			ft_putstr_fd(" -> ", 1);
		current = current->next;
	}
	ft_putchar_fd('\n', 1);
}
