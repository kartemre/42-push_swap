/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekart <ekart@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 13:51:52 by ekart             #+#    #+#             */
/*   Updated: 2025/06/25 14:36:17 by ekart            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	i;
	char	*sdup;

	i = ft_strlen(s);
	sdup = malloc((i + 1) * sizeof(char));
	if (!sdup)
		return (NULL);
	ft_memcpy(sdup, s, i);
	sdup[i] = '\0';
	return (sdup);
}
