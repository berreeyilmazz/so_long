/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: havyilma <havyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 02:35:04 by havyilma          #+#    #+#             */
/*   Updated: 2023/03/23 06:26:54 by havyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int ft_key_handler(int key, t_settings *set)
{
	(void)set;
	ft_hook_key(key, set);
	return (0);
}

void ft_hook_key(int key, t_settings *set)
{
	ft_where_is_she(set, -1, -1);
	if (key == 13 || key == 126 )
	{
		set->move++;
		ft_up(set);
	}
	else if (key == 1 || key == 125)
	{
		set->move++;
		ft_down(set);
	}
	else if (key == 0 || key == 123)
	{
		set->move++;
		ft_left(set);
	}
	else if (key == 2 || key == 124)
	{
		set->move++;
		ft_right(set);
	}
	else if (key == 53)
	{
		ft_game_over(set);
		exit(0);
	}
	set->c_move = ft_itoa(set->move);
	free(set->c_move);
	//printf("++%s\n", set->c_move);
	mlx_string_put(set->mlx, set->window, 64 * (set->map_width / 2), 30, 000011, set->c_move);
}
