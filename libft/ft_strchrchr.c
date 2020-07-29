/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstiekem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 17:51:20 by dstiekem          #+#    #+#             */
/*   Updated: 2019/07/26 16:03:58 by dstiekem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*returns the character*/
#include "libft.h"

char	ft_strchrchr(const char *s, int c)
{
	char *str;
	char cc;

	str = (char *)s;
	cc = (char)c;
	if (!s)
		return ('\0');
	while (*str != '\0')
	{
		if (*str == cc)
			return (*str);
		str++;
	}
	if (*str == '\0' && cc == '\0')
		return (*str);
	return ('\0');
}
