/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstiekem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 12:50:40 by dstiekem          #+#    #+#             */
/*   Updated: 2019/06/28 07:45:21 by dstiekem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t i;
	size_t j;
	size_t ds_l;
	size_t sr_l;

	i = 0;
	j = 0;
	sr_l = ft_strlen(src);
	ds_l = ft_strlen(dst);
	if (dstsize <= ds_l)
		return (dstsize + sr_l);
	while (dst[i] && i < dstsize - 1)
		i++;
	while (src[j] && i < dstsize - 1)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (ds_l + sr_l);
}
