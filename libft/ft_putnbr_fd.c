/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstiekem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 11:59:15 by dstiekem          #+#    #+#             */
/*   Updated: 2019/06/25 07:18:11 by dstiekem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (fd > 0)
	{
		if (n == -2147483648)
			ft_putstr_fd("-2147483648", fd);
		else
		{
			if (n < 0)
			{
				ft_putchar_fd('-', fd);
				ft_putnbr_fd(-n, fd);
			}
			else if (n > 9)
			{
				ft_putnbr_fd((n / 10), fd);
				ft_putnbr_fd((n % 10), fd);
			}
			else
			{
				n += 48;
				ft_putchar_fd(n, fd);
			}
		}
	}
}
