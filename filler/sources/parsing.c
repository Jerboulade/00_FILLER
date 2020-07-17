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

int		compare_map(t_game *game)
{
	int i;
	int j;

	i = -1;
	j = -1;
	while (game->map.new_map[++i])
	{
		if ((game->map.new_map[i] == game->op.opponent) && (game->map.old_map[i] == '.'))
			game->op.n_last_blok++;
	}
	if (!(game->op.last_blok = (int *)malloc(sizeof(int) * (game->op.n_last_blok + 1))))
		return (0);
	ft_memset(game->op.last_blok, 0, game->op.n_last_blok);
	game->op.last_blok[game->op.n_last_blok] = -1;
	i = -1;
	while (game->map.new_map[++i])
	{
		if ((game->map.new_map[i] == game->op.opponent) && (game->map.old_map[i] == '.'))
			game->op.last_blok[++j] = i;
	}
	// ## PRINT ##############################################################
	// ft_putendl_fd("\n## Opponent last block ##############\n", game->fd_bot);
	// i = -1;
	// j = -1;
	// while (game->op.last_blok[++i] != -1)
	// {
	// 	ft_putchar_fd('(', game->fd_bot);
	// 	ft_putnbr_fd(game->op.last_blok[i], game->fd_bot);
	// 	ft_putchar_fd(')', game->fd_bot);
	// }
	// ft_putchar_fd('\n', game->fd_bot);
	// ## END PRINT ##########################################################

	return (1);
}

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

int		parse_map(t_game *game, int i, int j, int k)
{
	while (game->map.new_map[++i])
	{
		if (game->map.new_map[i] == game->pl.player)
			game->pl.n_blok++;
		else if (game->map.new_map[i] == game->op.opponent)
			game->op.n_blok++;
	}
	if (!(game->op.blok = (int *)malloc(sizeof(int) * (game->op.n_blok + 1))))
		return (0);
	if (!(game->pl.blok = (int *)malloc(sizeof(int) * (game->pl.n_blok + 1))))
		return (0);
	game->pl.blok[game->pl.n_blok] = -1;
	game->op.blok[game->op.n_blok] = -1;
	ft_memset(game->pl.blok, 0, game->pl.n_blok);
	ft_memset(game->op.blok, 0, game->op.n_blok);
	i = -1;
	while (game->map.new_map[++i])
	{
		if (game->map.new_map[i] == game->pl.player)
			game->pl.blok[++j] = i;
		else if (game->map.new_map[i] == game->op.opponent)
			game->op.blok[++k] = i;
	}
	return (1);
}
