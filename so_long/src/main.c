/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 20:34:35 by faaraujo          #+#    #+#             */
/*   Updated: 2023/09/14 19:03:39 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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
	check_map();
	free_map(data()->matrix);
	return (0);
}
