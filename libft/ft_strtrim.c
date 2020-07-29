/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstiekem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 07:48:01 by dstiekem          #+#    #+#             */
/*   Updated: 2019/06/28 09:15:03 by dstiekem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	unsigned int	i;
	unsigned int	len;
	char			*trim;

	i = 0;
	if (!s)
		return (NULL);
	while (ft_somespaces(s[i]))
		i++;
	len = ft_strlen(s);
	while (len > i && ft_somespaces(s[len - 1]))
		len--;
	trim = ft_strsub(s, i, len - i);
	return (trim);
}
