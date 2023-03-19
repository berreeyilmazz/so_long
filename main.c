/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: havyilma <havyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 18:54:43 by havyilma          #+#    #+#             */
/*   Updated: 2023/03/19 16:37:25 by havyilma         ###   ########.fr       */
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
			&& set->map[i][j + 1] == '1'
			&& set->map[i - 1][j] == '1' && set->map[i + 1][j] == '1')
				return (0);
			if (set->map[i][j] == 'E' && (set->map[i][j - 1] == '1'
			&& set->map[i][j + 1] == '1'
			&& set->map[i - 1][j] == '1' && set->map[i + 1][j] == '1'))
				return (0);
			if (set->map[i][j] == 'C' && (set->map[i][j - 1] == '1'
			&& set->map[i][j + 1] == '1'
			&& set->map[i - 1][j] == '1' && set->map[i + 1][j] == '1'))
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
	ft_control_epc(set, 0, 0, 0, 0);
	int a = ft_check_edge(set, 1, 0);
	if(set->map_height < 3 || set->map_width < 3 || a != 1)
	{
		printf("Something went wrong about the MAP! Try again.");
		return(0);
	}
	if (ft_check_zero_one(set, 1, 1) != 1)
	{
		printf("Wrong position of P, E or C!");
		return(0);
	}
	return (1);
}

int main(int ac, char **av)
{
	t_settings	*set;
	int			ctrl;

	if (ac == 2)
		return (0);
	set = malloc(sizeof(t_settings));
	ctrl = ft_check_map(&set, av[1]);
	if(ctrl != 1)
		return(0);
	else
	{
	ft_init(&set);
	ft_data(&set, -1, -1);
	printf("ft_data dan outttttu\n");
	set->mlx =  mlx_init();
	set->window = mlx_new_window(set->mlx, 64 * set->map_width, 64 * set->map_height, "so_long");
	mlx_loop(set->mlx);
	}
}
