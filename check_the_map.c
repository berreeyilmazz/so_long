/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_the_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: havyilma <havyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 19:57:50 by havyilma          #+#    #+#             */
/*   Updated: 2023/03/25 07:20:14 by havyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_read_map(char *av, t_settings *set)
{
	int	i;
	int	fd;

	i = 1;
	set->map = malloc((set->map_height + 1) * sizeof(char *));
	fd = open(av, O_RDONLY);
	set->map[0] = get_next_line(fd);
	if (set->map[0] == NULL)
	{
		write(1, "ERROR!", 6);
		exit(0);
	}
	while (i < set->map_height)
	{
		set->map[i] = get_next_line(fd);
		i++;
	}
	set->map[i] = NULL;
	close(fd);
	ft_copy_map(av, set);
}

void	what_the_height(char *av, t_settings *map)
{
	int		fd;
	int		i;
	char	*temp;

	i = 0;
	fd = open(av, O_RDONLY);
	temp = get_next_line(fd);
	while (temp)
	{
		free(temp);
		temp = get_next_line(fd);
		i++;
	}
	close(fd);
	map->map_height = i;
}

void	what_the_width(t_settings *set)
{
	int	size;
	int	i;

	i = 1;
	size = ft_strlen(set->map[0]) - 1;
	while (i < set->map_height - 2)
	{
		if (size != ft_strlen(set->map[i]) - 1)
			return ;
		i++;
	}
	if (i == set->map_height - 2)
	{
		if (!(size != ft_strlen(set->map[i])))
			return ;
		set->map_width = size;
	}
}

int	ft_control_epc(t_settings *set, int i, int j, int check_p)
{
	while (++i <= set->map_height - 1)
	{
		while (++j <= set->map_width - 1)
		{
			if (set->img_ch[i][j] == 'E')
				set->count_e++;
			if (set->img_ch[i][j] == 'P')
				check_p++;
			if (set->img_ch[i][j] == 'C')
				set->check_coll++;
			if (set->img_ch[i][j] != '1' && set->img_ch[i][j] != '0'
				&& set->img_ch[i][j] != 'P' &&
				set->img_ch[i][j] != 'E' && set->img_ch[i][j] != 'C'
					&& set->img_ch[i][j] != '\n')
			{
				write(1, "ERROR! Wrong parameter!", 23);
				return (0);
			}
		}
		j = -1;
	}
	if (set->count_e != 1 || set->check_coll < 1 || check_p != 1)
		return (0);
	return (1);
}

int	ft_check_edge(t_settings *set, int i, int j)
{
	while (j < set->map_width)
	{
		if (set->img_ch[0][j] != '1')
			return (0);
		j++;
	}
	j = 0;
	while (i < set->map_height)
	{
		while (j < set->map_width)
		{
			if (set->img_ch[set->map_height - 1][j] != '1'
				|| set->img_ch[i][set->map_width - 1] != '1'
				|| set->img_ch[i][0] != '1')
				return (0);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}
