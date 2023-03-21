/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: havyilma <havyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 18:54:43 by havyilma          #+#    #+#             */
/*   Updated: 2023/03/21 04:40:26 by havyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int ft_check_zero_one(t_settings *set, int i, int j)
{
	while (i < set->map_height - 1)
	{
		while (j < set->map_width - 1)
		{
			if (set->map[i][j] == 'P' && set->map[i][j - 1] == '1' && set->map[i][j + 1] == '1' && set->map[i - 1][j] == '1' && set->map[i + 1][j] == '1')
				return (0);
			if (set->map[i][j] == 'E' && (set->map[i][j - 1] == '1' && set->map[i][j + 1] == '1' && set->map[i - 1][j] == '1' && set->map[i + 1][j] == '1'))
				return (0);
			if (set->map[i][j] == 'C' && (set->map[i][j - 1] == '1' && set->map[i][j + 1] == '1' && set->map[i - 1][j] == '1' && set->map[i + 1][j] == '1'))
				return (0);
			j++;
		}
		j = 1;
		i++;
	}
	return (1);
}

int ft_check_map(t_settings *set, char *av1)
{
	what_the_height(av1, set);
	ft_read_map(av1, set);
	what_the_width(set);
	ft_control_epc(set, 0, 0, 0, 0);
	ft_check_edge(set, 1, 0);
	if (set->map_height < 3 || set->map_width < 3 || ft_check_edge(set, 1, 0) != 1)
	{
		printf("Something went wrong about the MAP! Try again.");
		return (0);
	}
	if (ft_check_zero_one(set, 1, 1) != 1)
	{
		printf("Wrong position of P, E or C!");
		return (0);
	}
	// printf("==h=%d\n==w=%d\n", set->map_height,set->map_width);
	return (1);
}

int main(int ac, char **av)
{
	t_settings set;

	ft_init(&set);
	if (ac != 2 || !ft_check_map(&set, av[1]))
		return (0);
	set.mlx = mlx_init();
	set.window = mlx_new_window(set.mlx, 64 * (set.map_width), 64 * set.map_height, "so_long");
	set.img = mlx_new_image(set.mlx, 64 * (set.map_width), 64 * set.map_height);
	set.addr = mlx_get_data_addr(set.img, &set.bits_per_pixel, &set.line_length, &set.endian);
	ft_data(&set, 0, 0);
	mlx_hook(set.window, 2, 1L << 0, key_handler, &set);
	mlx_loop(set.mlx);
	return (0);
}

int key_handler(int key, t_settings *set)
{
	(void)set;
	//printf("%d\n",key);
	hook_key(key, set);
	return (0);
}

void hook_key(int key, t_settings *set)
{
	(void)set;

	if (key == 13)
		printf("yukari\n");
	else if (key == 0)
		printf("sol\n");
	else if (key == 1)
		printf("asagi\n");
	else if (key == 2)
		printf("sag\n");
}
