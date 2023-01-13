/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaratae <dkaratae@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 13:45:42 by dkaratae          #+#    #+#             */
/*   Updated: 2022/10/03 09:35:14 by dkaratae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_create_map(t_game *game)
{
	int	i;
	int	j;

	j = 0;
	while (game->map[j])
	{
		i = 0;
		while (game->map[j][i])
		{
			if (game->map[j][i] == 'P')
			{
				game->px = i;
				game->py = j;
			}
			ft_print_xpm(game, i, j);
			i++;
		}
		j++;
	}
}

void	ft_print_xpm(t_game *game, int x, int y)
{
	if (game->map[y][x] == 'P')
		ft_mlx_show_image(game, PLAYER_F, x, y);
	else if (game->map[y][x] == '0')
		ft_mlx_show_image(game, FLOOR, x, y);
	else if (game->map[y][x] == '1')
		ft_mlx_show_image(game, WALL, x, y);
	else if (game->map[y][x] == 'C')
		ft_mlx_show_image(game, COIN, x, y);
	else if (game->map[y][x] == 'E')
		ft_mlx_show_image(game, EXIT, x, y);
}

void	ft_mlx_show_image(t_game *game, char *path, int x, int y)
{
	int	size;
	int	i;
	int	j;

	size = 64;
	i = y * size;
	j = x * size;
	game->img = mlx_xpm_file_to_image(game->mlx, path, &size, &size);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->img, j, i);
	mlx_destroy_image(game->mlx, game->img);
}

int	count_letters_map(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] != '0' && str[i] != '1' && str[i] != 'C' && \
			str[i] != 'E' && str[i] != 'P' && str[i] != '\n')
		{
			ft_printf("ERROR, YOUR MAP ISN'T VALID!!!");
			exit(1);
		}
		if (str[i] != '\n')
			count++;
		i++;
	}
	return (count);
}

int	exit_game(t_game *game)
{
	mlx_clear_window(game->mlx, game->mlx_win);
	mlx_destroy_window(game->mlx, game->mlx_win);
	map_free(game);
	exit (0);
}
