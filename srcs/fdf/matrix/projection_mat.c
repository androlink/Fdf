/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection_mat.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 22:44:30 by gcros             #+#    #+#             */
/*   Updated: 2024/02/21 00:20:42 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

t_mat4	get_iso_proj()
{
	t_mat4	mat;

	ft_bzero(&mat, sizeof(t_mat4));
	mat.mat[0][0] = 1;
	mat.mat[1][1] = 1;
	mat.mat[2][2] = -1;
	mat.mat[3][3] = 1;
	return (mat);
}

t_mat4	get_pers_proj()
{
	t_mat4	mat;
	float	far;
	float	near;

	far = 100.f;
	near = .1f;
	ft_bzero(&mat, sizeof(t_mat4));
	mat.mat[0][0] = 1 / tan(120 / 2 * 3.14 / 180);
	mat.mat[1][1] = 1 / tan(90 / 2 * 3.14 / 180);
	mat.mat[2][2] = -(far + near) / (far - near);
	mat.mat[3][2] = -2 * far * near / (far - near);
	mat.mat[2][3] = -1;
	return (mat);
}