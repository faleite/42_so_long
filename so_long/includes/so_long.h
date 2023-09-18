/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 18:13:08 by faaraujo          #+#    #+#             */
/*   Updated: 2023/09/18 21:45:01 by faaraujo         ###   ########.fr       */
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

typedef struct s_map
{
	void	*mlx_ptr;
	void	*win_ptr;
	char	**matrix;
	char	**cp_map;
	int		x_len;
	int		y_len;
}	t_map;

typedef struct s_field
{
	int		out;
	int		collect;
	int		player;
	int		x_player;
	int		y_player;
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
int		invalid_field(void);
int		check_field(void);
int		count_field(void);
int		find_player(void);
int		validate_map(void);
char	**copy_map(char *file);
void	heigth_map(void);
void	flood_fill(int y, int x, char **matrix);


/* structs */
t_map	*map(void);
t_field	*field(void);

/* window */
int		destroy_window(t_map *map);
int		on_keypress(int keycode, t_map *map);
int		build_window(void);

#endif /* SO_LONG_H */
