/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchaves- <dchaves-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 00:28:24 by dchaves-          #+#    #+#             */
/*   Updated: 2022/03/14 18:42:48 by dchaves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	rotate_x(t_vec *v, float angle)
{
	t_vec	vector;

	vector.y = v->y * cos(angle) - v->z * sin(angle);
	vector.z = v->y * sin(angle) + v->z * cos(angle);
	v->y = vector.y;
	v->z = vector.z;
}

void	rotate_y(t_vec *v, float angle)
{
	t_vec	vector;

	vector.x = v->x * cos(angle) + v->z * sin(angle);
	vector.z = -v->x * sin(angle) + v->z * cos(angle);
	v->x = vector.x;
	v->z = vector.z;
}

void	rotate_z(t_vec *v, float angle)
{
	t_vec	vector;

	vector.x = v->x * cos(angle) - v->y * sin(angle);
	vector.y = v->x * sin(angle) + v->y * cos(angle);
	v->x = vector.x;
	v->y = vector.y;
}

t_vec	**vectors_malloc(t_map *map)
{
	t_vec	**vectors;
	int		y;
	int		x;

	vectors = malloc(map->rows * sizeof(t_vec *));
	if (!vectors)
		return (NULL);
	y = 0;
	while (y < map->rows)
	{
		x = 0;
		vectors[y] = malloc(map->columns * sizeof(t_vec));
		while (x < map->columns)
		{
			vectors[y][x].x = x - map->columns / 2;
			vectors[y][x].y = y - map->rows / 2;
			vectors[y][x].z = 0;
			vectors[y][x].color = C_FRONT;
			x++;
		}
		y++;
	}
	return (vectors);
}
