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
	if (!(dup = (int *)malloc(sizeof(int) * (n_blok + 1))))
		return (NULL);
	dup[n_blok] = -1;
	while (++i < n_blok)
		dup[i] = blok[i];
	return(dup);
}

void check_placement(t_game *game)
{
	int i;
	int j;
	int k;
	int l;
	int out;
	int nb_placement;
	int map_blok_start;
	int pc_blok_start;
	int *pc_bloks;

	i = -1;
	l = 0;

	// ft_putchar_fd('\n', game->fd_bot);
	// ft_putnbr_fd(game->pl.n_last_blok, game->fd_bot);
	// ft_putchar_fd('\n', game->fd_bot);
	// ft_putnbr_fd(game->pc.n_blok, game->fd_bot);
	// ft_putchar_fd('\n', game->fd_bot);



	nb_placement = game->pl.n_blok * game->pc.n_blok;
	if (!(game->pc.placement = (int **)malloc(sizeof(int*) * (nb_placement + 1))))
		return ;
	while (++i <= nb_placement)
		game->pc.placement[i] = NULL;
	i = -1;
	//double while i-j, je teste, un à un tous les blocks de la pièce sur tous les blocks précédement posés
	while (++i < game->pl.n_blok)
	{
		j = -1;
		while (++j < game->pc.n_blok)
		{
			//récupération de données

			pc_bloks = dup_blok(game->pc.blok, game->pc.n_blok);
			// ft_putendl_fd("\n########### CACA 8 ###########\n", game->fd_bot);
			map_blok_start = game->pl.blok[i];
			// ft_putendl_fd("\n########### CACA 9 ###########\n", game->fd_bot);
			pc_blok_start = pc_bloks[j];

			//transformation des coordonnées de la pièces pour qu'elles correspondent aux coordonnées de la map, à partir de la coordonnée du block testé
			k = -1;
			out = 1;
			while ((pc_bloks[++k] != -1) && out)
			{

				if (pc_bloks[k] == pc_blok_start)
				{
					pc_bloks[k] = map_blok_start;
				}
				else
				{
					pc_bloks[k] = map_blok_start + (((pc_bloks[k] / game->pc.col) - (pc_blok_start / game->pc.col)) * game->map.col) + ((pc_bloks[k] % game->pc.col) - (pc_blok_start % game->pc.col));
					// check si pqs hors map
					// ft_putendl_fd("\n########### CACA prout ###########\n", game->fd_bot);
					// ft_putnbr_fd(pc_bloks[k], game->fd_bot);
					// ft_putstr_fd(" = ", game->fd_bot);
					// ft_putnbr_fd(map_blok_start, game->fd_bot);
					// ft_putstr_fd(" + ((", game->fd_bot);
					// ft_putnbr_fd((pc_bloks[k] / game->pc.col), game->fd_bot);
					// ft_putstr_fd(" - ", game->fd_bot);
					// ft_putnbr_fd((pc_blok_start / game->pc.col), game->fd_bot);
					// ft_putstr_fd(") * ", game->fd_bot);
					// ft_putnbr_fd(game->map.col, game->fd_bot);
					// ft_putstr_fd(") + (", game->fd_bot);
					// ft_putnbr_fd((pc_bloks[k] % game->pc.col), game->fd_bot);
					// ft_putstr_fd(" - ", game->fd_bot);
					// ft_putnbr_fd((pc_blok_start % game->pc.col), game->fd_bot);
					// ft_putstr_fd(") ", game->fd_bot);

					if ((pc_bloks[k] < 0) || (pc_bloks[k] >= game->map.size))
						out = 0;
					else
					{
						// ft_putendl_fd("#\n", game->fd_bot);
						// ft_putnbr_fd(pc_bloks[k], game->fd_bot);
						if (game->map.new_map[pc_bloks[k]] != '.')
						{
							// ft_putnbr_fd(pc_bloks[k], game->fd_bot);
							// ft_putchar_fd(game->map.new_map[pc_bloks[k]], game->fd_bot);
							// ft_putendl_fd("\n##### OCCUPIED ####\n", game->fd_bot);
							out = 0;
						}

						if ((((map_blok_start % game->map.col) + ((game->pc.blok[k] % game->pc.col) - (pc_blok_start % game->pc.col))) < 0) || (((map_blok_start % game->map.col) + ((game->pc.blok[k] % game->pc.col) - (pc_blok_start % game->pc.col))) >= game->map.col))
						{
							// ft_putendl_fd("\n##### OUT COL #####\n", game->fd_bot);
							out = 0;
						}
						if ((((map_blok_start / game->map.col) + ((game->pc.blok[k] / game->pc.col) - (pc_blok_start / game->pc.col))) < 0) || (((map_blok_start / game->map.col) + ((game->pc.blok[k] / game->pc.col) - (pc_blok_start / game->pc.col))) >= game->map.col))
						{
							// ft_putendl_fd("\n##### OUT LI ######\n", game->fd_bot);
							out = 0;
						}
					}
					// ft_putchar_fd('\n', game->fd_bot);
					// ft_putnbr_fd(pc_bloks[k], game->fd_bot);
					// ft_putchar_fd('\n', game->fd_bot);
					// ft_putstr_fd("\nline check : ", game->fd_bot);
					// ft_putnbr_fd((((map_blok_start / game->map.col) + ((game->pc.blok[k] / game->pc.col) - (pc_blok_start / game->pc.col)))), game->fd_bot);
					// ft_putstr_fd(" = ", game->fd_bot);
					// ft_putnbr_fd((map_blok_start / game->map.col), game->fd_bot);
					// ft_putstr_fd(" + ( ", game->fd_bot);
					// ft_putnbr_fd((game->pc.blok[k] / game->pc.col), game->fd_bot);
					// ft_putstr_fd(" - ", game->fd_bot);
					// ft_putnbr_fd((pc_blok_start / game->pc.col), game->fd_bot);
					// ft_putstr_fd(" )", game->fd_bot);
					// ft_putstr_fd("\ncol check  : ", game->fd_bot);
					// ft_putnbr_fd((((map_blok_start % game->map.col) + ((game->pc.blok[k] % game->pc.col) - (pc_blok_start % game->pc.col)))), game->fd_bot);
					// ft_putstr_fd(" = ", game->fd_bot);
					// ft_putnbr_fd((map_blok_start % game->map.col), game->fd_bot);
					// ft_putstr_fd(" + ( ", game->fd_bot);
					// ft_putnbr_fd((game->pc.blok[k] % game->pc.col), game->fd_bot);
					// ft_putstr_fd(" - ", game->fd_bot);
					// ft_putnbr_fd((pc_blok_start % game->pc.col), game->fd_bot);
					// ft_putstr_fd(" )", game->fd_bot);
					// ft_putendl_fd("\n\n########### CACA 10 ###########\n", game->fd_bot);
				}
			}
			if (out)
			{
				// if (!(game->pc.placement[l] = (int *)malloc(sizeof(int) * (game->pc.n_blok + 1))))
				// 	return ;
				game->pc.placement[l] = pc_bloks; // malloc le pc_blocks
				l++;
			}
		}
	}

	// ## PRINT ##############################################################
	// ft_putendl_fd("\n## Possible placement ##############\n", game->fd_bot);
	// i = -1;
	// while (game->pc.placement[++i])
	// {
	// 	ft_putchar_fd('(', game->fd_bot);
	// 	j = -1;
	// 	while (game->pc.placement[i][++j] != -1)
	// 	{
	// 		ft_putnbr_fd(game->pc.placement[i][j], game->fd_bot);
	// 		if (game->pc.placement[i][j + 1] != -1)
	// 			write(game->fd_bot, ", ", 2);
	// 	}
	// 	ft_putchar_fd(')', game->fd_bot);
	// 	ft_putchar_fd('\n', game->fd_bot);
	// }
	// ## END PRINT ##########################################################

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
			while (game->op.last_blok[++k] != -1)
			{
				tmp = (game->pc.placement[i][j] % game->map.col) - (game->op.last_blok[k] % game->map.col);
				tmp *= (tmp < 0) ? -1 : 1;
				dist += tmp;
				tmp = (game->pc.placement[i][j] / game->map.col) - (game->op.last_blok[k] / game->map.col);
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

	check_placement(game);
	topi = 0;
	if (game->lap)
		topi = algo(game);
	if (game->pc.placement[0] == NULL)
	{
		ft_putnbr(0);
		ft_putchar(' ');
		ft_putnbr(0);
		ft_putchar('\n');
		exit(0);
	}
	else
	{
		x = (game->pc.placement[topi][0] % game->map.col) - (game->pc.blok[0] % game->pc.col);
		y = (game->pc.placement[topi][0] / game->map.col) - (game->pc.blok[0] / game->pc.col);
	}
	// game->pl.n_last_blok = game->pc.n_blok;
	// game->pl.last_blok = dup_blok(game->pc.placement[0], game->pc.n_blok);
	// x = (game->pl.last_blok[0] % game->map.col) - (game->pc.blok[0] % game->pc.col);
	// y = (game->pl.last_blok[0] / game->map.col) - (game->pc.blok[0] / game->pc.col);

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
