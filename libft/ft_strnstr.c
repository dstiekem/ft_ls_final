/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstiekem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 10:55:09 by dstiekem          #+#    #+#             */
/*   Updated: 2019/06/20 14:10:18 by dstiekem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t h;
	size_t n;
	size_t i;
	size_t j;

	h = 0;
	i = ft_strlen(needle);
	if (needle[0] == '\0')
		return ((char *)haystack);
	while ((haystack[h]) && (i + h <= len))
	{
		n = 0;
		j = 0;
		while (needle[n] == haystack[h + j] && h + j <= len)
		{
			n++;
			j++;
			if (needle[n] == '\0')
				return ((char *)&haystack[h]);
		}
		h++;
	}
	if (haystack[h] == '\0')
		return (NULL);
	return (0);
}
