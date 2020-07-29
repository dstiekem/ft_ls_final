/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstiekem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 17:12:13 by dstiekem          #+#    #+#             */
/*   Updated: 2019/06/26 15:38:44 by dstiekem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	int i;

	if (!s1 && !s2)
		return (1);
	else if (!s1 || !s2)
		return (0);
	i = ft_strcmp(s1, s2);
	if (i == 0)
		return (1);
	else
		return (0);
}
