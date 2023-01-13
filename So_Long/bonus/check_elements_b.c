/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_elements_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaratae <dkaratae@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 16:55:11 by dkaratae          #+#    #+#             */
/*   Updated: 2022/10/03 09:39:28 by dkaratae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_ber(char *av)
{
	int	len;

	len = ft_strlen(av) - 4;
	while (av[len])
	{
		if (av[len] == '.' && av[len + 1] == 'b' && \
			av[len + 2] == 'e' && av[len + 3] == 'r')
			return (1);
		len++;
	}
	return (0);
}

int	check_wall(t_game *game, int x, int y)
{
	if (game->map[x][y] == 'E')
	{
		if (game->hmap[x][y] != '1')
		{
			game->hmap[x][y] = '1';
			game->hexit += 1;
		}
		return (1);
	}
	if (game->map[x][y] == 'B')
	{
		if (game->hmap[x][y] != '1')
			game->hmap[x][y] = '1';
		return (1);
	}
	if (game->map[x][y] == '1')
		return (1);
	if (game->hmap[x][y] == '1')
		return (1);
	return (0);
}

void	check_hmap(t_game *game, int x, int y)
{
	game->hmap[x][y] = '1';
	if (game->map[x][y] == 'C')
		game->hcoin += 1;
	if (check_wall(game, x, y - 1) == 0)
		check_hmap(game, x, y - 1);
	if (check_wall(game, x + 1, y) == 0)
		check_hmap(game, x + 1, y);
	if (check_wall(game, x, y + 1) == 0)
		check_hmap(game, x, y + 1);
	if (check_wall(game, x - 1, y) == 0)
		check_hmap(game, x - 1, y);
}

void	count_elements(t_game *game)
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
				game->exit++;
			else if (game->map[i][j] == 'C')
				game->coin++;
			else if (game->map[i][j] == 'P')
			{
				game->player++;
				game->px = i;
				game->py = j;
			}
			j++;
		}
		i++;
	}
}

void	check_elem(t_game *game)
{
	if (game->player != 1)
	{
		perror("Error\nYou need to have 1 player!");
		map_free(game);
		exit(1);
	}
	else if (game->coin < 1)
	{
		perror("Error\nYou need to have one or more coins, it's mistake!");
		map_free(game);
		exit(1);
	}
	else if (game->exit != 1)
	{
		perror("Error\nYou need to have only one exits, it's mistake!");
		map_free(game);
		exit(1);
	}
}
