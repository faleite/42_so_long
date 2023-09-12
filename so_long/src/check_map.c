/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 18:54:33 by faaraujo          #+#    #+#             */
/*   Updated: 2023/09/12 21:26:55 by faaraujo         ###   ########.fr       */
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

int	check_wall(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == '1' || line[i] == '\n')
			i++;
		else
			return (1);
	}
	return (0);
}

int	check_side_wall(char *line)
{
	int	len;

	len = ft_strlen(line);

	if (line[0] == '1' && line[len - 1] == '1')
		return (0);
	return (1);
}

// int	check_map(char *file)
// {
// 	int		i;
// 	int		fd;
// 	char	*line;

// 	fd = open(file, O_RDONLY);
// 	i = 0;
// 	while (1)
// 	{
// 		line = get_next_line(fd);
// 		if (check_wall(line) == 1)
// 			return (1);
// 		//ft_printf("Wall ok\n");
// 		ft_printf("%s", line);
// 		if (!line)
// 			break ;
// 		free(line);
// 		i++;
// 	}
// 	close(fd);
// 	return (0);
// }

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	//printf("%d\n", check_side_wall(line));
// 	ft_printf("%d", check_map("map.ber"));
// 	return (0);
// }
