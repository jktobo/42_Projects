/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaratae <dkaratae@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 16:55:43 by dkaratae          #+#    #+#             */
/*   Updated: 2022/10/01 21:14:52 by dkaratae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	press_key(int key, t_game *game)
{
	animat(game);
	if (key == 53)
		exit_game(game);
	else if (key == 13)
		move(0, -1, game, 13);
	else if (key == 0)
		move(-1, 0, game, 0);
	else if (key == 2)
		move(1, 0, game, 2);
	else if (key == 1)
		move(0, 1, game, 1);
	return (0);
}

int	move(int x, int y, t_game *game, int key)
{
	if (check_move(x, y, game) == 1)
		return (1);
	ft_mlx_show_image(game, FLOOR, game->px, game->py);
	if (game->step % 2 == 0)
		ft_mlx_show_image(game, PLAYER_F, game->px + x, game->py + y);
	else
	{
		if (key == 13 || key == 1)
			ft_mlx_show_image(game, PLAYER_B, game->px + x, game->py + y);
		else if (key == 0)
			ft_mlx_show_image(game, PLAYER_L, game->px + x, game->py + y);
		else if (key == 2)
			ft_mlx_show_image(game, PLAYER_R, game->px + x, game->py + y);
	}
	game->px += x;
	game->py += y;
	game->step++;
	ft_printf("%d\n", game->step);
	ft_mlx_show_image(game, WALL, 0, 0);
	mlx_string_put(game->mlx, game->mlx_win, 32, 30, -100, ft_itoa(game->step));
	return (0);
}

int	check_move(int x, int y, t_game *game)
{
	if (game->map[game->py + y][game->px + x] == '1')
		return (1);
	if (game->map[game->py + y][game->px + x] == 'B')
		exit_game(game);
	if (game->map[game->py + y][game->px + x] == 'E' && game->coin != 0)
		return (1);
	if (game->map[game->py + y][game->px + x] == 'E' && game->coin == 0)
	{
		game->px += x;
		game->py += y;
		game->step++;
		ft_printf("%d\n", game->step);
		exit_game(game);
	}
	if (game->map[game->py + y][game->px + x] == 'C')
	{
		ft_mlx_show_image(game, FLOOR, game->px + x, game->py + y);
		game->coin--;
		if (game->coin == 0)
			show_exit_open(game);
		game->map[game->py + y][game->px + x] = '0';
		return (0);
	}
	return (0);
}

void	show_exit_open(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'E')
				ft_mlx_show_image(game, EXIT_OP, j, i);
			j++;
		}
		i++;
	}
}

void	check_new_line(char *str)
{
	int	len;

	len = ft_strlen(str) - 1;
	if (str[len] == '\n')
	{
		perror("Your map is not correct, try to delete new line in the end!");
		free(str);
		exit(1);
	}
}
