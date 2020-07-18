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

int absolute_distance(t_game *g, int i, int j, int k)
{
	int dx;
	int dy;

	dx = 0;
	dy = 0;
	dx = (g->pc.placement[i][j] % g->map.col) - (g->op.last[k] % g->map.col);
	dx *= (dx < 0) ? -1 : 1;
	dy = (g->pc.placement[i][j] / g->map.col) - (g->op.last[k] / g->map.col);
	dy *= (dy < 0) ? -1 : 1;
	return (dx + dy);
}

int		algo(t_game *game, int i, int j, int k)
{
	int top_dist;
	int top_dist_i;
	int dist;

	top_dist = 0;
	while (game->pc.placement[++i])
	{
		j = -1;
		dist = 0;
		while (game->pc.placement[i][++j] != -1)
		{
			k = -1;
			while (game->op.last[++k] != -1)
				dist += absolute_distance(game, i, j, k);
		}
		if (!i || (dist < top_dist))
		{
			top_dist = dist;
			top_dist_i = i;
		}
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
	if (g->pc.placement[0] == NULL)
		reset(g, 1);
	else
	{
		x = (g->pc.placement[i][0] % g->map.col) - (g->pc.blok[0] % g->pc.col);
		y = (g->pc.placement[i][0] / g->map.col) - (g->pc.blok[0] / g->pc.col);
	}
	ft_putnbr(y);
	ft_putchar(' ');
	ft_putnbr(x);
	ft_putchar('\n');
}
