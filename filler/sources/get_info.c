/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecarere <jecarere@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 18:00:17 by jecarere          #+#    #+#             */
/*   Updated: 2019/10/31 18:00:18 by jecarere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/filler.h"

int		get_piece(t_game *game)
{
	char	*line;
	int		i;
	int		j;

	if (get_next_line(0, &line) < 0)
		return (0);
	game->pc.li = ft_atoi(ft_strchr(line, ' ') + 1);
	game->pc.col = ft_atoi(ft_strrchr(line, ' ') + 1);
	if ((game->pc.li <= 0) || (game->pc.col <= 0))
		return (0);
	game->pc.size = game->pc.li * game->pc.col;
	if (!(game->pc.piece = ft_strnew(game->pc.size)))
		return (0);
	i = -1;
	j = 0;
	while (++i < game->pc.li)
	{
		if (get_next_line(0, &line) < 0)
			return (0);
		ft_strncpy(game->pc.piece + j, line, game->pc.col);
		j += game->pc.col;
	}
	free(line);

	return (1);
}

int		create_map(t_game *game, char *line)
{
	game->map.li = ft_atoi(ft_strchr(line, ' ') + 1);
	game->map.col = ft_atoi(ft_strrchr(line, ' ') + 1);
	if ((game->map.li <= 0) || (game->map.col <= 0))
		return (0);
	game->map.size = game->map.li * game->map.col;
	if (!(game->map.new_map = ft_strnew(game->map.size)))
		return (0);
	if (!(game->map.old_map = ft_strnew(game->map.size)))
		return (0);
	return (1);
}

int		get_map(t_game *game)
{
	char	*line;
	int		i;
	int		j;

	if (get_next_line(0, &line) < 0)
		return (0);
//	ft_putendl_fd("before map1\n", game->fd_bot);
//	ft_putendl_fd(line, game->fd_bot);
	if (!game->lap)
	{
		if (!create_map(game, line))
			return (0);
	}
	else
		ft_strcpy(game->map.old_map, game->map.new_map);
	if (get_next_line(0, &line) < 0)
		return (0);
	//ft_putendl_fd("before map2\n", game->fd_bot);
	//ft_putendl_fd(line, game->fd_bot);

	i = -1;
	j = 0;
	while (++i < game->map.li)
	{
		//ft_putnbr_fd(i, game->fd_bot);
		//ft_putendl_fd("line\n", game->fd_bot);
		if (get_next_line(0, &line) < 0)
			return (0);
		//ft_putendl_fd("line2", game->fd_bot);
		ft_strncpy(game->map.new_map + j, line + 4, game->map.col);
		j += game->map.col;
	}
	free(line);
	return (1);
}

int		get_players(t_game *game)
{
	char *line;

	if (get_next_line(0, &line) < 0)
		return (0);
	game->pl.player = *(ft_strchr(line, 'p') + 1);
	if ((game->pl.player != '1') && (game->pl.player != '2'))
		return (0);
	game->pl.player = (game->pl.player == '1') ? 'O' : 'X';
	game->op.opponent = (game->pl.player == 'O') ? 'X' : 'O';
	free(line);
	return (1);
}
