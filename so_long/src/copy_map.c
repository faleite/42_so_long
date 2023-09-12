/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 18:07:32 by faaraujo          #+#    #+#             */
/*   Updated: 2023/09/12 21:40:57 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	**copy_map(char *file)
{
	int		i;
	int		fd;
	char	*line;
	char	**matrix;

	matrix = (char **)malloc(sizeof(matrix));
	fd = open(file, O_RDONLY);
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		matrix[i] = (char *)malloc(sizeof(char) * ft_strlen(line));
		ft_strlcpy(matrix[i], line, ft_strlen(line));
		free(line);
		if (check_side_wall(matrix[0]) == 1)
			err_case("Error\nThe map should only have a wall around it\n");
		i++;
	}
	matrix[i] = NULL;
	close(fd);
	return (matrix);
}

/* Algo errado */
// void	copy_matrix(t_data *data)
// {
// 	int		i;

// 	data->cpy_matrix = (char **)malloc(sizeof(data->matrix) + 1);
// 	i = 0;
// 	while (i != 6)
// 	{
// 		data->cpy_matrix[i] = ft_strdup(data->matrix[i]);
// 		ft_printf("%s\n", data->cpy_matrix[i]);
// 		i++;
// 	}
// 	data->cpy_matrix[i] = NULL;
// }
