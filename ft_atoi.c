/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgodino <jgodino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 00:55:25 by jgodino           #+#    #+#             */
/*   Updated: 2024/10/03 00:31:47 by jgodino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	sign;
	int	result;

	sign = 1;
	result = 0;
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\v'
		|| *str == '\f' || *str == '\r')
	{
		str++;
	}
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
	{
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result * sign);
}

/* int main() {
	const char  str1[] = "   -123";
	const char  str2[] = "456";
	const char  str3[] = "+789";

	printf("Resultado 1: %d\n", ft_atoi( str1));  // -123
	printf("Resultado 2: %d\n", ft_atoi( str2));  // 456
	printf("Resultado 3: %d\n", ft_atoi( str3));  // 789

	return (0);
} */
