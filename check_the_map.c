/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_the_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: havyilma <havyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 19:57:50 by havyilma          #+#    #+#             */
/*   Updated: 2023/03/23 02:57:24 by havyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	what_the_height(char *av, t_settings *map)
{
	int		fd;
	int		i;
	char	*temp;

	i = 0;
	fd = open(av, O_RDONLY);
	temp = get_next_line(fd);
	while(temp)
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
	while(i < set->map_height - 2)
	{
		if(size != ft_strlen(set->map[i]) - 1)
			return;
		i++;
	}
	if(i == set->map_height - 2)
		if(!(size != ft_strlen(set->map[i])))
			return;
	if(i == set->map_height - 2)
		set->map_width = size;
}
void	ft_copy_map(char *av, t_settings *set)
{
	int	i;
	int	fd;

	i = 0;
	set->img_ch = malloc((set->map_height + 1) * sizeof(char*));
	fd = open(av, O_RDONLY);
	while (i < set->map_height)
	{
		set->img_ch[i] = get_next_line(fd);
		i++;
	}
	set->img_ch[i] = NULL;
	close(fd);
}

void	ft_read_map(char *av, t_settings *set)
{
	int	i;
	int	fd;

	i = 0;
	set->map = malloc((set->map_height + 1) * sizeof(char*));
	fd = open(av, O_RDONLY);
	while (i < set->map_height)
	{
		set->map[i] = get_next_line(fd);
		i++;
	}
	set->map[i] = NULL;
	close(fd);
	set->img_ch = set->map;
}

int	ft_control_epc(t_settings *set, int i, int j, int check_e_p, int check_c)
{
	check_e_p = 0;
	check_c = 0;
	while (i <= set->map_height - 1)
	{
		while (j <= set->map_width - 1)
		{
			if (set->map[i][j] == 'E' || set->map[i][j] == 'P')
				check_e_p++;
			if (set->map[i][j] == 'C')
				check_c++;
			if (set->map[i][j] != '1' && set->map[i][j] != '0' && set->map[i][j] != 'P' &&
			set->map[i][j] != 'E' && set->map[i][j] != 'C' && set->map[i][j] != '\n')
				return(0);
			j++;
		}
		j = 0;
		i++;
	}
	if (check_e_p != 2 || check_c == 0)
		return (0);
	set->check_coll = check_c;
	return (1);
}

int	ft_check_edge(t_settings *set, int i, int j)
{
	while (j <= set->map_width - 1)
	{
		if (set->map[0][j] != '1')
			return (0);
		j++;
	}
	j = 0;
	while (i < set->map_height)
	{
		while (j < set->map_width)
		{
			if (set->map[set->map_height - 1][j] != '1' || set->map[i][set->map_width - 1] != '1'
			|| set->map[i][0] != '1')
				return(0);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}
