/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 20:34:35 by faaraujo          #+#    #+#             */
/*   Updated: 2023/08/22 21:28:15 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long.h"

void	init_data(t_data **buff)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		exit(EXIT_FAILURE);
	data->mlx_ptr = NULL;
	data->win_ptr = NULL;
	*buff = data;
}

int	main(void)
{
	t_data	*data;

	init_data(&data);

	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		return (1);
	data->win_ptr = mlx_new_window(data->mlx_ptr, 600, 400, "My first Window");
	if (!data->win_ptr)
		return (1);
	mlx_loop(data->mlx_ptr);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	return (0);
}
