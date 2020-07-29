/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstiekem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 11:41:32 by dstiekem          #+#    #+#             */
/*   Updated: 2019/07/04 15:46:26 by dstiekem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *s;

	s = (char *)size;
	if (!s)
		return (NULL);
	if (!(s = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	ft_bzero(s, size + 1);
	return ((char *)s);
}
