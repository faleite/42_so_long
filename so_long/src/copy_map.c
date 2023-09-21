/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 18:07:32 by faaraujo          #+#    #+#             */
/*   Updated: 2023/09/21 17:07:15 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	count_line(char *file)
{
	int		len;
	int		read_line;
	int		fd;
	char	c;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		err_case("Error\nFile Descriptor (File not exist)\n");
	len = 1;
	while (1)
	{
		read_line = read(fd, &c, 1);
		if (read_line == 0)
			break ;
		if (read_line < 0)
			err_case("Error\nNot read (Empty file)\n");
		if (c == '\n')
			len++;
	}
	close(fd);
	return (len);
}

char	**copy_map(char *file)
{
	int		i;
	int		fd;
	char	*line;
	char	**matrix;

	matrix = malloc(sizeof(char *) * (count_line(file) + 1));
	fd = open(file, O_RDONLY);
	if (fd == -1)
		err_case("Error\nFile Descriptor (File not exist)\n");
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		matrix[i] = line;
		if (!line)
			break ;
		i++;
	}
	close(fd);
	return (matrix);
}
