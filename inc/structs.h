/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchaves- <dchaves-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 13:08:01 by dchaves-          #+#    #+#             */
/*   Updated: 2022/03/15 12:50:04 by dchaves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_vec
{
	float	x;
	float	y;
	float	z;
	int		color;
}	t_vec;

typedef struct s_rect
{
	int	x;
	int	y;
	int	width;
	int	height;
	int	color;
}	t_rect;

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bits_per_pixel;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_display
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
}	t_display;

typedef struct s_map
{
	t_vec	**vectors;
	int		columns;
	int		rows;
	int		z_max;
	int		z_min;
}	t_map;

typedef struct s_data
{
	int		projection;
	float	scale;
	float	z_scale;
	float	x_move;
	float	y_move;
	float	x_angle;
	float	y_angle;
	float	z_angle;
}	t_data;

typedef struct s_mouse
{
	int	left_button;
	int	right_button;
	int	third_button;
	int	x;
	int	y;

}	t_mouse;

typedef struct s_fdf
{
	t_display	*display;
	t_map		*map;
	t_data		*data;
	t_mouse		*mouse;
	int			mod_key;
	int			menu;
	int			animation;
}	t_fdf;

#endif
