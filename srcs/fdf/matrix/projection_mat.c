/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection_mat.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 22:44:30 by gcros             #+#    #+#             */
/*   Updated: 2024/02/26 23:11:45 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>
#include <stdio.h>

t_mat4	get_iso_proj(void)
{
	t_mat4		mat;
	const float	far = 1000.;
	const float	near = .1;

	ft_bzero(&mat, sizeof(t_mat4));
	mat.mat[0][0] = 1. / IMAGE_WIDTH;
	mat.mat[1][1] = 1. / IMAGE_HEIGHT;
	mat.mat[2][2] = -2. / (far - near);
	mat.mat[2][3] = - (far + near) / (far - near);
	mat.mat[3][3] = 1.;
	return (mat);
}

t_mat4	get_pers_proj(void)
{
	t_mat4		mat;
	const float	far = 1000.;
	const float	near = .1;
	const float	fov = 90.;
	const float	fov_rad = 1. / tan(fov * .5 / 180. * FDF_PI);

	ft_bzero(&mat, sizeof(t_mat4));
	mat.mat[0][0] = (float)IMAGE_HEIGHT / (float)IMAGE_WIDTH * fov_rad;
	mat.mat[1][1] = fov_rad;
	mat.mat[2][2] = -(far + near) / (far - near);
	mat.mat[2][3] = -2. * (near * far) / (far - near);
	mat.mat[3][2] = -1.;
	mat.mat[3][3] = 0.;
	return (mat);
}
