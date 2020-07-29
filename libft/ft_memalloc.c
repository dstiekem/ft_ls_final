/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstiekem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 08:07:30 by dstiekem          #+#    #+#             */
/*   Updated: 2019/06/28 07:40:00 by dstiekem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *c;

	if (!(c = malloc(sizeof(size_t) * (size))))
		return (NULL);
	else
		ft_bzero(c, size);
	return (c);
}
