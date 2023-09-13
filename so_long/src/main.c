/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 20:34:35 by faaraujo          #+#    #+#             */
/*   Updated: 2023/09/13 22:06:44 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/* Not use yet */
void	init_data(t_data **buff)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		exit(EXIT_FAILURE);
	data->matrix = NULL;
	data->mlx_ptr = NULL;
	data->win_ptr = NULL;
	*buff = data;
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
		free(map[i++]);
	free(map);
	ft_printf("\nIT'S FREE!\n\n");
}

void	init_structs(void)
{
	t_data	*data;

	init_data(&data);
}

t_data	*data(void)
{
	static t_data	d;

	return (&d);
}

/* 	if (check_type(argv[1]) == 0) */
/*		build_window(); */
int	main(int argc, char *argv[])
{
	if (argc != 2)
		err_case("Error\nUse ./prog file.ber\n");
	check_type(argv[1]);
	data()->matrix = copy_map(argv[1]);
	check_map(data());
	free_map(data()->matrix);
	return (0);
}
