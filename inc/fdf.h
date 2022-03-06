/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchaves- <dchaves-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 21:11:03 by dchaves-          #+#    #+#             */
/*   Updated: 2022/03/06 20:20:29 by dchaves-         ###   ########.fr       */
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
	int	x;
	int	y;
	int	z;
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


int		close_window(t_fdf *fdf);
int		handle_keypress(int keysym, t_fdf *fdf);
void	img_pix_put(t_img *img, int x, int y, int color);
int		render_rect(t_img *img, t_rect rect);
void	render_background(t_img *img, int color);
void	plot_line(t_img *img, int x0, int y0, int x1, int y1, int color);
t_map	*read_map(int argc, char **argv);
void	print_map(t_map *map);
void	free_map(t_map *map);

#endif
