/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 18:54:33 by faaraujo          #+#    #+#             */
/*   Updated: 2023/09/15 22:14:00 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	count_field(void)
{
	int	i;
	int	j;

	i = 0;
	while (data()->matrix && data()->matrix[i])
	{
		j = 0;
		while (data()->matrix[i][j])
		{
			if (data()->matrix[i][j] == 'E')
				field()->out++;
			if (data()->matrix[i][j] == 'P')
				field()->player++;
			if (data()->matrix[i][j] == 'C')
				field()->collect++;
			j++;
		}
		i++;
	}
}

int	check_field(void)
{
	count_field();

	if (field()->out != 1)
		err_case("Error\nThere must be a way out of this game\n");
	if (field()->player != 1)
		err_case("Error\nThere must be a player in this game\n");
	if (field()->collect < 1)
		err_case("Error\nThere must be at least one collectible in this game\n");
	return (0);
}


int	check_map(void)
{
	int	i;

	i = 0;
	heigth_map();
	if (!data()->matrix[i])
		err_case("Error\nThe map is not a valid map\n");
	while (data()->matrix && data()->matrix[i])
	{
		if (check_side_wall(data()->matrix[i]))
			err_case("Error\nThe map should have a wall around it\n");
		if (check_wall(data()->matrix[0])
			|| check_wall(data()->matrix[data()->height - 1]))
			err_case("Error\nThe map should have a valid wall around it\n");
		if ((i > 0 && i < data()->height - 1) && !check_wall(data()->matrix[i]))
			err_case("Error\nInside the map should not have a wall closed\n");
		if (data()->height < 3)
			err_case("Error\nThe map is not a valid map\n");
		if (check_len(data()->matrix[i]))
			err_case("Error\nThe map is not a type of rectangle\n");
		i++;
	}
	check_field();
	return (0);
}
