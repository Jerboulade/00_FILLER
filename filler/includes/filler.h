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
	char		*map;

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
	int			first_blok;
	int			*last_blok;
	int			n_last_blok;

}				t_player;

typedef struct	s_opponent
{
	char		opponent;
	int			n_blok;
	int			*last_blok;
	int			n_last_blok;


}				t_opponent;

typedef struct	s_game
{
	t_map		map;
	t_piece		pc;
	t_player	pl;
	t_opponent	op;
	int			fd_bot; // norme pour bot.txt?
	int			lap;
}				t_game;
/*
**		printgame.c
*/
void	print_game(t_game *game, char *option);
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
int		create_map(t_game *game, char *line);
int		get_map(t_game *game);
int		get_players(t_game *game);
/*
**		parsing.c
*/
int		parse_piece(t_game *game);
int		get_map_nb_blok(t_game *game);
int		get_map_blok_position(t_game *game);
int		parse_map(t_game *game);
/*
**		resolution.c
*/
void	check_placement(t_game *game);
void	put_piece(t_game *game);
void	check_block(t_game *game, char blok);
int		*dup_blok(int *blok, int n_blok);


#endif
