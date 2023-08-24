/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 18:54:33 by faaraujo          #+#    #+#             */
/*   Updated: 2023/08/24 21:45:37 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	check_type(char *str)
{
	int		len;
	int		result;
	char	*map;

	len = ft_strlen(str);
	if (len <= 4)
		return (1);
	map = ft_strchr(str, '.');
	result = (ft_strcmp(map, ".ber"));
	if (result)
		err_case("Error\nTeste");
	return (result);
}
