/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 18:13:08 by faaraujo          #+#    #+#             */
/*   Updated: 2023/09/27 20:35:21 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/* images */
# define SIZE 32
# define WALL "./images/wall.xpm"
# define FLOOR "./images/floor.xpm"
# define EXIT "./images/exit.xpm"
# define CRYSTAL "./images/crystal.xpm"
# define P_UP "./images/p_up.xpm"
# define P_DOWN "./images/p_down.xpm"
# define P_LEFT "./images/p_left.xpm"
# define P_RIGHT "./images/p_right.xpm"

/* keycode */
# define W 119
# define A 97
# define S 115
# define D 100
# define UP 65362
# define DOWN 65364
# define LEFT 65361
# define RIGHT 65363
# define ESC 65307

/* includes */
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
	int		x;
	int		y;
	int		size_x;
	int		size_y;
}	t_map;

typedef struct s_field
{
	int		out;
	int		collect;
	int		collect_2;
	int		diamond;
	int		exit_2;
	int		player;
	int		x_p;
	int		y_p;
	int		moves;
}	t_field;

typedef struct s_img
{
	void	*wall;
	void	*floor;
	void	*exit;
	void	*crystal;
	void	*p_up;
	void	*p_down;
	void	*p_left;
	void	*p_right;
}	t_img;

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

void	validate_map(int argc, char *argv);
int		playable_map(void);
int		check_fill(char **matrix, int x, int y);
char	**copy_map(char *file);
void	heigth_map(void);
void	find_player(void);
void	flood_fill(char **matrix, int x, int y);

/* structs init */
t_map	*map(void);
t_img	*img(void);
t_field	*field(void);

/* window */
int		destroy_window(void);
int		destroy_image(void);
int		build_window(void);
void	*file_to_image(char *path);
void	image_to_window(void *image, int x, int y);
void	get_image(void);
void	put_image(void);
void	image_error(void);
void	display(void);

/* game */
void	moves(int keycode);
void	move_up(void);
void	move_down(void);
void	move_left(void);
void	move_right(void);

#endif /* SO_LONG_H */
