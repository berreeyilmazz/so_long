/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_the_map_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: havyilma <havyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 01:14:12 by havyilma          #+#    #+#             */
/*   Updated: 2023/03/25 10:46:30 by havyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_fd_check(char *av_1)
{
	int	fd;

	if ((av_1[ft_strlen(av_1) - 1] != 'r' && av_1[ft_strlen(av_1) - 2] != 'e'
			&& av_1[ft_strlen(av_1) - 3] != 'b'
			&& av_1[ft_strlen(av_1) - 4] != '.')
		|| ft_strlen(av_1) < 5)
	{
		write(1, "ERROR!", 6);
		return (0);
	}
	fd = open(av_1, O_RDONLY);
	if (fd < 0)
		return (0);
	close(fd);
	return (1);
}

void	ft_copy_map(char *av, t_settings *set)
{
	int	i;
	int	fd;

	i = 0;
	set->img_ch = malloc((set->map_height + 1) * sizeof(char *));
	fd = open(av, O_RDONLY);
	while (i < set->map_height)
	{
		set->img_ch[i] = get_next_line(fd);
		i++;
	}
	set->img_ch[i] = NULL;
	close(fd);
}
