/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_the_map_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: havyilma <havyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 02:29:34 by havyilma          #+#    #+#             */
/*   Updated: 2023/03/25 08:41:44 by havyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_zero_one(t_settings *set, int i, int j)
{
	while (i < set->map_height - 1)
	{
		while (j < set->map_width - 1)
		{
			if (set->map[i][j] == 'P' && set->map[i][j - 1] == '1'
				&& set->map[i][j + 1] == '1' && set->map[i - 1][j] == '1'
				&& set->map[i + 1][j] == '1')
				return (0);
			if (set->map[i][j] == 'E' && (set->map[i][j - 1] == '1'
					&& set->map[i][j + 1] == '1' && set->map[i - 1][j] == '1'
					&& set->map[i + 1][j] == '1'))
				return (0);
			if (set->map[i][j] == 'C' && (set->map[i][j - 1] == '1'
					&& set->map[i][j + 1] == '1' && set->map[i - 1][j] == '1'
					&& set->map[i + 1][j] == '1'))
				return (0);
			j++;
		}
		j = 1;
		i++;
	}
	return (1);
}

int	ft_check_map(t_settings *set, char *av1)
{
	what_the_height(av1, set);
	ft_read_map(av1, set);
	what_the_width(set);
	if (!ft_check_edge(set, 1, 0) || ft_control_epc(set, -1, -1, 0) == 0
		|| set->check_coll == 0 || set->count_e != 1)
	{
		write(1, "ERROR! Wrong map!", 17);
		return (0);
	}
	if (ft_if_c(set) == 0 || ft_check_zero_one(set, 1, 1) != 1)
	{
		write(1, "ERROR! Map is not valid!", 24);
		return (0);
	}
	if (set->map_height < 3 || set->map_width < 3 || ft_check_edge(set, 1,
			0) != 1 || set->map[0] == NULL)
	{
		write(1, "ERROR! Something went wrong about the MAP! Try again.", 53);
		return (0);
	}
	ft_where_is_she(set, -1, -1);
	return (1);
}

void	ft_valid_map(char **map, int i, int j)
{
	map[j][i] = '*';
	if (map[j - 1][i] != '1' && map[j - 1][i] != '*' && map[j - 1][i] != 'E')
		ft_valid_map(map, i, j - 1);
	if (map[j + 1][i] != '1' && map[j + 1][i] != '*' && map[j + 1][i] != 'E')
		ft_valid_map(map, i, j + 1);
	if (map[j][i - 1] != '1' && map[j][i - 1] != '*' && map[j][i - 1] != 'E')
		ft_valid_map(map, i - 1, j);
	if (map[j][i + 1] != '1' && map[j][i + 1] != '*' && map[j][i + 1] != 'E')
		ft_valid_map(map, i + 1, j);
}

int	ft_if_c(t_settings *set)
{
	int	i;
	int	j;

	ft_where_is_she(set, -1, -1);
	ft_valid_map(set->map, set->player_pos_x, set->player_pos_y);
	i = 0;
	while (i < set->map_height)
	{
		j = -1;
		while (++j < set->map_width)
		{
			if (set->map[i][j] == 'C')
				return (0);
			if (set->map[i][j] == 'E'
			&& set->map[i][j + 1] != '*'
			&& set->map[i][j - 1] != '*'
			&& set->map[i + 1][j] != '*'
			&& set->map[i - 1][j] != '*')
				return (0);
		}
		i++;
	}
	return (1);
}

void	ft_where_is_she(t_settings *set, int i, int j)
{
	while (++i < set->map_height)
	{
		j = -1;
		while (++j < set->map_width)
		{
			if (set->img_ch[i][j] == 'P')
			{
				set->player_pos_x = j;
				set->player_pos_y = i;
			}
		}
	}
}
