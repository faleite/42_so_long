/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 20:34:35 by faaraujo          #+#    #+#             */
/*   Updated: 2023/08/25 22:11:45 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	get_map(void)
{
	char	*line;
	int		fd;
	int		i;

	fd = open("src/map.ber", O_RDONLY);
	i = 1;
	ft_printf("\nGET MAP:\n\n");
	while (i <= 5)
	{
		line = get_next_line(fd);
		ft_printf("%s", line);
		free(line);
		i++;
	}
	ft_printf("\n");
	close(fd);
	return (0);
}

int	main(int argc, char *argv[])
{
	get_map();
	if (argc != 2)
		err_case("Error\nUse ./prog file.ber\n");
	if (check_type(argv[1]) == 0)
		build_window();
	return (0);
}
