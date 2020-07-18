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
	game->map.new_map = NULL;
	game->map.old_map = NULL;
}

void	init_piece(t_game *game)
{
	game->pc.li = 0;
	game->pc.col = 0;
	game->pc.size = 0;
	game->pc.piece = NULL;
	game->pc.n_blok = 0;
	game->pc.blok = NULL;
	game->pc.placement = NULL;
}

void	init_player(t_game *game)
{
	game->pl.player = 0;
	game->pl.n_blok = 0;
	game->pl.blok = NULL;
}

void	init_opponent(t_game *game)
{
	game->op.opponent = 0;
	game->op.n_last = 0;
	game->op.last = NULL;
}

void init_game(t_game *game)
{
	init_map(game);
	init_piece(game);
	init_player(game);
	init_opponent(game);
	game->lap = 0;
	game->line = NULL;
}
