/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgodino <jgodino@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 19:21:51 by jgodino           #+#    #+#             */
/*   Updated: 2024/10/12 22:14:36 by jgodino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s = src;

	d = dest;
	if (dest == NULL && src == NULL)
		return (NULL);
	while (n--)
	{
		*d++ = *s++;
	}
	return (dest);
}
