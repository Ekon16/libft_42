/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgodino <jgodino@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 16:48:53 by jgodino           #+#    #+#             */
/*   Updated: 2026/01/20 16:48:54 by jgodino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c);
int	ft_idigit(int c);

int	ft_isalnum(int d)
{
	if (ft_isalpha(d) || ft_isdigit(d))
	{
		return (1);
	}
	return (0);
}

/* int main(void)
{
	ft_isalnum(5);
	return (0);
} */
