/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 17:44:31 by faaraujo          #+#    #+#             */
/*   Updated: 2023/09/25 21:38:51 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// #define ESC 65307

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
	//ft_printf("%d\n", mlx_hook(map()->win_ptr, 2, 1L, moves, map()));
	get_image();
	put_image();
	// mlx_hook(map()->win_ptr, 2, 1L, on_keypress, map());
	mlx_hook(map()->win_ptr, 2, 1L, moves, map());
	mlx_hook(map()->win_ptr, 17, 0L,
		(int (*)(void *param))destroy_window, map());
	mlx_loop(map()->mlx_ptr);
	return (0);
}

int	on_keypress(int keycode)
{
	if (keycode == ESC)
	{
		ft_printf("The %d key (ESC) has been pressed\n\n", keycode);
		destroy_window();
		exit(1);
	}
	ft_printf("The %d key has been pressed\n\n", keycode);
	return (0);
}

int	destroy_window(void)
{
	ft_printf("Collect: %d\n", field()->collect);
	destroy_image();
	mlx_destroy_window(map()->mlx_ptr, map()->win_ptr);
	mlx_destroy_display(map()->mlx_ptr);
	free(map()->mlx_ptr);
	free_map(map()->matrix);
	exit(0);
}

int	destroy_image(void)
{
	mlx_destroy_image(map()->mlx_ptr, img()->wall);
	mlx_destroy_image(map()->mlx_ptr, img()->floor);
	mlx_destroy_image(map()->mlx_ptr, img()->exit);
	mlx_destroy_image(map()->mlx_ptr, img()->crystal);
	mlx_destroy_image(map()->mlx_ptr, img()->player);
}
