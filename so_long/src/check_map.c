/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 18:54:33 by faaraujo          #+#    #+#             */
/*   Updated: 2023/08/31 19:29:26 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_type(char *str)
{
	int		len;
	int		result;
	char	*map;

	len = ft_strlen(str);
	if (len <= 4)
		err_case("Error\nThe map must be a valid format: file.ber\n");
	map = ft_strchr(str, '.');
	result = (ft_strncmp(map, ".ber", len));
	if (result)
		err_case("Error\nThe map must be a valid format: file.ber\n");
	return (result);
}

char	**copy_map(char *file)
{
	int		i;
	int		fd;
	char	*line;
	char	**matrix;

	matrix = (char **)malloc(sizeof(matrix));
	fd = open(file, O_RDONLY);
	i = 0;
	ft_printf("\nThis is a Map Matrix\n");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		matrix[i] = (char *)malloc(sizeof(char) * ft_strlen(line));
		ft_strlcpy(matrix[i], line, ft_strlen(line));
		free(line);
		ft_printf("\n%s", matrix[i]);
		i++;
	}
	ft_printf("\n");
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

