/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekart <ekart@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 15:28:28 by ekart             #+#    #+#             */
/*   Updated: 2026/01/24 10:56:53 by ekart            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	do_sort(t_stack *a, t_stack *b)
{
	if (a->size == 2)
		sort_two(a);
	else if (a->size == 3)
		sort_three(a);
	else if (a->size == 4)
		sort_four(a, b);
	else if (a->size == 5)
		sort_five(a, b);
	else
		radix_sort(a, b);
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	if (argc < 2)
		return (0);
	st_init(&a, 'a');
	st_init(&b, 'b');
	if (!parse_and_fill_stack(&a, argc, argv))
	{
		st_clear(&a);
		st_clear(&b);
		write(2, "Error\n", 6);
		return (1);
	}
	if (is_sorted(&a))
	{
		st_clear(&a);
		st_clear(&b);
		return (0);
	}
	do_sort(&a, &b);
	st_clear(&a);
	st_clear(&b);
	return (0);
}
