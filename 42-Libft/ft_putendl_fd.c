/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekart <ekart@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 13:59:02 by ekart             #+#    #+#             */
/*   Updated: 2025/06/25 14:36:03 by ekart            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	char	*ptr;

	if (!s)
		return ;
	ptr = s;
	while (*ptr)
		ptr++;
	write(fd, s, ptr - s);
	write(fd, "\n", 1);
}
