/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgodino <jgodino@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 23:08:31 by jgodino           #+#    #+#             */
/*   Updated: 2024/10/12 22:09:55 by jgodino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	b;
	void	*p;

	if (count == 0 || size == 0)
	{
		count = 1;
		size = 1;
	}
	if (count > SIZE_MAX / size)
		return (NULL);
	b = count * size;
	p = malloc(b);
	if (p == NULL)
		return (NULL);
	ft_bzero(p, b);
	return (p);
}
