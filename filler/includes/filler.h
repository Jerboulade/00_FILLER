/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecarere <jecarere@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 11:52:56 by jecarere          #+#    #+#             */
/*   Updated: 2020/03/11 16:32:56 by jecarere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "../libft/libft.h"
# include "stdio.h"

# define X 0
# define Y 1



typedef struct	s_map
{
	int			li;
	int			col;
	int			size;
	char		*new_map;
	char		*old_map;
}				t_map;

typedef struct	s_piece
{
	int			li;
	int			col;
	int			size;
	char		*piece;
	int			n_blok;
	int			*blok;
	int			**placement;

}				t_piece;

typedef struct	s_player
{
	char		player;
	int			n_blok;
	int 		*blok;
}				t_player;

typedef struct	s_opponent
{
	char		opponent;
	int			n_last;
	int			*last;
}				t_opponent;

typedef struct	s_game
{
	t_map		map;
	t_piece		pc;
	t_player	pl;
	t_opponent	op;
	int			fd_bot; // norme pour bot.txt?
	int			lap;
	char		*line;
}				t_game;

typedef struct	s_place
{
	int			out;
	int			n_place;
	int			map_start;
	int			pc_start;
	int			*pc;
}				t_place;
/*
**		printgame.c
*/
void	print_game(t_game *game, char *option);
/*
**		filler.c
*/
void	reset(t_game *game, int end);

/*
**		init_game.c
*/
void	init_map(t_game *game);
void	init_piece(t_game *game);
void	init_player(t_game *game);
void	init_opponent(t_game *game);
void	init_game(t_game *game);
/*
**		get_info.c
*/
int		get_piece(t_game *game);
int		create_map(t_game *game);
int		get_map(t_game *game, int i, int j);
int		get_players(t_game *game);
/*
**		parsing.c
*/
int		parse_piece(t_game *game);
int		compare_map(t_game *game);
int		parse_map(t_game *game, int i, int j);
/*
**		resolution.c
*/
void	adapt_index(t_game *game, t_place *p);
void	check_placement(t_game *game);
void	put_piece(t_game *game);
int		*dup_blok(int *blok, int n_blok);
int		algo(t_game *game);
/*
**		tool.c
*/
void	ft_intdel(int **as);
void	ft_frintab(int **tab, int size);
#endif
