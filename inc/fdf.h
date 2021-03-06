/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchaves- <dchaves-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 21:11:03 by dchaves-          #+#    #+#             */
/*   Updated: 2022/03/14 20:34:00 by dchaves-         ###   ########.fr       */
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
# include "structs.h"
# include "macros.h"

// Display + Image (mlx)
t_display	*display_init(void);
void		display_img_init(t_fdf *fdf);
int			create_image(t_fdf *fdf);
int			render(t_fdf *fdf);
int			close_window(t_fdf *fdf);

// Map
t_map		*map_init(int argc, char **argv);
void		free_map(t_map *map);
t_vec		**vectors_malloc(t_map *map);
int			get_map_color(char *str);
void		plot_map(t_fdf *fdf);

// Data
t_data		*data_init(t_fdf *fdf);
void		data_reset(t_fdf *fdf);

// Input
int			key_press(int keysym, t_fdf *fdf);
int			key_release(int keysym, t_fdf *fdf);
t_mouse		*mouse_init(void);
int			mouse_press(int button, int x, int y, t_fdf *fdf);
int			mouse_release(int button, int x, int y, t_fdf *fdf);
int			mouse_move(int x, int y, t_fdf *fdf);

// Draw
void		img_pix_put(t_img *img, int x, int y, int color);
int			plot_rectangle(t_img *img, t_rect rect);
void		plot_line(t_img *img, t_vec vec0, t_vec vec1);
void		fill_img(t_img *img, int color);

// Transformation + Perspective
void		transform(t_fdf *fdf, t_vec *vec);
void		project(t_fdf *fdf, t_vec *vec);
void		scale(t_vec *vec, int scale);
void		rotate_x(t_vec *v, float angle);
void		rotate_y(t_vec *v, float angle);
void		rotate_z(t_vec *v, float angle);
void		translate(t_vec *vec, float x_move, float y_move);
void		isometric(float *x, float *y, float z);
void		perspective(t_vec *vec, float w);

// Utils
float		max(float a, float b);
float		min(float a, float b);
int			toggle(int status);

// User interface
void		interface(t_fdf *fdf);
void		interface_txt(t_fdf *fdf);
void		info_menu(t_fdf *fdf);
void		info_menu_txt(t_fdf *fdf);
void		error(int error_code);

// Colors
int			get_color(t_vec current, t_vec start, t_vec end, double percentage);
double		percent(int start, int end, int current);

#endif
