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

int		get_map_nb_blok(t_game *game)
{
	int i;

	i = -1;
	while (game->map.map[++i])
	{
		if (game->map.map[i] == '.')
			NULL;
		else if ((game->map.map[i] == 'X') || (game->map.map[i] == 'O'))
			check_block(game, game->map.map[i]);
		// else if (game->map.map[i] == (game->op.opponent + 32))
		// 	game->op.n_last_blok++;
		// else if (game->map.map[i] == (game->pl.player))
		// 	game->pl.n_blok++;
		else
			return (0);
	}
	// game->op.n_blok += (!game->lap && game->pl.player == 'O') ? 0 : game->op.n_last_blok;
	return (1);
}

// int get_player_last_block_position()
// {
//
// }

int		get_map_blok_position(t_game *game)
{
	int i;
	int j;
	int k;

	i = -1;
	j = -1;
	k = -1;
	if (!(game->op.last_blok = (int *)malloc(sizeof(int) * (game->op.n_last_blok + 1))))
		return (0);
	if (!(game->pl.blok = (int *)malloc(sizeof(int) * (game->pl.n_blok + 1))))
		return (0);
	game->pl.blok[game->pl.n_blok] = -1;
	game->op.last_blok[game->op.n_last_blok] = -1;
	while (game->op.last_blok[++i] != -1)
		game->op.last_blok[i] = 0;
	i = -1;
	while (game->map.map[++i])
	{
		if (game->map.map[i] == '.' || ((game->map.map[i] == game->op.opponent) && game->lap))
		{
			NULL;
			// ft_putnbr_fd(i, game->fd_bot);
			// ft_putendl_fd("\n## 1 check point --------------\n", game->fd_bot);
		}
		else if (!game->lap && (game->map.map[i] == game->pl.player))
		{
			game->pl.first_blok = i;
			// ft_putnbr_fd(i, game->fd_bot);
			// ft_putendl_fd("\n## 2 check point --------------\n", game->fd_bot);
		}
		else if (game->lap && (game->map.map[i] == game->pl.player))
		{
			game->pl.blok[++k] = i;
			// ft_putnbr_fd(i, game->fd_bot);
			// ft_putendl_fd("\n## 2.5 check point --------------\n", game->fd_bot);
		}
		else if (!game->lap && (game->map.map[i] == game->op.opponent))
		{
			game->op.last_blok[0] = i;
			// ft_putnbr_fd(i, game->fd_bot);
			// ft_putendl_fd("\n## 3 check point --------------\n", game->fd_bot);
		}
		else if (game->map.map[i] == (game->op.opponent + 32))
		{
			game->op.last_blok[++j] = i;
			// ft_putnbr_fd(i, game->fd_bot);
			// ft_putendl_fd("\n## 4 check point --------------\n", game->fd_bot);
		}
		else
		{
			// ft_putnbr_fd(i, game->fd_bot);
			// ft_putendl_fd("\n## 5 check point --------------\n", game->fd_bot);
			return (0);
		}
	}
	return (1);
}

int		parse_map(t_game *game)
{
	get_map_nb_blok(game);
	get_map_blok_position(game);
	return (1);
}
