/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 20:34:35 by faaraujo          #+#    #+#             */
/*   Updated: 2023/09/22 20:41:45 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	validate_map(int argc, char *argv)
{
	if (argc != 2)
		err_case("Error\nUse ./prog file.ber\n");
	check_type(argv);
	map()->matrix = copy_map(argv);
	check_map();
	if (playable_map())
		err_case("Error\nThe map is not valid\n");
	free_map(map()->matrix);
	map()->matrix = copy_map(argv);
}

/* 	if (check_type(argv[1]) == 0) */
/*		build_window(); */
int	main(int argc, char *argv[])
{
	validate_map(argc, argv[1]);
	build_window();
	free_map(map()->matrix);
	return (0);
}
