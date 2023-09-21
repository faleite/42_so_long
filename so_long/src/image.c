/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 20:21:27 by faaraujo          #+#    #+#             */
/*   Updated: 2023/09/21 21:42:12 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void    get_image(t_img img)
{
    int             width;
	int             height;
    
    img.floor = mlx_xpm_file_to_image(map.mlx_ptr, FLOOR, &width, &height);
    img.wall = mlx_xpm_file_to_image(map.mlx_ptr, WALL, &width, &height);
}

void    put_image(t_img img)
{
    t_map           map;
	mlx_put_image_to_window(map.mlx_ptr, map.win_ptr, img.floor, field()->x_player * PX, field()->y_player * PX);
}