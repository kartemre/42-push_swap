/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekart <ekart@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 15:28:28 by ekart             #+#    #+#             */
/*   Updated: 2025/08/29 18:00:17 by ekart            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	(void)argc; (void)argv;

	t_stack a, b;
	st_init(&a, 'a'); st_init(&b, 'b');
	st_push_top(&a, nd_new(3));
	st_push_top(&a, nd_new(2));
	st_push_top(&a, nd_new(1));
	// tek hamlede sırala: ra
	ra(&a); // çıktı: "ra\n"
	st_clear(&a); st_clear(&b);

	return 0;
}
