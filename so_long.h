/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: havyilma <havyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 18:57:21 by havyilma          #+#    #+#             */
/*   Updated: 2023/03/25 07:53:42 by havyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# define SO_LONG_H

# include <fcntl.h>
# include "./minilibx/mlx.h"
# include "./get_next_line/get_next_line.h"
# include "stdlib.h"

typedef struct s_settings
{
	void	*mlx;
	void	*window;
	void	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	char	**map;
	void	*img;
	int		map_width;
	int		map_height;
	char	*path_p;
	char	*path_e;
	char	*path_c;
	char	*path_1;
	char	*path_0;
	void	*img_0;
	void	*img_1;
	void	*img_p;
	void	*img_e;
	void	*img_c;
	int		pr_pos_x;
	int		pr_pos_y;
	int		count_coll;
	int		check_coll;
	int		count_e;
	char	**img_ch;
	int		player_pos_x;
	int		player_pos_y;
	int		move;
	char	*c_move;

}	t_settings;

void	ft_init(t_settings *set);
int		ft_control_epc(t_settings *set, int i, int j, int check_e);
int		ft_check_edge(t_settings *set, int i, int j);
int		ft_check_zero_one(t_settings *set, int i, int j);
void	ft_read_map(char *av, t_settings *set);
void	what_the_height(char *av, t_settings *map);
void	what_the_width(t_settings *map);
int		ft_check_zero_one(t_settings *set, int i, int j);
int		ft_check_map(t_settings *set, char *av1);
void	ft_int_dealer(t_settings *map, int i, int j, char c);
void	ft_fill_img_path(t_settings *map);
int		ft_key_handler(int key, t_settings *set);
void	ft_hook_key(int key, t_settings *set);
void	ft_where_is_she(t_settings *set, int i, int j);
void	ft_copy_map(char *av, t_settings *set);
void	ft_up(t_settings *set);
void	ft_down(t_settings *set);
void	ft_left(t_settings *set);
void	ft_right(t_settings *set);
void	ft_game_over(t_settings *set);
int		ft_game_over2(t_settings *set);
void	ft_gameover(t_settings *set);
int		ft_intlen(long n);
char	*ft_itoa(int n);
void	ft_valid_map(char **map, int i, int j);
int		ft_if_c(t_settings *set);
int		ft_fd_check(char *av_1);

#endif
