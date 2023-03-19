/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: havyilma <havyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 18:57:21 by havyilma          #+#    #+#             */
/*   Updated: 2023/03/19 16:36:36 by havyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

#define SO_LONG_H

#include <fcntl.h>
#include <stdio.h>
#include "./minilibx/mlx.h"
#include "./ft_printf/ft_printf.h"
#include "./get_next_line/get_next_line.h"

typedef struct *s_settings{
	void	*mlx;
	void	*window;
	char	**map;
	int		map_width;
	int		map_height;
	char	*path_p;
	char	*path_e;
	char	*path_c;
	char	*path_1;
	char	*path_0;
	char	*img_0;
	char	*img_1;
	char	*img_p;
	char	*img_e;
	char	*img_c;


}	*t_settings;

void	ft_init(t_settings *set);
int		ft_control_epc(t_settings *set, int i, int j, int check_e_p, int check_c);
int		ft_check_edge(t_settings *set, int i, int j);
int		ft_check_zero_one(t_settings *set, int i, int j);
void	ft_read_map(char *av, t_settings *set);
void	what_the_height(char *av, t_settings *map);
void	what_the_width(t_settings *map);
int		ft_check_zero_one(t_settings *set, int i, int j);
int		ft_check_map(t_settings *set, char *av1);
void	ft_data(t_settings *map, int i, int j);
void 	ft_fill_img_path(t_settings *map);




#endif
