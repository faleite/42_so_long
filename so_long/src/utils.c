/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 21:21:00 by faaraujo          #+#    #+#             */
/*   Updated: 2023/09/18 21:09:16 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
	{
		//ft_printf("%s", map[i]);
		free(map[i++]);
	}
	free(map);
}

void	err_case(char *msg)
{
	ft_putstr_fd(msg, 2);
	if (map()->matrix)
		free_map(map()->matrix);
	exit(EXIT_FAILURE);
}
