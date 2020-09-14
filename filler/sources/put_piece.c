/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_piece.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecarere <jecarere@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 12:15:12 by jecarere          #+#    #+#             */
/*   Updated: 2019/10/31 16:44:42 by jecarere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int		absolute_distance(t_game *g, int i, int j, int k)
{
	float dx;
	float dy;

	dx = 0;
	dy = 0;
	dx = (g->pc.place[i][j] % g->map.col) - (g->op.last[k] % g->map.col);
	dx *= (dx < 0) ? -1 : 1;
	dy = (g->pc.place[i][j] / g->map.col) - (g->op.last[k] / g->map.col);
	dy *= (dy < 0) ? -1 : 1;
	return (sqrt((dx * dx) + (dy * dy)));
}

int		check_surround(t_game *g, int p, int c, int nb)
{
	char o;

	o = g->op.opponent;
	if ((((p + 1) % c) < c) && (g->map.new_map[p + 1] == o))
		nb++;
	if ((((p - 1) % c) >= 0) && (g->map.new_map[p - 1] == o))
		nb++;
	if ((((p + c) / c) < g->map.li) && (g->map.new_map[p + c] == o))
		nb++;
	if ((((p + c + 1) / c) < g->map.li) && (g->map.new_map[p + c + 1] == o) &&\
		(((p + c + 1) / c) < c))
		nb++;
	if ((((p + c - 1) / c) < g->map.li) && (g->map.new_map[p + c - 1] == o) &&\
		(((p + c - 1) / c) >= 0))
		nb++;
	if ((((p - c) / c) >= 0) && ((p - c) >= 0) && (g->map.new_map[p - c] == o))
		nb++;
	if ((((p - c + 1) / c) >= 0) && ((p - c + 1) >= 0) &&\
		(((p - c + 1) / c) < c) && (g->map.new_map[p - c + 1] == o))
		nb++;
	if (((p - c - 1) / c) >= 0 && (((p - c - 1) / c) >= 0) &&\
		((p - c - 1) >= 0) && (g->map.new_map[p - c - 1] == o))
		nb++;
	return (nb);
}

int		algo(t_game *g, int i, int j, int k)
{
	while (g->pc.place[++i])
	{
		j = -1;
		g->dist = 0;
		g->surround = 0;
		while (g->pc.place[i][++j] != -1)
		{
			g->surround += check_surround(g, g->pc.place[i][j], g->map.col, 0);
			k = -1;
			while (g->op.last[++k] != -1)
				g->dist += absolute_distance(g, i, j, k);
		}
		if (!i || (g->dist < g->top_dist))
		{
			g->top_dist = g->dist;
			g->top_i = i;
		}
		if ((g->dist == g->top_dist) && (g->surround > g->top_surround))
		{
			g->top_surround = g->surround;
			g->top_i = i;
		}
	}
	return (g->top_i);
}

void	put_piece(t_game *g)
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
	ft_putnbr(y);
	ft_putchar(' ');
	ft_putnbr(x);
	ft_putchar('\n');
}
