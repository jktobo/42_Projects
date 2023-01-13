/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaratae <dkaratae@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 16:03:13 by dkaratae          #+#    #+#             */
/*   Updated: 2022/10/23 20:30:06 by dkaratae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	map_free(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i])
		free(game->map[i++]);
	free(game->map);
}

void	check_valid_map(t_game *game)
{
	check_hmap(game, game->px, game->py);
	if (game->coin != game->hcoin || game->hexit != 1)
	{
		ft_printf("YOUR MAP ISN'T VALID!!!\n");
		map_free(game);
		exit(1);
	}
}

void	game_run(t_game *game, char *av)
{
	game->player = 0;
	game->exit = 0;
	game->coin = 0;
	game->hexit = 0;
	game->hcoin = 0;
	if (check_ber(av))
	{
		get_map(game, av);
		check_rectangle(game);
		check_wall_top_bottom(game);
		check_wall_left_right(game);
		count_elements(game);
		check_elem(game);
		check_valid_map(game);
	}
	else
	{
		perror("Error\nYour extension isn't equal '.ber'!");
		exit(1);
	}
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		return (0);
	game_run(&game, av[1]);
	game.mlx = mlx_init();
	game.mlx_win = mlx_new_window(game.mlx, game.weight * 64, \
									game.height * 64, "so_long");
	ft_create_map(&game);
	mlx_hook(game.mlx_win, 2, 1L << 0, press_key, &game);
	mlx_hook(game.mlx_win, 17, (1L << 17), exit_game, &game);
	mlx_loop(game.mlx);
	map_free(&game);
}
