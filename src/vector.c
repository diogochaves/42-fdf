/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchaves- <dchaves-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 00:28:24 by dchaves-          #+#    #+#             */
/*   Updated: 2022/03/11 02:02:05 by dchaves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

t_vec3	vec3_rotate_x(t_vec3 v, float angle)
{
	t_vec3	rotated_vector;
	static int	count = 0;
	count++;

	rotated_vector.x = v.x;
	rotated_vector.y = v.y; //v.y * cos(angle) - v.z * sin(angle),
	rotated_vector.z = v.z + angle;//v.y * sin(angle) + v.z * cos(angle);

	printf("cos(%f) = %f\n", angle, cos(angle));
	printf("sin(%f) = %f\n", angle, sin(angle));
	printf("COUNT(%d)", count);

	return (rotated_vector);
}

t_vec3	vec3_translate(t_vec3 v, float x, float y)
{
	t_vec3	translated_vector;

	translated_vector.x = v.x + x;
	translated_vector.y = v.y + y;
	translated_vector.z = v.z;
	return(translated_vector);
}
