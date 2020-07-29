/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstiekem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 13:37:15 by dstiekem          #+#    #+#             */
/*   Updated: 2019/07/03 16:42:26 by dstiekem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				**ft_strsplit(char const *s, char c)
{
	char			**new;
	size_t			len;
	unsigned int	i;
	unsigned int	k;
	unsigned int	start;

	if (!s)
		return (NULL);
	k = wcount(s, c);
	new = NULL;
	if (!(new = (char **)ft_memalloc(sizeof(char *) * (k + 1))))
		return (NULL);
	start = 0;
	i = 0;
	len = 0;
	while (i < k)
	{
		start = len + start;
		while (*(s + start) == c && *(s + start) != '\0')
			start++;
		len = wlen(s + start, c);
		new[i] = ft_strsub(s + start, 0, len);
		i++;
	}
	return (new);
}
