/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_calc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 01:13:16 by gcros             #+#    #+#             */
/*   Updated: 2024/02/27 23:41:32 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_mat4	fdf_mat4_mul(t_mat4 m1, t_mat4 m2)
{
	int		i;
	int		j;
	t_mat4	m3;

	ft_bzero(&m3, sizeof(t_mat4));
	j = 0;
	while (j < 4)
	{
		i = 0;
		while (i < 4)
		{
			m3.mat[j][i] = m1.mat[j][0] * m2.mat[0][i];
			m3.mat[j][i] += m1.mat[j][1] * m2.mat[1][i];
			m3.mat[j][i] += m1.mat[j][2] * m2.mat[2][i];
			m3.mat[j][i] += m1.mat[j][3] * m2.mat[3][i];
			i++;
		}
		j++;
	}
	return (m3);
}

t_vec3	fdf_mat4_x_vec3(t_mat4 m1, t_vec3 v1)
{
	t_vec3	v2;
	float	w;

	v2 = (t_vec3){0, 0, 0};
	v2.x = m1.mat[0][0] * v1.x + m1.mat[0][1] * v1.y + m1.mat[0][2] \
	* v1.z + m1.mat[0][3] * 1.;
	v2.y = m1.mat[1][0] * v1.x + m1.mat[1][1] * v1.y + m1.mat[1][2] \
	* v1.z + m1.mat[1][3] * 1.;
	v2.z = m1.mat[2][0] * v1.x + m1.mat[2][1] * v1.y + m1.mat[2][2] \
	* v1.z + m1.mat[2][3] * 1.;
	w = m1.mat[3][0] * v1.x + m1.mat[3][1] * v1.y + m1.mat[3][2] \
	* v1.z + m1.mat[3][3] * 1.;
	if (w != 0.0f)
	{
		v2.x /= w;
		v2.y /= w;
		v2.z /= w;
	}
	return (v2);
}
