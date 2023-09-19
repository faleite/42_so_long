/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 17:33:20 by faaraujo          #+#    #+#             */
/*   Updated: 2023/09/19 20:56:32 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	find_player(void)
{
	int	x;
	int	y;

	y = 0;
	while (y < map()->y_len)
	{
		x = 0;
		while (x < map()->x_len)
		{
			if (map()->matrix[y][x] == 'P')
			{
				if (!field()->x_player && !field()->y_player)
				{
					field()->x_player = x;
					field()->y_player = y;
				}
				break ;
			}
			x++;
		}
		y++;
	}
}

void	flood_fill(char **matrix, int x, int y)
{
	if (check_fill(matrix, x - 1, y))
		flood_fill(matrix, x - 1, y);
	if (check_fill(matrix, x + 1, y))
		flood_fill(matrix, x + 1, y);
	if (check_fill(matrix, x, y - 1))
		flood_fill(matrix, x, y - 1);
	if (check_fill(matrix, x, y + 1))
		flood_fill(matrix, x, y + 1);	
}

int	check_fill(char **matrix, int x, int y)
{
	if (y < 0 || y >= map()->y_len || x < 0 || x >= map()->x_len)
		return (0);
	if (matrix[y][x] == 'E')
		matrix[y][x] = '1';
	if (matrix[y][x] != '1' && matrix[y][x] != '_')
	{
		matrix[y][x] = '_';
		return (1);
	}
	return (0);
}

int	playable_map(void)
{
	int	x;
	int	y;

	find_player();
	flood_fill(map()->matrix, field()->x_player, field()->y_player);
	y = 0;
	while (y < map()->y_len)
	{
		x = 0;
		while (x < map()->x_len)
		{
			if (map()->matrix[y][x] != '1' && map()->matrix[y][x] != '_')
				return (1);				
			x++;
		}
		y++;
	}
	return (0);
}
