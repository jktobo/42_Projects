/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaratae <dkaratae@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 12:15:51 by dkaratae          #+#    #+#             */
/*   Updated: 2022/10/01 16:41:48 by dkaratae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	get_map(t_game *game, char *file)
{
	int		fd;
	char	*str;
	char	*temp;
	int		count_lines;

	str = NULL;
	count_lines = 0;
	fd = open (file, O_RDONLY);
	temp = get_next_line(fd);
	if (!temp)
		exit(1);
	while (temp != NULL)
	{
		str = ft_strjoin(str, temp);
		free(temp);
		temp = get_next_line(fd);
		count_lines++;
	}
	check_new_line(str);
	game->map = ft_split(str, '\n');
	game->height = count_lines;
	game->weight = ft_strlen(game->map[0]);
	game->len_str = count_letters_map(str);
	free(str);
	close (fd);
}

void	check_rectangle(t_game *game)
{
	if ((game->height * game->weight) != game->len_str)
	{
		perror("Your map is not rectangle or you have new line!");
		map_free(game);
		exit(1);
	}
}

void	check_wall_top_bottom(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->map[0][i] != '\0')
	{
		if (game->map[0][i++] != '1')
		{
			perror("Your wall is not correct!");
			map_free(game);
			exit(1);
		}
	}
	i = 0;
	j = game->height - 1;
	while (game->map[j][i] != '\0')
	{
		if (game->map[j][i++] != '1')
		{
			perror("Your wall is not correct!");
			map_free(game);
			exit(1);
		}
	}
}

void	check_wall_left_right(t_game *game)
{
	int	i;
	int	height;
	int	weight;

	i = 0;
	height = game->height - 1;
	weight = game->weight - 1;
	while (i <= height)
	{
		if (game->map[i][0] != '1')
		{
			perror("Your left wall is not correct!");
			map_free(game);
			exit(1);
		}
		if (game->map[i][weight] != '1')
		{
			perror("Your right wall is not correct!");
			map_free(game);
			exit(1);
		}
		i++;
	}
}
