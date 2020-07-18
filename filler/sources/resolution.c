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

int *dup_blok(int *blok, int n_blok)
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
	return(dup);
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
			p->pc[i] = p->map_start + (((p->pc[i] / g->pc.col) - (p->pc_start / g->pc.col)) * g->map.col) + ((p->pc[i] % g->pc.col) - (p->pc_start % g->pc.col));
			if ((p->pc[i] < 0) || (p->pc[i] >= g->map.size))
				p->out = 0;
			else if (g->map.new_map[p->pc[i]] != '.')
				p->out = 0;
			else if ((((p->map_start % g->map.col) + ((g->pc.blok[i] % g->pc.col) - (p->pc_start % g->pc.col))) < 0) || (((p->map_start % g->map.col) + ((g->pc.blok[i] % g->pc.col) - (p->pc_start % g->pc.col))) >= g->map.col))
				p->out = 0;
			else if ((((p->map_start / g->map.col) + ((g->pc.blok[i] / g->pc.col) - (p->pc_start / g->pc.col))) < 0) || (((p->map_start / g->map.col) + ((g->pc.blok[i] / g->pc.col) - (p->pc_start / g->pc.col))) >= g->map.col))
				p->out = 0;
		}
	}
}
void	check_placement(t_game *game)
{
	int i;
	int j;
	int l;
	t_place p;


	i = -1;
	l = 0;
	p.n_place = game->pl.n_blok * game->pc.n_blok;
	if (!(game->pc.placement = (int **)malloc(sizeof(int*) * (p.n_place + 1))))
		return ;
	while (++i <= p.n_place)
		game->pc.placement[i] = NULL;
	i = -1;
	while (++i < game->pl.n_blok)
	{
		j = -1;
		while (++j < game->pc.n_blok)
		{
			p.pc = dup_blok(game->pc.blok, game->pc.n_blok);
			p.map_start = game->pl.blok[i];
			p.pc_start = p.pc[j];
			p.out = 1;
			adapt_index(game, &p);
			if (p.out)
			{
				game->pc.placement[l] = p.pc;
				l++;
			}
			else
				ft_intdel(&p.pc);
		}
	}
}

int		algo(t_game *game)
{

	int top_dist;
	int top_dist_i;
	int dist;
	int tmp;
	int i;
	int j;
	int k;

	top_dist = 0;
	i = -1;
	while (game->pc.placement[++i])
	{
		j = -1;
		dist = 0;
		while (game->pc.placement[i][++j] != -1)
		{
			k = -1;
			while (game->op.last[++k] != -1)
			{
				tmp = (game->pc.placement[i][j] % game->map.col) - (game->op.last[k] % game->map.col);
				tmp *= (tmp < 0) ? -1 : 1;
				dist += tmp;
				tmp = (game->pc.placement[i][j] / game->map.col) - (game->op.last[k] / game->map.col);
				tmp *= (tmp < 0) ? -1 : 1;
				dist += tmp;
			}
		}
		if (!i)
		{
			top_dist = dist;
			top_dist_i = i;
		}
		else if (i && (dist < top_dist))
		{
			top_dist = dist;
			top_dist_i = i;
		}
	}
	return (top_dist_i);
}

void 	put_piece(t_game *game)
{
	int x;
	int y;
	int topi;
	// int placement;
	// ft_putendl_fd("\n########### CACA 7 bis ###########\n", game->fd_bot);

	x = 0;
	y = 0;
	check_placement(game);
	topi = 0;
	if (game->lap)
		topi = algo(game);
	if (game->pc.placement[0] == NULL)
		reset(game, 1);
	else
	{
		x = (game->pc.placement[topi][0] % game->map.col) - (game->pc.blok[0] % game->pc.col);
		y = (game->pc.placement[topi][0] / game->map.col) - (game->pc.blok[0] / game->pc.col);
	}
	// game->pl.n_last = game->pc.n_blok;
	// game->pl.last = dup_blok(game->pc.placement[0], game->pc.n_blok);
	// x = (game->pl.last[0] % game->map.col) - (game->pc.blok[0] % game->pc.col);
	// y = (game->pl.last[0] / game->map.col) - (game->pc.blok[0] / game->pc.col);

	ft_putnbr(y);
	ft_putchar(' ');
	ft_putnbr(x);
	ft_putchar('\n');

	// ## PRINT ##############################################################
	// ft_putendl_fd("\n## Placement coordinates ###########\n", game->fd_bot);
	// ft_putstr_fd("x: ", game->fd_bot);
	// ft_putnbr_fd(x, game->fd_bot);
	// ft_putchar_fd('\n', game->fd_bot);
	// ft_putstr_fd("y: ", game->fd_bot);
	// ft_putnbr_fd(y, game->fd_bot);
	// ft_putchar_fd('\n', game->fd_bot);
	// ft_putchar_fd('\n', game->fd_bot);
	// ## END PRINT ##########################################################

}
