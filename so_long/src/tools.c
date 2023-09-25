/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 21:21:00 by faaraujo          #+#    #+#             */
/*   Updated: 2023/09/25 18:09:20 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_map	*map(void)
{
	static t_map	d;

	return (&d);
}

t_field	*field(void)
{
	static t_field	f;

	return (&f);
}

t_img	*img(void)
{
	static t_img	i;

	return (&i);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
	{
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
