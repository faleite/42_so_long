/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 20:34:35 by faaraujo          #+#    #+#             */
/*   Updated: 2023/09/18 21:44:36 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_map	*map(void)
{
	static t_map	d;

	return (&d);
}

t_field	*field(void)
{
	static t_field	f;

	return (&f);
}

/* 	if (check_type(argv[1]) == 0) */
/*		build_window(); */
int	main(int argc, char *argv[])
{
	if (argc != 2)
		err_case("Error\nUse ./prog file.ber\n");
	check_type(argv[1]);
	map()->matrix = copy_map(argv[1]);
	map()->cp_map = copy_map(argv[1]);
	check_map();
	validate_map();
	free_map(map()->matrix);
	return (0);
}
