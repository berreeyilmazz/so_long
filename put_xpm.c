/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_xpm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: havyilma <havyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 11:54:02 by havyilma          #+#    #+#             */
/*   Updated: 2023/03/23 05:01:41 by havyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ft_init(t_settings *set)
{
	set->mlx = 0;
	set->window = 0;
	set->map = 0;
	set->map_width = 0;
	set->map_height = 0;
	set->path_p = 0;
	set->path_e = 0;
	set->path_c = 0;
	set->path_1 = 0;
	set->path_0 = 0;
	set->img_0 = 0;
	set->img_1 = 0;
	set->img_p = 0;
	set->img_e = 0;
	set->img_c = 0;
	set->pr_pos_x = 0;
	set->pr_pos_y = 0;
	set->count_coll = 0;
	set->check_coll = 0;
	set->player_pos_y = 0;
	set->player_pos_x = 0;
	set->move = 0;
	set->c_move = (char *)malloc(sizeof(char) * 1);
}

void ft_fill_img_path(t_settings *map)
{
	int sz;

	sz = 64;
	map->path_0 = "./pictures/unknown.xpm";
	map->path_1 = "./pictures/planks.xpm";
	map->path_p = "./pictures/cat.xpm";
	map->path_e = "./pictures/aqua.xpm";
	map->path_c = "./pictures/orfish.xpm";
	map->img_0 = mlx_xpm_file_to_image(map->mlx, map->path_0, &sz, &sz);
	map->img_1 = mlx_xpm_file_to_image(map->mlx, map->path_1, &sz, &sz);
	map->img_p = mlx_xpm_file_to_image(map->mlx, map->path_p, &sz, &sz);
	map->img_e = mlx_xpm_file_to_image(map->mlx, map->path_e, &sz, &sz);
	map->img_c = mlx_xpm_file_to_image(map->mlx, map->path_c, &sz, &sz);
}

void	ft_print_p_e_c(t_settings *map, int c)
{
	mlx_put_image_to_window(map->mlx, map->window, map->img_0, map->pr_pos_x, map->pr_pos_y);
	if(c == 'P')
		mlx_put_image_to_window(map->mlx, map->window, map->img_p, map->pr_pos_x, map->pr_pos_y);
	if(c == 'E')
		mlx_put_image_to_window(map->mlx, map->window, map->img_e, map->pr_pos_x, map->pr_pos_y);
	if(c == 'C')
		mlx_put_image_to_window(map->mlx, map->window, map->img_c, map->pr_pos_x, map->pr_pos_y);
}

void	ft_print_wall_space(t_settings *map, int c)
{
	if(c == '1')
		mlx_put_image_to_window(map->mlx, map->window, map->img_1, map->pr_pos_x, map->pr_pos_y);
	if(c == '0')
		mlx_put_image_to_window(map->mlx, map->window, map->img_0, map->pr_pos_x, map->pr_pos_y);
}

void ft_int_dealer(t_settings *map, int i, int j, int c)
{

	while (i < map->map_height)
	{
		while (j <= map->map_width + 1)
		{
			c = map->img_ch[i][j++];
			if (c == '0' || c == '1' || c == 'P' || c == 'E' || c == 'C')
			{
				if (c == '1' || c == '0')
					ft_print_wall_space(map, c);
				else if (c == 'P' || c == 'E' || c == 'C' )
					ft_print_p_e_c(map, c);
				map->pr_pos_x += 64;
			}
			else if(c == '\n')
			{
				map->pr_pos_x = 0;
				map->pr_pos_y += 64;
			}
		}
		j = 0;
		i++;
	}
}
