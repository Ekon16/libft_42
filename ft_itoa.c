/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgodino <jgodino@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 22:14:44 by jgodino           #+#    #+#             */
/*   Updated: 2024/10/12 22:14:45 by jgodino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numlen(int n)
{
	int	len;

	len = (n <= 0) ? 1 : 0;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	number;
	int		len;

	number = n;
	len = ft_numlen(number);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len--] = '\0';
	if (number < 0)
	{
		str[0] = '-';
		number = -number;
	}
	while (len >= 0 && str[len] != '-')
	{
		str[len--] = (number % 10) + '0';
		number /= 10;
	}
	return (str);
}
