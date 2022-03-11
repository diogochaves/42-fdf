/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchaves- <dchaves-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 21:42:03 by dchaves-          #+#    #+#             */
/*   Updated: 2022/03/11 01:25:38 by dchaves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	rotate_x(t_fdf *fdf)
{
	int	row;
	int	col;

	row = 0;
	col = 0;

	while(row < fdf->map->rows)
	{
		while (col < fdf->map->columns)
		{
			fdf->map->vectors[row][col] = vec3_rotate_x(fdf->map->vectors[row][col], 2);
			col++;
		}
		col = 0;
		row++;
	}	
}
