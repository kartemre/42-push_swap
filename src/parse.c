/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekart <ekart@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 10:25:51 by ekart             #+#    #+#             */
/*   Updated: 2026/01/24 10:56:53 by ekart            ###   ########.fr       */
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

static int	process_number(t_stack *a, char *str)
{
	int		value;
	t_node	*node;

	if (!is_valid_number(str) || !check_limits(str))
		return (0);
	value = ft_atoi(str);
	if (has_duplicate(a, value))
		return (0);
	node = nd_new(value);
	if (!node)
		return (0);
	st_push_bottom(a, node);
	return (1);
}

static int	process_split(t_stack *a, char **split)
{
	int	j;

	if (!split || !split[0])
		return (0);
	j = 0;
	while (split[j])
	{
		if (!process_number(a, split[j]))
			return (0);
		j++;
	}
	return (1);
}

int	parse_and_fill_stack(t_stack *a, int argc, char **argv)
{
	int		i;
	char	**split;

	i = 1;
	while (i < argc)
	{
		split = ft_split(argv[i], ' ');
		if (!process_split(a, split))
		{
			free_split(split);
			return (0);
		}
		free_split(split);
		i++;
	}
	return (1);
}
