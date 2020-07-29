/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstiekem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 14:46:33 by dstiekem          #+#    #+#             */
/*   Updated: 2019/06/27 15:35:43 by dstiekem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	int				i;
	unsigned char	*p;

	i = 0;
	p = (unsigned char *)s;
	while (n--)
	{
		if (p[i] != (unsigned char)c)
			i++;
		else
			return ((unsigned char *)s + i);
	}
	return (NULL);
}
