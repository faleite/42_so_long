/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 18:54:33 by faaraujo          #+#    #+#             */
/*   Updated: 2023/09/20 17:30:43 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_map(void)
{
	int	i;

	i = 0;
	heigth_map();
	if (!map()->matrix[i])
		err_case("Error\nThe map is not a valid map\n");
	while (map()->matrix && map()->matrix[i])
	{
		if (check_side_wall(map()->matrix[i]))
			err_case("Error\nThe map should have a wall around it\n");
		if (check_wall(map()->matrix[0])
			|| check_wall(map()->matrix[map()->size_y - 1]))
			err_case("Error\nThe map should have a valid wall around it\n");
		if ((i > 0 && i < map()->size_y - 1) && !check_wall(map()->matrix[i]))
			err_case("Error\nInside the map should not have a wall closed\n");
		if (map()->size_y < 3)
			err_case("Error\nThe map is not a valid map\n");
		if (check_len(map()->matrix[i]))
			err_case("Error\nThe map is not a type of rectangle\n");
		i++;
	}
	if (check_field())
		err_case("Error\nThe map contains one or more invalid fields\n");
	return (0);
}

int	invalid_field(void)
{
	int	i;
	int	j;
	int	other;

	i = 0;
	other = 0;
	while (map()->matrix && map()->matrix[i])
	{
		j = 0;
		while (map()->matrix[i][j])
		{
			if (map()->matrix[i][j] != 'E' && map()->matrix[i][j] != 'P'
				&& map()->matrix[i][j] != 'C' && map()->matrix[i][j] != '1'
				&& map()->matrix[i][j] != '0' && map()->matrix[i][j] != '\n')
				other++;
			j++;
		}
		i++;
	}
	return (other);
}

int	count_field(void)
{
	int	i;
	int	j;

	i = 0;
	if (invalid_field())
		return (1);
	while (map()->matrix && map()->matrix[i])
	{
		j = 0;
		while (map()->matrix[i][j])
		{
			if (map()->matrix[i][j] == 'E')
				field()->out++;
			if (map()->matrix[i][j] == 'P')
				field()->player++;
			if (map()->matrix[i][j] == 'C')
				field()->collect++;
			j++;
		}
		i++;
	}
	return (0);
}

int	check_field(void)
{
	if (count_field())
		return (1);
	if (field()->out != 1)
		err_case("Error\nThere must be a way out of this game\n");
	if (field()->player != 1)
		err_case("Error\nThere must be a player in this game\n");
	if (field()->collect < 1)
		err_case("Error\nThere must be at least one collectible in this game\n");
	return (0);
}
