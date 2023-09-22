/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 20:21:27 by faaraujo          #+#    #+#             */
/*   Updated: 2023/09/22 21:52:17 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	*file_to_image(char *path)
{
	void	*img;
	int		width;
	int		height;

	img = mlx_xpm_file_to_image(map()->mlx_ptr, path, &width, &height);
	return (img);
}

void	image_to_window(void *image, int x, int y)
{
	mlx_put_image_to_window
	(
		map()->mlx_ptr,
		map()->win_ptr,
		image,
		x * SIZE,
		y * SIZE
	);
}

void	get_image(void)
{
	img()->floor = file_to_image(FLOOR);
	img()->wall = file_to_image(WALL);
}

void	put_image(void)
{
	int	x;
	int	y;

	x = 0;
	while (map()->matrix && map()->matrix[x])
	{
		y = 0;
		while (map()->matrix[x][y])
		{
			if (map()->matrix[x][y] == '0')
				image_to_window(img()->floor, y, x);
			else if (map()->matrix[x][y] == '1')
				image_to_window(img()->wall, y, x);
			y++;
		}
		x++;
	}
}
