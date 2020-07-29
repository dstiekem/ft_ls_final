/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstiekem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 10:17:05 by dstiekem          #+#    #+#             */
/*   Updated: 2019/06/25 07:21:06 by dstiekem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	int		h;
	char	*s2;

	i = 0;
	if (!s || !f)
		return (NULL);
	h = ft_strlen(s);
	if (!(s2 = (char *)malloc(sizeof(char) * (h + 1))))
		return (NULL);
	while (i < h)
	{
		s2[i] = f(s[i]);
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
