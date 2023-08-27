/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 20:34:35 by faaraujo          #+#    #+#             */
/*   Updated: 2023/08/27 21:04:39 by faaraujo         ###   ########.fr       */
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
	// data->mlx_ptr = NULL;
	// data->win_ptr = NULL;
	*buff = data;
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
		free(map[i++]);
	free(map);
	ft_printf("\n\nIT'S FREE!\n\n");
}

int	main(int argc, char *argv[])
{
	t_data	data;

	if (argc != 2)
		err_case("Error\nUse ./prog file.ber\n");
	data.matrix = copy_map(argv[1]);
	free_map(data.matrix);
	if (check_type(argv[1]) == 0)
		build_window();
	return (0);
}
