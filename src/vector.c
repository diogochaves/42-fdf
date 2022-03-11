/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchaves- <dchaves-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 00:28:24 by dchaves-          #+#    #+#             */
/*   Updated: 2022/03/11 19:08:17 by dchaves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	vec3_rotate_x(t_vec3 *v, float angle)
{
	t_vec3 vector;

	vector.y = v->y * cos(angle) - v->z * sin(angle);
	vector.z = v->y * sin(angle) + v->z * cos(angle);
	v->y = vector.y;
	v->z = vector.z;
}

void	vec3_rotate_y(t_vec3 *v, float angle)
{
	t_vec3 vector;

	vector.x = v->x * cos(angle) + v->z * sin(angle);
	vector.z = -v->x * sin(angle) + v->z * cos(angle);
	v->x = vector.x;
	v->z = vector.z;
}

void	vec3_rotate_z(t_vec3 *v, float angle)
{
	t_vec3 vector;

	vector.x = v->x * cos(angle) - v->y * sin(angle);
	vector.y = v->x * sin(angle) + v->y * cos(angle);
	v->x = vector.x;
	v->y = vector.y;
}
