/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekart <ekart@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 15:28:28 by ekart             #+#    #+#             */
/*   Updated: 2025/08/29 19:44:06 by ekart            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	int x;
	t_stack a, b;
	st_init(&a, 'a'); st_init(&b, 'b');
	if (argc == 4)
	{
		x = ft_atoi(argv[1]);
		st_push_top(&a, nd_new(x));
		x = ft_atoi(argv[2]);
		st_push_top(&a, nd_new(x));
		x = ft_atoi(argv[3]);
		st_push_top(&a, nd_new(x));
		// tek hamlede sırala: ra
		ra(&a);
		st_clear(&a); st_clear(&b);
	}
	return 0;
}
