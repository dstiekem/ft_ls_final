/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstiekem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 17:22:46 by dstiekem          #+#    #+#             */
/*   Updated: 2019/07/21 11:01:22 by dstiekem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *sub;

	if (!s || !(sub = (char *)malloc(sizeof(char) * (len) + 1)))
		return (NULL);
	sub = ft_strncpy(sub, (char *)s + start, len);
	sub[len] = '\0';
	return (sub);
}
