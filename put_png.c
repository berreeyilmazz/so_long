/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_png.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: havyilma <havyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 11:54:02 by havyilma          #+#    #+#             */
/*   Updated: 2023/03/21 04:45:24 by havyilma         ###   ########.fr       */
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
	set->fill_x = 0;
	set->fill_y = 0;
}

void print_map_as_ascii(t_settings *map)
{
	int i;
	int j;

	i = 0;
	while(map->map[i])
	{
		j = -1;
		while (map->map[i][++j])
		{
			printf("%i-",map->map[i][j]);
			if (map->map[i][j] == 10)
				printf("\n");
		}
		i++;
	}
}

void ft_fill_img_path(t_settings *map)
{
	int sz;

	sz = 64;
	map->path_0 = "./pictures/background.xpm";
	map->img_0 = mlx_xpm_file_to_image(map->mlx, map->path_0, &sz, &sz);
	map->path_1 = "./pictures/cat.xpm";
	map->img_1 = mlx_xpm_file_to_image(map->mlx, map->path_1, &sz, &sz);
	map->path_p = "./pictures/cat.xpm";
	map->path_e = "./pictures/aqua.xpm";
	map->path_c = "./pictures/orfish.xpm";
	map->img_p = mlx_xpm_file_to_image(map->mlx, map->path_p, &sz, &sz);
	map->img_e = mlx_xpm_file_to_image(map->mlx, map->path_e, &sz, &sz);
	map->img_c = mlx_xpm_file_to_image(map->mlx, map->path_c, &sz, &sz);
}

void ft_data(t_settings *map, int i, int j)
{
	ft_fill_img_path(map);
	int c;

	i = 0;
	while (i < map->map_height)
	{
		j = 0;
		while (j < map->map_width + 2)
		{
			c = map->map[i][j];
			if (is_char_valid(c))
			{
				printf("c:%i\n",c);
				if (c == '1')
				{
					mlx_put_image_to_window(map->mlx, map->window, map->img_1, map->fill_x, map->fill_y);
					map->fill_x += 64;
				}
				else if (c == 'C')
				{
					mlx_put_image_to_window(map->mlx, map->window, map->img_c, map->fill_x, map->fill_y);
					map->fill_x += 64;
				}
				else if (c == 'P')
				{
					mlx_put_image_to_window(map->mlx, map->window, map->img_p, map->fill_x, map->fill_y);
					map->fill_x += 64;
				}
				else if (c == 'E')
				{
					mlx_put_image_to_window(map->mlx, map->window, map->img_e, map->fill_x, map->fill_y);
					map->fill_x += 64;
				}
				else if (c == 10)
				{
					map->fill_x = 0;
					map->fill_y += 64;
				}
				else // 0 gelirse
				{
					map->fill_x += 64;
				}
			}
			j++;
		}
		i++;
	}
}

int is_char_valid(char c)
{
	return (c == '0' || c == '1' || c == 'P' || c == 'C' || c == 'E' || c == '\n');
}
