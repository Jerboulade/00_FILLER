# include "../includes/filler.h"

void	print_game(t_game *game, char *option)
{
	ft_putstr_fd("## LAP ", game->fd_bot);
	ft_putnbr_fd(game->lap, game->fd_bot);
	ft_putendl_fd(" ############################", game->fd_bot);

	if (!option || !ft_strcmp(option, "player"))
	{
		ft_putendl_fd("## PLAYER ##########################\n", game->fd_bot);
		ft_putstr_fd("   player: ", game->fd_bot);
		ft_putchar_fd(game->pl.player, game->fd_bot);
		ft_putchar_fd('\n', game->fd_bot);
		ft_putstr_fd("   nb player blocks on the map: ", game->fd_bot);
		ft_putnbr_fd(game->pl.n_blok, game->fd_bot);
		ft_putchar_fd('\n', game->fd_bot);

	}
	if (!option || !ft_strcmp(option, "opponent"))
	{
		ft_putendl_fd("\n## OPPONENT ########################\n", game->fd_bot);
		ft_putstr_fd("   opponent: ", game->fd_bot);
		ft_putchar_fd(game->op.opponent, game->fd_bot);
		ft_putchar_fd('\n', game->fd_bot);
		ft_putstr_fd("   nb previous blocks: ", game->fd_bot);
		ft_putnbr_fd(game->op.n_last, game->fd_bot);
		ft_putchar_fd('\n', game->fd_bot);
		ft_putstr_fd("   last blocks: ", game->fd_bot);
		int i = -1;
		while (++i < game->op.n_last)
		{
			ft_putnbr_fd(game->op.last[i], game->fd_bot);
			if (i != (game->op.n_last - 1))
				write(game->fd_bot, ", ", 2);
		}
		ft_putchar_fd('\n', game->fd_bot);
	}

	if (!option || !ft_strcmp(option, "piece"))
	{
		ft_putendl_fd("\n## PIECE ###########################\n", game->fd_bot);
		ft_putstr_fd("   line: ", game->fd_bot);
		ft_putnbr_fd(game->pc.li, game->fd_bot);
		ft_putchar_fd('\n', game->fd_bot);
		ft_putstr_fd("   colone: ", game->fd_bot);
		ft_putnbr_fd(game->pc.col, game->fd_bot);
		ft_putchar_fd('\n', game->fd_bot);
		ft_putstr_fd("   size: ", game->fd_bot);
		ft_putnbr_fd(game->pc.size, game->fd_bot);
		ft_putchar_fd('\n', game->fd_bot);

		ft_putstr_fd("   piece: \n", game->fd_bot);
		int		i = -1;
		int		j = 0;
		while (++i < game->pc.li)
		{
			write(game->fd_bot, "   ", 3);
			write(game->fd_bot, game->pc.piece + j, game->pc.col);
			j += game->pc.col;
			ft_putchar_fd('\n', game->fd_bot);
		}
		ft_putchar_fd('\n', game->fd_bot);

		ft_putstr_fd("   n_block: ", game->fd_bot);
		ft_putnbr_fd(game->pc.n_blok, game->fd_bot);
		ft_putchar_fd('\n', game->fd_bot);

		ft_putstr_fd("   bloks_index: ", game->fd_bot);
		i = -1;
		while (++i < game->pc.n_blok)
		{
			ft_putnbr_fd(game->pc.blok[i], game->fd_bot);
			if (i != (game->pc.n_blok - 1))
				write(game->fd_bot, ", ", 2);
		}
		ft_putchar_fd('\n', game->fd_bot);



		// ft_putstr_fd("   placement: \n", game->fd_bot);
		// i = -1;
		// while (game->pc.placement[++i])
		// {
		// 	ft_putchar_fd('(', game->fd_bot);
		// 	j = -1;
		// 	while (game->pc.placement[i][++j] != -1)
		// 	{
		// 		ft_putnbr_fd(game->pc.placement[i][j], game->fd_bot);
		// 		write(game->fd_bot, ", ", 2);
		// 	}
		// 	ft_putchar_fd(')', game->fd_bot);
		// 	ft_putchar_fd('\n', game->fd_bot);
		// }

	}

	if (!option || !ft_strcmp(option, "map"))
	{
		ft_putendl_fd("\n## MAP #############################\n", game->fd_bot);
		ft_putstr_fd("   line: ", game->fd_bot);
		ft_putnbr_fd(game->map.li, game->fd_bot);
		ft_putchar_fd('\n', game->fd_bot);
		ft_putstr_fd("   colone: ", game->fd_bot);
		ft_putnbr_fd(game->map.col, game->fd_bot);
		ft_putchar_fd('\n', game->fd_bot);
		ft_putstr_fd("   size: ", game->fd_bot);
		ft_putnbr_fd(game->map.size, game->fd_bot);
		ft_putchar_fd('\n', game->fd_bot);
		ft_putstr_fd("   old_map: \n", game->fd_bot);
		int		i = -1;
		int		j = 0;
		while (++i < game->map.li)
		{
			write(game->fd_bot, "   ", 3);
			write(game->fd_bot, game->map.old_map + j, game->map.col);
			j += game->map.col;
			ft_putchar_fd('\n', game->fd_bot);
		}
		ft_putchar_fd('\n', game->fd_bot);
		ft_putstr_fd("   new_map: \n", game->fd_bot);
		i = -1;
		j = 0;
		while (++i < game->map.li)
		{
			write(game->fd_bot, "   ", 3);
			write(game->fd_bot, game->map.new_map + j, game->map.col);
			j += game->map.col;
			ft_putchar_fd('\n', game->fd_bot);
		}
		ft_putchar_fd('\n', game->fd_bot);
	}
}
