/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 18:37:37 by faaraujo          #+#    #+#             */
/*   Updated: 2023/09/27 20:41:30 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	display(void)
{
	char	*str1;
	char	*str2;

	str1 = ft_itoa(field()->moves);
	str2 = ft_itoa(field()->diamond);
	image_to_window(img()->wall, 0, 0);
	image_to_window(img()->wall, 1, 0);
	image_to_window(img()->wall, 2, 0);
	mlx_string_put(map()->mlx_ptr, map()->win_ptr, 10, 12, 0x00FF00, "Moves: ");
	mlx_string_put(map()->mlx_ptr, map()->win_ptr, 67, 12, 0x00FF00, str1);
	mlx_string_put(map()->mlx_ptr, map()->win_ptr, 10, 26, 0x00FF00, "Diamonds:  ");
	mlx_string_put(map()->mlx_ptr, map()->win_ptr, 67, 26, 0x00FF00, str2);
	free(str1);
	free(str2);
}
