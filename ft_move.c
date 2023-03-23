/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: havyilma <havyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 20:53:21 by havyilma          #+#    #+#             */
/*   Updated: 2023/03/23 03:09:06 by havyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_game_over(t_settings *set)
{
	mlx_destroy_window(set->mlx, set->window);
	exit(0);
}

void	ft_up(t_settings *set)
{
	int x = set->player_pos_x;
	int y = set->player_pos_y;

	if(set->img_ch[y - 1][x] == 'C' || set->img_ch[ y - 1][x] == '0')
	{
		if(set->img_ch[y - 1][x] == 'C')
			set->count_coll++;
		set->img_ch[y][x] = '0';
		set->img_ch[y - 1][x] = 'P';
		mlx_clear_window(set->mlx, set->window);
		set->pr_pos_x = 0;
		set->pr_pos_y = 0;
		ft_int_dealer(set, 0,0,0);
	}
	else if (set->img_ch[y - 1][x] == 'E')
	{
		if(set->count_coll == set->check_coll)
			ft_game_over(set);
		else if(set->count_coll != set->check_coll)
			return;
	}
	else if (set->img_ch[y - 1][x] == '1')
		return;
}

void	ft_down(t_settings *set)
{
	int x = set->player_pos_x;
	int y = set->player_pos_y;
	if(set->img_ch[y + 1][x] == 'C' || set->img_ch[y + 1][x] == '0')
	{
		if(set->img_ch[y + 1][x] == 'C')
			set->count_coll++;
		set->img_ch[y][x] = '0';
		set->img_ch[y + 1][x] = 'P';
		mlx_clear_window(set->mlx, set->window);
		set->pr_pos_x = 0;
		set->pr_pos_y = 0;
		ft_int_dealer(set, 0,0,0);
	}
	else if (set->img_ch[y + 1][x] == 'E')
	{
		if(set->count_coll == set->check_coll)
			ft_game_over(set);
		else if(set->count_coll != set->check_coll)
			return;
	}
	else if (set->img_ch[y + 1][x] == '1')
		return;
}

void	ft_left(t_settings *set)
{
	int x = set->player_pos_x;
	int y = set->player_pos_y;
	if(set->img_ch[y][x - 1] == 'C' || set->img_ch[y][x - 1] == '0')
	{
		if(set->img_ch[y][x - 1] == 'C')
			set->count_coll++;
		set->img_ch[y][x] = '0';
		set->img_ch[y][x - 1] = 'P';
		mlx_clear_window(set->mlx, set->window);
		set->pr_pos_x = 0;
		set->pr_pos_y = 0;
		ft_int_dealer(set, 0,0,0);
	}
	else if (set->img_ch[y][x - 1] == 'E')
	{
		if(set->count_coll == set->check_coll)
			ft_game_over(set);
		else if(set->count_coll != set->check_coll)
			return;
	}
	else if (set->img_ch[y][x - 1] == '1')
		return;
}

void	ft_right(t_settings *set)
{
	int x = set->player_pos_x;
	int y = set->player_pos_y;
	if(set->img_ch[y][x + 1] == 'C' || set->img_ch[y][x + 1] == '0')
	{
		if(set->img_ch[y][x + 1] == 'C')
			set->count_coll++;
		set->img_ch[y][x] = '0';
		set->img_ch[y][x + 1] = 'P';
		mlx_clear_window(set->mlx, set->window);
		set->pr_pos_x = 0;
		set->pr_pos_y = 0;
		ft_int_dealer(set, 0,0,0);
	}
	else if (set->img_ch[y][x + 1] == 'E')
	{
		if(set->count_coll == set->check_coll)
			ft_game_over(set);
		else if(set->count_coll != set->check_coll)
			return;
	}
	else if (set->img_ch[y][x + 1] == '1')
		return;
}
