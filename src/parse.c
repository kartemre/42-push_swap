/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekart <ekart@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 10:25:51 by ekart             #+#    #+#             */
/*   Updated: 2025/12/31 10:26:09 by ekart            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

static void	process_number(t_stack *a, char *str)
{
	int		value;
	t_node	*node;

	if (!is_valid_number(str) || !check_limits(str))
		error_exit();
	value = ft_atoi(str);
	if (has_duplicate(a, value))
		error_exit();
	node = nd_new(value);
	if (!node)
		error_exit();
	st_push_bottom(a, node);
}

static void	process_split(t_stack *a, char **split)
{
	int	j;

	if (!split || !split[0])
		error_exit();
	j = 0;
	while (split[j])
	{
		process_number(a, split[j]);
		j++;
	}
}

void	parse_and_fill_stack(t_stack *a, int argc, char **argv)
{
	int		i;
	char	**split;

	i = 1;
	while (i < argc)
	{
		split = ft_split(argv[i], ' ');
		process_split(a, split);
		free_split(split);
		i++;
	}
}
