/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgodino <jgodino@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 07:41:38 by jgodino           #+#    #+#             */
/*   Updated: 2024/10/12 22:10:49 by jgodino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	to_copy;

	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	if (size <= dest_len)
		return (src_len + size);
	to_copy = (src_len >= size - dest_len) ? size - dest_len - 1 : src_len;
	ft_memcpy(dest + dest_len, src, to_copy);
	dest[dest_len + to_copy] = '\0';
	return (dest_len + src_len);
}
