/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 18:54:33 by faaraujo          #+#    #+#             */
/*   Updated: 2023/09/17 14:40:36 by faaraujo         ###   ########.fr       */
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
	if (data()->x_len == 0)
		data()->x_len = len;
	if (line[0] == '1' && line[len - 1] == '1')
		return (0);
	return (1);
}

int	check_wall(char *line)
{
	int	i;

	i = 0;
	while (i < data()->x_len)
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
	while (data()->matrix && data()->matrix[i])
		i++;
	if (data()->y_len == 0)
		data()->y_len = i;
}

int	check_len(char *line)
{
	int	len;

	len = ft_strlen(line);
	len -= (line[len - 1] == '\n');
	if (len != data()->x_len)
		return (1);
	return (0);
}
