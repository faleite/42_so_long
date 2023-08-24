/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 21:21:00 by faaraujo          #+#    #+#             */
/*   Updated: 2023/08/24 21:37:40 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/**
 * @brief The error case function, returns an error message, frees the data
 * and closes the file descriptors
 * @param msg The error message
 * @param data The data to be freed
*/
// void	err_case(char *msg, t_data *data)
void	err_case(char *msg)
{
	perror(msg);
	// free(data);
	// if (data->in_fd > -1)
	// 	close(data->in_fd);
	// if (data->out_fd > -1)
	// 	close(data->out_fd);
	exit(EXIT_FAILURE);
}

/**
 * @brief The function prints the error message
 * for the wrong number of arguments
 * More message you can added:
 * ft_putstr_fd("Error: wrong number of arguments\n", 1);
*/
void	using(void)
{
	ft_putstr_fd("Error\nUse ./prog file.ber\n", 2);
	exit(EXIT_FAILURE);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t			i;
	unsigned char	*cs1;
	unsigned char	*cs2;

	cs1 = (unsigned char *)s1;
	cs2 = (unsigned char *)s2;
	i = 0;
	while ((cs1[i] || cs2[i]))
	{
		if (cs1[i] != cs2[i])
			return (cs1[i] - cs2[i]);
		i++;
	}
	return (0);
}
