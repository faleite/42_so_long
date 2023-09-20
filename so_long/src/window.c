/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 17:44:31 by faaraujo          #+#    #+#             */
/*   Updated: 2023/09/20 21:45:30 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	destroy_window(t_map *map)
{
	mlx_destroy_window(map->mlx_ptr, map->win_ptr);
	mlx_destroy_display(map->mlx_ptr);
	free(map->mlx_ptr);
	exit(0);
}

int	on_keypress(int keycode, t_map *map)
{
	if (keycode == 65307)
	{
		ft_printf("The %d key (ESC) has been pressed\n\n", keycode);
		destroy_window(map);
		exit(1);
	}
	ft_printf("The %d key has been pressed\n\n", keycode);
	return (0);
}

int	build_window(void)
{
	t_map	data;

	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return (1);
	data.win_ptr = mlx_new_window(data.mlx_ptr, map()->size_x * PX, map()->size_y * PX, "./so_long");
	if (!data.win_ptr)
	{
		mlx_destroy_display(data.mlx_ptr);
		free(data.mlx_ptr);
		return (1);
	}
	// mlx_xpm_file_to_image(data.mlx_ptr, PATH, map()->size_x, map()->size_y);
	// mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, PATH, field()->x_player * PX, field()->y_player * PX);
	mlx_hook(data.win_ptr, 2, 1L, on_keypress, &data);
	mlx_hook(data.win_ptr, 17, 0L, (int (*)(void *param))destroy_window, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
