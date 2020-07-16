/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecarere <jecarere@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 19:47:17 by jecarere          #+#    #+#             */
/*   Updated: 2020/03/11 13:22:24 by jecarere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	find_line(char **stock, char **line, int line_end, int fd)
{
	int		line_length;
	char	*tmps;

	line_length = ft_strchr(stock[fd], line_end) - stock[fd];
	if (!(*line = ft_strsub(stock[fd], 0, line_length)))
		return (-1);
	if (!line_end)
	{
		ft_strclr(stock[fd]);
		return (1);
	}
	stock[fd] += line_length + 1;
	tmps = ft_strdup(stock[fd]);
	stock[fd] -= line_length + 1;
	ft_strdel(&stock[fd]);
	stock[fd] = tmps;
	return (1);
}

static char	*stock_buff(char *buff, char **stock, int fd)
{
	char			*tmps;

	if (!stock[fd])
	{
		if (!(tmps = ft_strdup(buff)))
			return (NULL);
	}
	else
	{
		if (!(tmps = ft_strjoin(stock[fd], buff)))
			return (NULL);
	}
	return (tmps);
}

int			get_next_line(const int fd, char **line)
{
	static char		*stock[OPEN_MAX];
	char			buff[BUFF_SIZE + 1];
	int				size;
	char			*tmps;

	if (fd < 0 || fd > OPEN_MAX || !line || read(fd, buff, 0) == -1)
		return (-1);
	if (!stock[fd])
		stock[fd] = ft_strnew(1);
	if (stock[fd] && ft_strchr(stock[fd], '\n'))
		return (find_line(stock, line, '\n', fd));
	while ((size = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[size] = 0;
		if (!(tmps = stock_buff(buff, stock, fd)))
			return (-1);
		ft_strdel(&stock[fd]);
		stock[fd] = tmps;
		if (ft_strchr(stock[fd], '\n'))
			return (find_line(stock, line, '\n', fd));
	}
	if (size < BUFF_SIZE && !ft_strchr(stock[fd], '\n') && *stock[fd])
		return (find_line(stock, line, '\0', fd));
	*line = NULL;
	return (0);
}
