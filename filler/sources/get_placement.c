/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_placement.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecarere <jecarere@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 12:15:12 by jecarere          #+#    #+#             */
/*   Updated: 2019/10/31 16:44:42 by jecarere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int		*dup_blok(int *blok, int n_blok)
{
	int *dup;
	int i;

	i = -1;
	if (!blok || !n_blok)
		return (NULL);
	if (!(dup = (int *)malloc(sizeof(int) * (n_blok + 1))))
		return (NULL);
	dup[n_blok] = -1;
	while (++i < n_blok)
		dup[i] = blok[i];
	return (dup);
}

int		check_if_out(t_game *g, t_place *p, int i)
{
	int x1;
	int x2;
	int y1;
	int y2;

	x1 = p->pc_start % g->pc.col;
	x2 = g->pc.blok[i] % g->pc.col;
	y1 = p->pc_start / g->pc.col;
	y2 = g->pc.blok[i] / g->pc.col;
	if ((p->pc[i] < 0) || \
	(p->pc[i] >= g->map.size) || \
	(g->map.new_map[p->pc[i]] != '.') || \
	(((p->map_start % g->map.col) + (x2 - x1)) < 0) || \
	(((p->map_start % g->map.col) + (x2 - x1)) >= g->map.col) || \
	(((p->map_start / g->map.col) + (y2 - y1)) < 0) || \
	(((p->map_start / g->map.col) + (y2 - y1)) >= g->map.col))
		return (0);
	return (p->out);
}

int		index_translation(t_game *g, t_place *p, int i)
{
	int x1;
	int x2;
	int y1;
	int y2;

	x1 = p->pc_start % g->pc.col;
	x2 = p->pc[i] % g->pc.col;
	y1 = p->pc_start / g->pc.col;
	y2 = p->pc[i] / g->pc.col;
	return (p->map_start + ((y2 - y1) * g->map.col) + (x2 - x1));
}

void	adapt_index(t_game *g, t_place *p)
{
	int i;

	i = -1;
	while ((p->pc[++i] != -1) && p->out)
	{

		if (p->pc[i] == p->pc_start)
			p->pc[i] = p->map_start;
		else
		{
			p->pc[i] = index_translation(g, p, i);
			p->out = check_if_out(g, p, i);
		}
	}
	if (p->out)
	{
		g->pc.place[p->place_i] = p->pc;
		p->place_i++;
	}
	else
		ft_intdel(&p->pc);
}

int	get_placement(t_game *g, int *start, int n_start)
{
	int 	i;
	int 	j;
	t_place p;

	i = -1;
	p.place_i = 0;
	g->pc.n_place = n_start * g->pc.n_blok;
	if (!(g->pc.place = (int **)malloc(sizeof(int*) * (g->pc.n_place + 1))))
		return (0);
	while (++i <= g->pc.n_place)
		g->pc.place[i] = NULL;
	i = -1;
	while (++i < n_start)
	{
		j = -1;
		while (++j < g->pc.n_blok)
		{
			if (!(p.pc = dup_blok(g->pc.blok, g->pc.n_blok)))
				return (0);
			p.map_start = start[i];
			p.pc_start = p.pc[j];
			p.out = 1;
			adapt_index(g, &p);
		}
	}
	return (1);
}
