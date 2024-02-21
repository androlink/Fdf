/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection_mat.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 22:44:30 by gcros             #+#    #+#             */
/*   Updated: 2024/02/21 19:34:29 by gcros            ###   ########.fr       */
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
	const float	far = 1000.;
	const float	near = .1;
	const float	fov = 120.;
	const float	ratio = (float)IMAGE_HEIGHT / (float)IMAGE_WIDTH;
	const float fov_rad = 1. / tan(fov * .5 / 180. * FDF_PI);
	const float z_far_z_near = far / (far - near);

	ft_bzero(&mat, sizeof(t_mat4));
	mat.mat[0][0] = ratio * fov_rad;
	mat.mat[1][1] = fov_rad;
	mat.mat[2][2] = z_far_z_near;
	mat.mat[3][2] = (-z_far_z_near) * near;
	mat.mat[2][3] = 1.0;
	mat.mat[3][3] = 1;
	return (mat);
}