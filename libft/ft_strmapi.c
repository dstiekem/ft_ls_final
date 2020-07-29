/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstiekem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 13:37:22 by dstiekem          #+#    #+#             */
/*   Updated: 2019/06/25 07:21:53 by dstiekem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	unsigned int	h;
	char			*s2;

	i = 0;
	if (!s || !f)
		return (NULL);
	h = ft_strlen(s);
	if (!(s2 = (char *)malloc(sizeof(char) * (h + 1))))
		return (NULL);
	while (i < h)
	{
		s2[i] = f(i, s[i]);
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
