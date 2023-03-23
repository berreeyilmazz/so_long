/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_the_map_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: havyilma <havyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 02:29:34 by havyilma          #+#    #+#             */
/*   Updated: 2023/03/23 03:18:50 by havyilma         ###   ########.fr       */
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
	return (1);
}

void	ft_where_is_she(t_settings *set, int i, int j)
{
	while (++i < set->map_height)
	{
		j = -1;
		while (++j < set->map_width - 1)
		{
			if(set->img_ch[i][j] == 'P')
			{
				set->player_pos_x = j;
				set->player_pos_y = i;
			}
		}
	}
}
