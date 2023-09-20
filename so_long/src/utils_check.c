/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 18:54:33 by faaraujo          #+#    #+#             */
/*   Updated: 2023/09/20 18:59:41 by faaraujo         ###   ########.fr       */
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
	if (!map)
		err_case("Error\nThe map must be a valid format: file.ber\n");
	result = (ft_strncmp(map, ".ber", len));
	if (result)
		err_case("Error\nThe map must be a valid format: file.ber\n");
	return (result);
}

int	check_side_wall(char *line)
{
	int	len;

	len = ft_strlen(line);
	len -= (line[len - 1] == '\n');
	if (len >= 60)
		err_case("Error\nThe map is not the ideal size for the screen\n");
	if (map()->size_x == 0)
		map()->size_x = len;
	if (line[0] == '1' && line[len - 1] == '1')
		return (0);
	return (1);
}

int	check_wall(char *line)
{
	int	i;

	i = 0;
	while (i < map()->size_x)
	{
		if (line[i] == '1')
			i++;
		else
			return (1);
	}
	return (0);
}

void	heigth_map(void)
{
	int	i;

	i = 0;
	while (map()->matrix && map()->matrix[i])
		i++;
	if (i > 32)
		err_case("Error\nThe map is not the ideal size for the screen\n");
	if (map()->size_y == 0)
		map()->size_y = i;
}

int	check_len(char *line)
{
	int	len;

	len = ft_strlen(line);
	len -= (line[len - 1] == '\n');
	if (len != map()->size_x)
		return (1);
	return (0);
}
