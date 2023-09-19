/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 17:44:31 by faaraujo          #+#    #+#             */
/*   Updated: 2023/09/19 21:42:54 by faaraujo         ###   ########.fr       */
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
	t_map	map;

	map.mlx_ptr = mlx_init();
	if (!map.mlx_ptr)
		return (1);
	map.win_ptr = mlx_new_window(map.mlx_ptr, 600, 400, "My first Window");
	if (!map.win_ptr)
	{
		mlx_destroy_display(map.mlx_ptr);
		free(map.mlx_ptr);
		return (1);
	}
	mlx_hook(map.win_ptr, 2, 1L, on_keypress, &map);
	mlx_hook(map.win_ptr, 17, 0L, (int (*)(void *param))destroy_window, &map);
	mlx_loop(map.mlx_ptr);
	return (0);
}
