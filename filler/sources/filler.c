/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecarere <jecarere@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 11:48:57 by jecarere          #+#    #+#             */
/*   Updated: 2020/03/11 17:55:40 by jecarere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void reset(t_game *game)
{
	ft_strdel(&game->pc.piece);
	free(game->op.last_blok);
	game->op.last_blok = NULL;
	// free(game->pl.last_blok);
	// game->pl.last_blok = NULL;
	ft_strdel(&game->pc.piece);
	free(game->pc.blok);
	game->pc.blok = NULL;
	game->pc.n_blok = 0;
	game->pl.n_blok = 0;
	game->op.n_blok = 0;
	game->op.n_last_blok = 0;
	game->pl.n_last_blok = 0;
	game->lap++;
}

int		start_game(t_game *game)
{
	// char *line;
	// int i = -1;

	if ((game->fd_bot = open("./bot_log/log.txt", O_WRONLY| O_CREAT, 0777)) == -1)
		return (0);

	get_players(game);

	while (19)
	{
		ft_putendl_fd("\n########### CACA 1 ###########\n", game->fd_bot);
		get_map(game);
		ft_putendl_fd("\n########### CACA 2 ###########\n", game->fd_bot);
		get_piece(game);
		ft_putendl_fd("\n########### CACA 3 ###########\n", game->fd_bot);
		parse_map(game);
		ft_putendl_fd("\n########### CACA 4 ###########\n", game->fd_bot);
		parse_piece(game);
		ft_putendl_fd("\n########### CACA 5 ###########\n", game->fd_bot);
		// print_game(game, NULL);
		ft_putendl_fd("\n########### CACA 6 ###########\n", game->fd_bot);
		put_piece(game);
		ft_putendl_fd("\n########### CACA 7 ###########\n", game->fd_bot);
		reset(game);
		ft_putendl_fd("\n########### CACA 11 ###########\n", game->fd_bot);
	}
	// while (get_next_line(0, &line) > 0)
	// {
	// 	ft_putstr_fd(line, game->fd_bot);
	// 	ft_putchar_fd('\n', game->fd_bot);
	// }
	return (1);
}

int		main(void)
{
	t_game game;

	init_game(&game);
	start_game(&game);
	close(game.fd_bot);
	return (0);
}
