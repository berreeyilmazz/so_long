/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: havyilma <havyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 18:54:43 by havyilma          #+#    #+#             */
/*   Updated: 2023/03/23 06:22:25 by havyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	ft_fill_img_path(&set);
	ft_copy_map(av[1], &set);
	ft_int_dealer(&set, 0, 0, 0);

	mlx_string_put(set.mlx, set.window, 64 * (set.map_width / 2), 30, 000011, set.c_move);
	mlx_hook(set.window, 2, 1L << 0, ft_key_handler, &set);
	mlx_loop(set.mlx);
	return (0);
}
