/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 17:44:31 by faaraujo          #+#    #+#             */
/*   Updated: 2023/09/27 20:24:14 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	build_window(void)
{
	void	*window;

	map()->mlx_ptr = mlx_init();
	if (!map()->mlx_ptr)
		return (1);
	window = mlx_new_window(map()->mlx_ptr,
			map()->size_x * SIZE,
			map()->size_y * SIZE,
			"./so_long");
	map()->win_ptr = window;
	if (!map()->win_ptr)
	{
		mlx_destroy_display(map()->mlx_ptr);
		free(map()->mlx_ptr);
		return (1);
	}
	get_image();
	put_image();
	mlx_hook(map()->win_ptr, 2, 1L, (void *) moves, map());
	mlx_hook(map()->win_ptr, 17, 0L,
		(int (*)(void *param))destroy_window, map());
	mlx_loop(map()->mlx_ptr);
	return (0);
}

int	destroy_window(void)
{
	destroy_image();
	mlx_destroy_window(map()->mlx_ptr, map()->win_ptr);
	mlx_destroy_display(map()->mlx_ptr);
	free(map()->mlx_ptr);
	free_map(map()->matrix);
	exit(0);
}

int	destroy_image(void)
{
	if (img()->wall)
		mlx_destroy_image(map()->mlx_ptr, img()->wall);
	if (img()->floor)
		mlx_destroy_image(map()->mlx_ptr, img()->floor);
	if (img()->exit)
		mlx_destroy_image(map()->mlx_ptr, img()->exit);
	if (img()->crystal)
		mlx_destroy_image(map()->mlx_ptr, img()->crystal);
	if (img()->p_up)
		mlx_destroy_image(map()->mlx_ptr, img()->p_up);
	if (img()->p_down)
		mlx_destroy_image(map()->mlx_ptr, img()->p_down);
	if (img()->p_left)
		mlx_destroy_image(map()->mlx_ptr, img()->p_left);
	if (img()->p_right)
		mlx_destroy_image(map()->mlx_ptr, img()->p_right);
	return (1);
}
