/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_over.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: havyilma <havyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 01:25:47 by havyilma          #+#    #+#             */
/*   Updated: 2023/03/25 01:43:14 by havyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_game_over(t_settings *set)
{
	mlx_destroy_window(set->mlx, set->window);
	exit(0);
}

int	ft_game_over2(t_settings *set)
{
	mlx_destroy_window(set->mlx, set->window);
	exit(0);
	return (123);
}

void	ft_gameover(t_settings *set)
{
	set->move++;
	free(set->c_move);
	set->c_move = ft_itoa(set->move);
	mlx_string_put(set->mlx, set->window, 64 * (set->map_width / 2), 30, 000011,
		set->c_move);
	mlx_destroy_window(set->mlx, set->window);
	exit(0);
}
