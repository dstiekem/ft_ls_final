/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstiekem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 13:26:50 by dstiekem          #+#    #+#             */
/*   Updated: 2019/07/21 10:25:41 by dstiekem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char const *src)
{
	char	*a;
	int		i;

	if (!(a = (char *)malloc(sizeof(char) * (ft_strlen(src) + 1))))
		return (NULL);
	i = 0;
	while (src[i] != '\0')
	{
		a[i] = src[i];
		i++;
	}
	a[i] = '\0';
	return (a);
}
