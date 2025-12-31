/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekart <ekart@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 06:41:30 by ekart             #+#    #+#             */
/*   Updated: 2025/12/31 06:41:42 by ekart            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_puts(const char *s)
{
	ft_putstr_fd((char *)s, 1);
	ft_putchar_fd('\n', 1);
}

void	sa(t_stack *a)
{
	st_swap_top2(a);
	ps_puts("sa");
}

void	sb(t_stack *b)
{
	st_swap_top2(b);
	ps_puts("sb");
}

void	ss(t_stack *a, t_stack *b)
{
	st_swap_top2(a);
	st_swap_top2(b);
	ps_puts("ss");
}
