/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecarere <jecarere@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 12:15:12 by jecarere          #+#    #+#             */
/*   Updated: 2019/10/31 16:44:42 by jecarere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int 	absolute_distance(t_game *g, int i, int j, int k)
{
	float dx;
	float dy;

	dx = 0;
	dy = 0;
	dx = (g->pc.place[i][j] % g->map.col) - (g->op.last[k] % g->map.col);
	dx *= (dx < 0) ? -1 : 1;
	dy = (g->pc.place[i][j] / g->map.col) - (g->op.last[k] / g->map.col);
	dy *= (dy < 0) ? -1 : 1;
	// ft_putstr_fd("\nlap ", g->fd_bot);
	// ft_putnbr_fd(g->lap, g->fd_bot);
	// ft_putstr_fd("\n   dx: ", g->fd_bot);
	// ft_putnbr_fd(dx, g->fd_bot);
	// ft_putstr_fd("\n   dy: ", g->fd_bot);
	// ft_putnbr_fd(dy, g->fd_bot);

	return (sqrt((dx * dx) + (dy * dy)));
}

int		check_surround(t_game *game, int i, int j)
{
	int nb;

	nb = 0;
	if ((((game->pc.place[i][j] + 1) % game->map.col) < game->map.col) \
	&& (game->map.new_map[game->pc.place[i][j] + 1] == game->op.opponent))
		nb++;
	if ((((game->pc.place[i][j] - 1) % game->map.col) >= 0) \
	&& (game->map.new_map[game->pc.place[i][j] - 1] == game->op.opponent))
		nb++;

	if ((((game->pc.place[i][j] + game->map.col) / game->map.col) < game->map.li) \
	&& (game->map.new_map[game->pc.place[i][j] + game->map.col] == game->op.opponent))
		nb++;
	if ((((game->pc.place[i][j] + game->map.col + 1) / game->map.col) < game->map.li) \
	&& (game->map.new_map[game->pc.place[i][j] + game->map.col + 1] == game->op.opponent) \
	&& (((game->pc.place[i][j] + game->map.col + 1) / game->map.col) < game->map.col))
		nb++;
	if ((((game->pc.place[i][j] + game->map.col - 1) / game->map.col) < game->map.li) \
	&& (game->map.new_map[game->pc.place[i][j] + game->map.col - 1] == game->op.opponent) \
	&& (((game->pc.place[i][j] + game->map.col - 1) / game->map.col) >= 0))
		nb++;

	if ((((game->pc.place[i][j] - game->map.col) / game->map.col) >= 0) \
	&& (game->map.new_map[game->pc.place[i][j] - game->map.col] == game->op.opponent))
		nb++;
	if ((((game->pc.place[i][j] - game->map.col + 1) / game->map.col) >= 0) \
	&& (game->map.new_map[game->pc.place[i][j] - game->map.col + 1] == game->op.opponent) \
	&& (((game->pc.place[i][j] - game->map.col + 1) / game->map.col) < game->map.col))
		nb++;
	if (((game->pc.place[i][j] - game->map.col - 1) / game->map.col) >= 0 \
	&& (game->map.new_map[game->pc.place[i][j] - game->map.col - 1] == game->op.opponent) \
	&& (((game->pc.place[i][j] - game->map.col - 1) / game->map.col) >= 0))
		nb++;
	return (nb);
}

int		cut(t_game *game, int i, int j)
{
	int k;

	k = -1;
	while (++k < game->map.col)
	{
		if (game->pc.place[i][j] == game->map.north_side[k])
			return (1);
		if (game->pc.place[i][j] == game->map.south_side[k])
			return (1);
	}
	k = -1;
	while (++k < game->map.li)
	{
		if (game->pc.place[i][j] == game->map.east_side[k])
			return (1);
		if (game->pc.place[i][j] == game->map.west_side[k])
			return (1);
	}
	return (0);
}

int		algo(t_game *game, int i, int j, int k)
{
	float top_dist;
	int top_dist_i;
	float dist;
	int surround;
	int top_surround;
	// int on_side;

	top_dist = 0;
	top_surround = 0;
	while (game->pc.place[++i])
	{
		j = -1;
		dist = 0;
		surround = 0;
		// on_side = 0;
		while (game->pc.place[i][++j] != -1)
		{
			// on_side = cut(game, i, j);
			surround += check_surround(game, i, j);
			k = -1;
			while (game->op.last[++k] != -1)
			{
				dist += absolute_distance(game, i, j, k);
			}
		}
		if ((dist == top_dist) && (surround > top_surround))
		{
			top_surround = surround;
			top_dist_i = i;
		}
		if (!i || (dist < top_dist))
		{
			top_dist = dist;
			top_dist_i = i;
		}
		// if (dist == top_dist)
		// {
		// 	if (surround == top_surround)
		// 		ft_putendl_fd("## egal surround\n", game->fd_bot);
		// 	if (surround > top_surround)
		// 	{
		// 		top_dist_i = i;
		// 		top_surround = surround;
		// 	}
		// }
	}
	return (top_dist_i);
}

void 	put_piece(t_game *g)
{
	int x;
	int y;
	int i;

	x = 0;
	y = 0;
	i = 0;
	if (g->lap)
		i = algo(g, -1, -1, -1);
	if (g->pc.place[0] == NULL)
		reset(g, 1);
	else
	{
		x = (g->pc.place[i][0] % g->map.col) - (g->pc.blok[0] % g->pc.col);
		y = (g->pc.place[i][0] / g->map.col) - (g->pc.blok[0] / g->pc.col);
	}
	// ft_putendl_fd("\n## size of struct\n", g->fd_bot);
	// ft_putnbr_fd(sizeof(g), g->fd_bot);
	// ft_putendl_fd("\n## size of size\n", g->fd_bot);
	// ft_putnbr_fd(g->map.size + g->pc.size + g->pc.n_blok + g->pl.n_blok + g->op.n_last, g->fd_bot);
	ft_putnbr(y);
	ft_putchar(' ');
	ft_putnbr(x);
	ft_putchar('\n');
}
