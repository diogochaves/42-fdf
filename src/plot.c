/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plot.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchaves- <dchaves-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 12:40:42 by dchaves-          #+#    #+#             */
/*   Updated: 2022/03/14 19:59:03 by dchaves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static void	plot_map_line(t_fdf *fdf, int row, int col);

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;

	if (x >= 0 && x < WINDOW_WIDTH && y >= 0 && y < WINDOW_HEIGHT)
	{
		pixel = img->addr + (y * img->line_len + x * (img->bits_per_pixel / 8));
		*(int *)pixel = color;
	}
}

void	fill_img(t_img *img, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < WINDOW_HEIGHT)
	{
		j = 0;
		while (j < WINDOW_WIDTH)
		{
			img_pix_put(img, j++, i, color);
		}
		++i;
	}
}

int	plot_rectangle(t_img *img, t_rect rect)
{
	int	i;
	int	j;

	i = rect.y;
	while (i < rect.y + rect.height)
	{
		j = rect.x;
		while (j < rect.x + rect.width)
			img_pix_put(img, j++, i, rect.color);
		++i;
	}
	return (0);
}

void	plot_map(t_fdf *fdf)
{
	int		row;
	int		col;

	row = 0;
	while (row < fdf->map->rows)
	{
		col = 0;
		while (col < fdf->map->columns)
		{
			plot_map_line(fdf, row, col);
			col++;
		}
		row++;
	}
}

static void	plot_map_line(t_fdf *fdf, int row, int col)
{
	t_vec	vec[2];

	vec[0] = fdf->map->vectors[row][col];
	transform(fdf, &vec[0]);
	if (col < fdf->map->columns - 1)
	{
		vec[1] = fdf->map->vectors[row][col + 1];
		transform(fdf, &vec[1]);
		plot_line(&fdf->display->img, vec[0], vec[1]);
	}
	if (row < fdf->map->rows - 1)
	{
		vec[1] = fdf->map->vectors[row + 1][col];
		transform(fdf, &vec[1]);
		plot_line(&fdf->display->img, vec[0], vec[1]);
	}	
}
