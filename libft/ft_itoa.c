/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstiekem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 14:14:36 by dstiekem          #+#    #+#             */
/*   Updated: 2019/07/14 14:26:23 by dstiekem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa(int n)
{
	char	*s;
	int		j;
	int		neg;

	neg = 1;
	j = ft_digitcount(n);
	if (!(s = (char *)ft_memalloc(j + 1)))
		return (NULL);
	if (n < 0)
	{
		s[0] = '-';
		neg = -1;
	}
	s[j--] = '\0';
	while (j >= 0 && s[j] != '-')
	{
		s[j] = (n % 10) * neg + '0';
		n /= 10;
		j--;
	}
	return (s);
}
