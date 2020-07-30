/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecarere <jecarere@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 18:00:13 by jecarere          #+#    #+#             */
/*   Updated: 2019/10/31 18:00:21 by jecarere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int		parse_piece(t_game *game)
{
	int i;
	int j;

	i = -1;
	while (game->pc.piece[++i])
	{
		if (game->pc.piece[i] == '.')
			NULL;
		else if (game->pc.piece[i] == '*')
			game->pc.n_blok++;
		else
			return (0);
	}
	if (!(game->pc.blok = (int *)malloc(sizeof(int) * (game->pc.n_blok + 1))))
		return (0);
	game->pc.blok[game->pc.n_blok] = -1;
	i = -1;
	j = -1;
	while (game->pc.piece[++i])
	{
		if (game->pc.piece[i] == '*')
			game->pc.blok[++j] = i;
	}
	return (1);
}

int		compare_map(t_game *g)
{
	int i;
	int j;

	i = -1;
	j = -1;
	while (g->map.new_map[++i])
	{
		if ((g->map.new_map[i] == g->op.opponent) && (g->map.old_map[i] == '.'))
			g->op.n_last++;
	}
	if (!(g->op.last = (int *)malloc(sizeof(int) * (g->op.n_last + 1))))
		return (0);
	ft_memset(g->op.last, 0, g->op.n_last);
	g->op.last[g->op.n_last] = -1;
	i = -1;
	while (g->map.new_map[++i])
	{
		if ((g->map.new_map[i] == g->op.opponent) && (g->map.old_map[i] == '.'))
			g->op.last[++j] = i;
	}
	return (1);
}

int		parse_map(t_game *game, int i, int j)
{
	while (game->map.new_map[++i])
	{
		if (game->map.new_map[i] == game->pl.player)
			game->pl.n_blok++;
	}
	if (!(game->pl.blok = (int *)malloc(sizeof(int) * (game->pl.n_blok + 1))))
		return (0);
	game->pl.blok[game->pl.n_blok] = -1;
	ft_memset(game->pl.blok, 0, game->pl.n_blok);
	i = -1;
	while (game->map.new_map[++i])
	{
		if (game->map.new_map[i] == game->pl.player)
			game->pl.blok[++j] = i;
	}
	return (1);
}
