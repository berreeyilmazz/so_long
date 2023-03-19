/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_png.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: havyilma <havyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 11:54:02 by havyilma          #+#    #+#             */
/*   Updated: 2023/03/19 16:07:23 by havyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init(t_settings *set)
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
}

void ft_fill_img_path(t_settings *map)
{
	int sz;

	sz = 64;
	map->path_0 = "../pictures/background.xpm";
	map->img_0 = mlx_xpm_file_to_image(map->mlx, map->path_0, &sz, &sz);
	/*map->path_p = "../pictures/cat.xpm";
	map->path_e = "../pictures/bowl.xpm";
	map->path_c = "../pictures/fish.xpm";
	map->path_1 = "../pictures/public.xpm";
	map->img_1 = mlx_xpm_file_to_image(map->mlx, map->path_1, &sz, &sz);
	map->img_p = mlx_xpm_file_to_image(map->mlx, map->path_p, &sz, &sz);
	map->img_e = mlx_xpm_file_to_image(map->mlx, map->path_e, &sz, &sz);
	map->img_c = mlx_xpm_file_to_image(map->mlx, map->path_c, &sz, &sz);
	*/printf("---%s", map->img_0);
}

void	ft_data(t_settings *map, int i, int j)
{
	ft_fill_img_path(map);
	while (++i < map->map_height)
	{
		printf("whiledan kaç kere\n");
		while (++j < map->map_width)
		{
			if(map->map[i][j] == '0')
				mlx_put_image_to_window(map->mlx, map->window, map->img_0, i, j);
			/*if(map->map[i][j] == 'P')
				mlx_put_image_to_window(map->mlx, map->window, map->img_p, i, j);
			else if(map->map[i][j] == '1')
				mlx_put_image_to_window(map->mlx, map->window, map->img_1, i, j);
			else if(map->map[i][j] == 'E')
				mlx_put_image_to_window(map->mlx, map->window, map->img_e, i, j);
			if(map->map[i][j] == 'C')
				mlx_put_image_to_window(map->mlx, map->window, map->img_c, i, j);
		*/}
		j = -1;
	}
}
