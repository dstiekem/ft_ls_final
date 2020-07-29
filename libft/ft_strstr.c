/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstiekem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 14:15:38 by dstiekem          #+#    #+#             */
/*   Updated: 2019/06/20 14:12:29 by dstiekem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int h;
	int n;
	int i;

	h = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[h])
	{
		i = 0;
		n = 0;
		while (needle[n] == haystack[h + i])
		{
			i++;
			n++;
			if (needle[n] == '\0')
				return ((char *)&haystack[h]);
		}
		h++;
	}
	if (haystack[0] == '\0')
		return (NULL);
	return (0);
}
