/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstiekem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 16:45:55 by dstiekem          #+#    #+#             */
/*   Updated: 2019/09/18 08:54:22 by dstiekem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "libft.h"

ssize_t			read_stuff(int fd, char **hold)
{
	char		buff[BUFF_SIZE + 1];
	char		*tmp;
	ssize_t		bytes;

	while (!(ft_strchr(*hold, '\n')))
	{
		bytes = read(fd, buff, BUFF_SIZE);
		if (bytes < 1)
			break ;
		buff[bytes] = '\0';
		tmp = ft_strjoin(*hold, buff);
		free(*hold);
		*hold = tmp;
	}
	return (bytes);
}

void			hold_stuff(char **hold, char **line)
{
	char		*nextline;
	char		*tmp;
	int			len;

	if ((nextline = ft_strchr(*hold, '\n')))
	{
		len = nextline - *hold;
		*line = ft_strsub(*hold, 0, len);
		tmp = ft_strdup(nextline + 1);
		free(*hold);
		*hold = tmp;
	}
	else
	{
		*line = *hold;
		*hold = NULL;
	}
}

int				get_next_line(const int fd, char **line)
{
	static char	*hold[MAX_FD];

	if (fd < 0 || !line || fd > MAX_FD || read(fd, hold[fd], 0) < 0)
		return (-1);
	if (hold[fd] == NULL)
		hold[fd] = ft_strnew(0);
	if (read_stuff(fd, &hold[fd]) < 0)
		return (-1);
	if (ft_strlen(hold[fd]) == 0)
		return (0);
	hold_stuff(&hold[fd], line);
	return (1);
}
