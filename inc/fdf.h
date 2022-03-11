/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchaves- <dchaves-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 21:11:03 by dchaves-          #+#    #+#             */
/*   Updated: 2022/03/11 01:20:21 by dchaves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h> // Malloc, Free, Exit
# include <unistd.h> // Read, Write, Close
# include <fcntl.h> // Open
# include <math.h> // Math
# include <X11/X.h> // "KeyPress", "DestroyNotify", "NoEventMask"
# include <X11/keysym.h> // "XK_Escape", "XK_Tab"
# include <mlx.h> // MiniLibx
# include "../lib/libft/inc/libft.h" // Libft + GNL
# include "minilibx.h"

/* NOT ALLOWED */
# include <stdio.h> //printf

typedef struct s_vec3
{
	float	x;
	float	y;
	float	z;
} t_vec3;

typedef struct s_map
{
	int		columns;
	int		rows;
	t_vec3	**vectors;
} t_map;

typedef struct s_fdf
{
	t_data	*data;
	t_map	*map;
} t_fdf;


t_map	*map_init(int argc, char **argv);
void	map_free(t_map *map);
t_data	*data_init();
void	data_img_init(t_fdf *fdf);
int		create_image(t_fdf *fdf);
void	plot_map(t_fdf *fdf);
int		close_window(t_fdf *fdf);
int		handle_keypress(int keysym, t_fdf *fdf);
void	img_pix_put(t_img *img, int x, int y, int color);
int		render_rect(t_img *img, t_rect rect);
void	render_background(t_img *img, int color);
void	plot_line(t_img *img, t_vec3 vec0, t_vec3 vec1, int color);
void	project(t_vec3 *vec, int zoom);
void	rotate_x(t_fdf *fdf);
t_vec3	vec3_rotate_x(t_vec3 v, float angle);

#endif
