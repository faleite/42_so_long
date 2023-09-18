/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 17:33:20 by faaraujo          #+#    #+#             */
/*   Updated: 2023/09/18 21:45:57 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	find_player(void)
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
			else
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

void	flood_fill(int y, int x, char **matrix)
{
	if (y < 0 || y >= map()->y_len || x < 0 || x >= map()->x_len)
		return ;
	if (matrix[y][x] == 'E')
		matrix[y][x] = '1';
	if (matrix[y][x] != '1' && matrix[y][x] != 'V')
	{
		matrix[y][x] = 'V';
	}
	flood_fill(x - 1, y, matrix);
	flood_fill(x + 1, y, matrix);
	flood_fill(x, y - 1, matrix);
	flood_fill(x, y + 1, matrix);
}

int	validate_map(void)
{
	int	x;
	int	y;
	int	result;

	find_player();
	flood_fill(field()->x_player, field()->y_player, map()->cp_map);
	y = 0;
	while (y < map()->y_len)
	{
		x = 0;
		ft_printf("%s\n", map()->cp_map[y]);
		while (x < map()->x_len)
		{
			if (map()->cp_map[y][x] == '0')
				return (0);
			x++;
		}
		y++;
	}
	ft_printf("%d\n", result);
	return (result);
}
