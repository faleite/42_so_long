/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 21:21:00 by faaraujo          #+#    #+#             */
/*   Updated: 2023/09/19 21:43:55 by faaraujo         ###   ########.fr       */
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

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
	{
		ft_printf("%s", map[i]);
		free(map[i++]);
	}
	ft_printf("\n\n");
	free(map);
}

void	err_case(char *msg)
{
	ft_putstr_fd(msg, 2);
	if (map()->matrix)
		free_map(map()->matrix);
	exit(EXIT_FAILURE);
}
