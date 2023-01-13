/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaratae <dkaratae@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 23:57:15 by dkaratae          #+#    #+#             */
/*   Updated: 2022/10/02 14:49:15 by dkaratae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/file.h>
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include "./mlx/mlx.h"

# define FLOOR "./images/floor.xpm"
# define PLAYER_F "./images/player_front.xpm"
# define PLAYER_B "./images/player_back.xpm"
# define PLAYER_R "./images/player_right.xpm"
# define PLAYER_L "./images/player_left.xpm"
# define WALL "./images/wall.xpm"
# define COIN "./images/coin.xpm"
# define EXIT "./images/exit.xpm"
# define EXIT_OP "./images/exit_open.xpm"
# define BOMB_1 "./images/bomb_1.xpm"
# define BOMB_2 "./images/bomb_2.xpm"

typedef struct s_game
{
	char	**map;
	int		height;
	int		weight;
	int		len_str;
	int		hexit;
	int		hcoin;
	int		px;
	int		py;
	int		player;
	int		coin;
	int		exit;
	int		step;
	int		hmap[256][256];
	void	*mlx;
	void	*mlx_win;
	void	*img;
}	t_game;

int		main(int ac, char **av);
void	game_run(t_game *game, char *av);
void	check_valid_map(t_game *game);
void	map_free(t_game *game);
void	animat(t_game *game);

void	get_map(t_game *g, char *file);
void	check_rectangle(t_game *game);
void	check_wall_top_bottom(t_game *game);
void	check_wall_left_right(t_game *game);
void	check_l_r_side(t_game *game, int side);

int		check_ber(char	*av);
int		check_wall(t_game *game, int x, int y);
void	check_hmap(t_game *game, int x, int y);
void	count_elements(t_game *game);
void	check_elem(t_game *game);

void	ft_create_map(t_game *game);
void	ft_print_xpm(t_game *game, int x, int y);
void	ft_mlx_show_image(t_game *game, char *path, int x, int y);
int		count_letters_map(char *str);
int		exit_game(t_game *game);

int		press_key(int key, t_game *game);
int		move(int x, int y, t_game *game, int key);
int		check_move(int x, int y, t_game *game);
void	show_exit_open(t_game *game);
void	check_new_line(char *str);

#endif
