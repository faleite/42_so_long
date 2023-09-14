/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 18:54:33 by faaraujo          #+#    #+#             */
/*   Updated: 2023/09/14 21:13:04 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"


int	check_map(void)
{
	int	i;

	i = 0;
	heigth_map();
	while (data()->matrix && data()->matrix[i])
	{
		if (check_side_wall(data()->matrix[i]))
			err_case("Error\nThe map should have a wall around it\n");
		if (check_wall(data()->matrix[0])
			|| check_wall(data()->matrix[data()->height - 1]))
			err_case("Error\nThe map should have a valid wall around it\n");
		if ((i > 0 && i < data()->height - 1) && !check_wall(data()->matrix[i]))
			err_case("Error\nInside the map should not have a wall closed\n");
		if (check_len(data()->matrix[i]))
			err_case("Error\nThe map is not a type of rectangle\n");
		i++;
	}
	return (0);
}
