/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekart <ekart@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 13:41:23 by ekart             #+#    #+#             */
/*   Updated: 2025/06/25 14:35:01 by ekart            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	ttl;

	ttl = nmemb * size;
	if (nmemb != 0 && ttl / nmemb != size)
		return (NULL);
	ptr = malloc(ttl);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, ttl);
	return (ptr);
}
