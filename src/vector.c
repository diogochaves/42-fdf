/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchaves- <dchaves-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 00:28:24 by dchaves-          #+#    #+#             */
/*   Updated: 2022/03/11 01:25:23 by dchaves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

t_vec3	vec3_rotate_x(t_vec3 v, float angle)
{
	t_vec3	rotated_vector = {
		.x = v.x,
		.y = v.y, //v.y * cos(angle) - v.z * sin(angle),
		.z = v.z * angle //v.y * sin(angle) + v.z * cos(angle)
	};
	return (rotated_vector);
}
