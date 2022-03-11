/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchaves- <dchaves-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 13:08:01 by dchaves-          #+#    #+#             */
/*   Updated: 2022/03/11 19:29:26 by dchaves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

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

typedef struct s_rect
{
	int	x;
	int	y;
	int	width;
	int	height;
	int	color;
}	t_rect;

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

typedef struct	s_data
{
	float	scale;
	float	x_move;	
	float	y_move;
	float	x_angle;	
	float	y_angle;
	float	z_angle;	
} t_data;

typedef struct s_fdf
{
	t_display	*display;
	t_map		*map;
	t_data		*data;
} t_fdf;

#endif
