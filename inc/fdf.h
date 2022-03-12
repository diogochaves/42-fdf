/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchaves- <dchaves-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 21:11:03 by dchaves-          #+#    #+#             */
/*   Updated: 2022/03/12 00:07:42 by dchaves-         ###   ########.fr       */
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

/* NOT ALLOWED */
# include <stdio.h> //printf


t_display	*display_init();
void		display_img_init(t_fdf *fdf);
int			create_image(t_fdf *fdf);
t_map		*map_init(int argc, char **argv);
void		map_free(t_map *map);
void		plot_map(t_fdf *fdf);
t_data		*data_init(t_fdf *fdf);
void		data_reset(t_fdf *fdf);
int			close_window(t_fdf *fdf);
int			key_press(int keysym, t_fdf *fdf);
t_mouse		*mouse_init(void);
int			mouse_press(int button, int x, int y, t_fdf *fdf);
int			mouse_release(int button, int x, int y, t_fdf *fdf);
int			mouse_move(int x, int y, t_fdf *fdf);
void		img_pix_put(t_img *img, int x, int y, int color);
int			render_rect(t_img *img, t_rect rect);
void		render_background(t_img *img, int color);
void		plot_line(t_img *img, t_vec3 vec0, t_vec3 vec1, int color);
void		project(t_vec3 *vec, int scale);
void		scale(t_vec3 *vec, int scale);
void		translate(t_vec3 *vec, float x_move, float y_move);
void 		isometric(float *x, float *y, float z);
void		vec3_rotate_x(t_vec3 *v, float angle);
void		vec3_rotate_y(t_vec3 *v, float angle);
void		vec3_rotate_z(t_vec3 *v, float angle);
float		max(float a, float b);
float		min(float a, float b);
void		interface(t_fdf *fdf);
void		interface_txt(t_fdf *fdf);

#endif
