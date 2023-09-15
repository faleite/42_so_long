/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 18:13:08 by faaraujo          #+#    #+#             */
/*   Updated: 2023/09/15 22:03:08 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"
# include "../get_next_line/get_next_line.h"
# include "../mlx_linux/mlx.h"
# include <errno.h> /**/
# include <fcntl.h> /**/
# include <stdio.h>
# include <stdlib.h>
# include <X11/X.h>
# include <X11/keysym.h>

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	char	**matrix;
	int		length;
	int		height;
}	t_data;

typedef struct s_field
{
	int		out;
	int		collect;
	int		player;
}	t_field;


/*  error  */
void	err_case(char *msg);
void	free_map(char **map);

/* checks */
int		check_type(char *str);
int		check_wall(char *line);
int		check_side_wall(char *line);
int		check_map(void);
int		check_len(char *line);
int		check_field(void);
char	**copy_map(char *file);
void	heigth_map(void);
void	count_field(void);


/* structs */
t_data	*data(void);
t_field	*field(void);

/* window */
int		destroy_window(t_data *data);
int		on_keypress(int keycode, t_data *data);
int		build_window(void);

#endif /* SO_LONG_H */
