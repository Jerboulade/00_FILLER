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

int	side(t_game *game)
{
	int i;

	i = -1;
	if (!(game->map.north_side = ft_intab(game->map.col)))
		return (0);
	if (!(game->map.east_side = ft_intab(game->map.li)))
		return (0);
	if (!(game->map.south_side = ft_intab(game->map.col)))
		return (0);
	if (!(game->map.west_side = ft_intab(game->map.li)))
		return (0);
	while (++i < game->map.li)
	{
		game->map.east_side[i] = (i * game->map.col) + game->map.col - 1;
		game->map.west_side[i] = (i * game->map.col);
	}
	i = -1;
	while (++i < game->map.col)
	{
		game->map.north_side[i] = i;
		game->map.south_side[i] = i + ((game->map.li - 1) * game->map.col);
	}
	// ##########print#######################################
	// ft_putendl_fd(" ############################", game->fd_bot);
	// i = -1;
	// while (++i < game->map.size)
	// {
	// 	if (!(i % game->map.col))
	// 		ft_putchar_fd('\n', game->fd_bot);
	// 	ft_putnbr_fd(i, game->fd_bot);
	// 	ft_putstr_fd("   ", game->fd_bot);
	// }
	// i = -1;
	// ft_putchar_fd('\n', game->fd_bot);
	// ft_putendl_fd(" east ", game->fd_bot);
	// while (++i < game->map.li)
	// {
	// 	ft_putnbr_fd(game->map.east_side[i], game->fd_bot);
	// 	ft_putchar_fd(' ', game->fd_bot);
	// }
	// ft_putchar_fd('\n', game->fd_bot);
	// i = -1;
	// ft_putendl_fd(" west ", game->fd_bot);
	// while (++i < game->map.li)
	// {
	// 	ft_putnbr_fd(game->map.west_side[i], game->fd_bot);
	// 	ft_putchar_fd(' ', game->fd_bot);
	// }
	// ft_putchar_fd('\n', game->fd_bot);
	// i = -1;
	// ft_putendl_fd(" north ", game->fd_bot);
	// while (++i < game->map.col)
	// {
	// 	ft_putnbr_fd(game->map.north_side[i], game->fd_bot);
	// 	ft_putchar_fd(' ', game->fd_bot);
	// }
	// ft_putchar_fd('\n', game->fd_bot);
	// i = -1;
	// ft_putendl_fd(" south ", game->fd_bot);
	// while (++i < game->map.col)
	// {
	// 	ft_putnbr_fd(game->map.south_side[i], game->fd_bot);
	// 	ft_putchar_fd(' ', game->fd_bot);
	// }
	// ##########print#######################################
	return (1);
}

int	get_piece(t_game *game)
{
	int		i;
	int		j;

	if (get_next_line(0, &game->line) < 0)
		return (0);
	// ft_putendl_fd(game->line, game->fd_bot);
	game->pc.li = ft_atoi(ft_strchr(game->line, ' ') + 1);
	game->pc.col = ft_atoi(ft_strrchr(game->line, ' ') + 1);
	if ((game->pc.li <= 0) || (game->pc.col <= 0))
		return (0);
	game->pc.size = game->pc.li * game->pc.col;
	if (!(game->pc.piece = ft_strnew(game->pc.size)))
		return (0);
	i = -1;
	j = 0;
	ft_strdel(&game->line);
	while (++i < game->pc.li)
	{
		if (get_next_line(0, &game->line) < 0)
			return (0);
		// ft_putendl_fd(game->line, game->fd_bot);
		ft_strncpy(game->pc.piece + j, game->line, game->pc.col);
		j += game->pc.col;
		ft_strdel(&game->line);
	}
	if (!(side(game)))
		return(0);
	return (1);
}

int		create_map(t_game *game)
{
	game->map.li = ft_atoi(ft_strchr(game->line, ' ') + 1);
	game->map.col = ft_atoi(ft_strrchr(game->line, ' ') + 1);
	if ((game->map.li <= 0) || (game->map.col <= 0))
		return (0);
	game->map.size = game->map.li * game->map.col;
	if (!(game->map.new_map = ft_strnew(game->map.size)))
		return (0);
	if (!(game->map.old_map = ft_strnew(game->map.size)))
		return (0);
	return (1);
}

int	get_map(t_game *game, int i, int j)
{
	if (get_next_line(0, &game->line) < 0)
		return (0);
	// ft_putendl_fd(game->line, game->fd_bot);
	if ((!game->line) || (!game->lap && !create_map(game)))
	{
		ft_strdel(&game->line);
		return (0);
	}
	else
		ft_strcpy(game->map.old_map, game->map.new_map);
	ft_strdel(&game->line);
	if (get_next_line(0, &game->line) < 0)
		return (0);
	// ft_putendl_fd(game->line, game->fd_bot);
	ft_strdel(&game->line);
	while (++i < game->map.li)
	{
		if (get_next_line(0, &game->line) < 0)
			return (0);
		// ft_putendl_fd(game->line, game->fd_bot);
		ft_strncpy(game->map.new_map + j, game->line + 4, game->map.col);
		j += game->map.col;
		ft_strdel(&game->line);
	}
	return (1);
}

int	get_players(t_game *game)
{
	game->line = NULL;
	if (get_next_line(0, &game->line) < 0)
		return (0);
	game->pl.player = *(ft_strchr(game->line, 'p') + 1);
	if ((game->pl.player != '1') && (game->pl.player != '2'))
	{
		ft_strdel(&game->line);
		return (0);
	}
	game->pl.player = (game->pl.player == '1') ? 'O' : 'X';
	game->op.opponent = (game->pl.player == 'O') ? 'X' : 'O';
	ft_strdel(&game->line);
	return (1);
}
