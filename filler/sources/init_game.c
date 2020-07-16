/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecarere <jecarere@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 12:15:12 by jecarere          #+#    #+#             */
/*   Updated: 2019/10/31 16:44:42 by jecarere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
# include "../includes/filler.h"


void	init_map(t_game *game)
{
	game->map.li = 0;
	game->map.col = 0;
	game->map.size = 0;
	game->map.map = NULL;
}

void	init_piece(t_game *game)
{
		game->pc.blok = NULL;
		game->pc.n_blok = 0;
}

void	init_player(t_game *game)
{
	game->pl.player = 0;
	game->pl.n_blok = 0;
	game->pl.n_last_blok = 1;
}

void	init_opponent(t_game *game)
{
	game->op.opponent = 0;
	game->op.n_blok = 0;
	game->pl.n_last_blok = 1;
}

void init_game(t_game *game)
{
	init_map(game);
	init_piece(game);
	init_player(game);
	init_opponent(game);
	game->lap = 0;
}
