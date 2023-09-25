/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 18:20:48 by faaraujo          #+#    #+#             */
/*   Updated: 2023/09/25 22:10:18 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	moves(int keycode)
{
	if (field()->moves == 0)
		field()->moves = 1;
	if (keycode == ESC)
		destroy_window();
	else if (keycode == W || keycode == UP)
		move_up();
	else if (keycode == S || keycode == DOWN)
		move_down();
	else if (keycode == D || keycode == RIGHT)
		move_right();
	else if (keycode == A || keycode == LEFT)
		move_left();
}

void	move_up(void)
{
	if (map()->matrix[field()->y_p - 1][field()->x_p] != '1'
	&& map()->matrix[field()->y_p - 1][field()->x_p] != 'E')
	{
		if (map()->matrix[field()->y_p - 1][field()->x_p] == 'C')
		{
			map()->matrix[field()->y_p - 1][field()->x_p] = '0';
			field()->collect--;
		}
		field()->y_p--;
		image_to_window(img()->floor, field()->x_p, field()->y_p + 1);
		image_to_window(img()->player, field()->x_p, field()->y_p);
		ft_printf("Moves: %d\n", field()->moves++);
	}
}

void	move_down(void)
{
	if (map()->matrix[field()->y_p + 1][field()->x_p] != '1'
	&& map()->matrix[field()->y_p + 1][field()->x_p] != 'E')
	{
		if (map()->matrix[field()->y_p + 1][field()->x_p] == 'C')
		{
			map()->matrix[field()->y_p + 1][field()->x_p] = '0';
			field()->collect--;
		}
		field()->y_p++;
		image_to_window(img()->floor, field()->x_p, field()->y_p - 1);
		image_to_window(img()->player, field()->x_p, field()->y_p);
		ft_printf("Moves: %d\n", field()->moves++);
	}
}

void	move_right(void)
{
	if (map()->matrix[field()->y_p][field()->x_p + 1] != '1'
	&& map()->matrix[field()->y_p][field()->x_p + 1] != 'E')
	{
		if (map()->matrix[field()->y_p][field()->x_p + 1] == 'C')
		{
			map()->matrix[field()->y_p][field()->x_p + 1] = '0';
			field()->collect--;
		}
		field()->x_p++;
		image_to_window(img()->floor, field()->x_p - 1, field()->y_p);
		image_to_window(img()->player, field()->x_p, field()->y_p);
		ft_printf("Moves: %d\n", field()->moves++);
	}
}

void	move_left(void)
{
	if (map()->matrix[field()->y_p][field()->x_p - 1] != '1'
	&& map()->matrix[field()->y_p][field()->x_p - 1] != 'E')
	{
		if (map()->matrix[field()->y_p][field()->x_p - 1] == 'C')
		{
			map()->matrix[field()->y_p][field()->x_p - 1] = '0';
			field()->collect--;
		}
		field()->x_p--;
		image_to_window(img()->floor, field()->x_p + 1, field()->y_p);
		image_to_window(img()->player, field()->x_p, field()->y_p);
		ft_printf("Moves: %d\n", field()->moves++);
	}
}
