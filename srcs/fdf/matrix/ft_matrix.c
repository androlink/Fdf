/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 22:46:59 by gcros             #+#    #+#             */
/*   Updated: 2024/02/20 03:50:05 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>
#include <stdio.h>

/*************************************************************************************
t_mat4	get_rot_mat(t_vec3 *rot_vec)
{
	t_mat4	rot_mat;

	ft_bzero(&rot_mat, sizeof(t_mat4));
	rot_mat.mat[0][0] = cos(rot_vec->z) * cos(rot_vec->y);
	rot_mat.mat[0][1] = sin(rot_vec->z) * cos(rot_vec->y);
	rot_mat.mat[0][2] = -sin(rot_vec->y);
	rot_mat.mat[1][0] = sin(rot_vec->z) * sin(rot_vec->y) * \
	sin(rot_vec->x) - sin(rot_vec->z) * cos(rot_vec->x);
	rot_mat.mat[1][1] = sin(rot_vec->z) * sin(rot_vec->y) * \
	sin(rot_vec->x) - cos(rot_vec->z) * cos(rot_vec->x);
	rot_mat.mat[1][2] = cos(rot_vec->y) * sin(rot_vec->x);
	rot_mat.mat[2][0] = cos(rot_vec->z) * sin(rot_vec->y) * \
	cos(rot_vec->x) - sin(rot_vec->z) * sin(rot_vec->x);
	rot_mat.mat[2][1] = sin(rot_vec->z) * sin(rot_vec->y) * \
	cos(rot_vec->x) - cos(rot_vec->z) * sin(rot_vec->x);
	rot_mat.mat[2][2] = cos(rot_vec->y) * cos(rot_vec->x);
	return (rot_mat);
}*/

t_mat4	get_rot_mat(t_vec3 *rot_vec)
{
	t_mat4	rot_mat;

	ft_bzero(&rot_mat, sizeof(t_mat4));
	rot_mat.mat[0][0] = cos(rot_vec->z) * cos(rot_vec->y);
	rot_mat.mat[0][1] = cos(rot_vec->z) * sin(rot_vec->y) * \
	sin(rot_vec->x) - sin(rot_vec->z) * cos(rot_vec->x);
	rot_mat.mat[0][2] = cos(rot_vec->z) * sin(rot_vec->y) * \
	cos(rot_vec->x) + sin(rot_vec->z) * sin(rot_vec->x);
	rot_mat.mat[1][0] = sin(rot_vec->z) * cos(rot_vec->y);
	rot_mat.mat[1][1] = sin(rot_vec->z) * sin(rot_vec->y) * \
	sin(rot_vec->x) + cos(rot_vec->z) * cos(rot_vec->x);
	rot_mat.mat[1][2] = sin(rot_vec->z) * sin(rot_vec->y) * \
	cos(rot_vec->x) - cos(rot_vec->z) * sin(rot_vec->x);
	rot_mat.mat[2][0] = -sin(rot_vec->y);
	rot_mat.mat[2][1] = cos(rot_vec->y) * sin(rot_vec->x);
	rot_mat.mat[2][2] = cos(rot_vec->y) * cos(rot_vec->x);
	return (rot_mat);
}

t_mat4	get_trans_mat(t_vec3 *trans_vec)
{
	t_mat4	trans_mat;

	printf("trans : %f, %f, %f\n", trans_vec->x, trans_vec->y, trans_vec->z);
	ft_bzero(&trans_mat, sizeof(t_mat4));
	trans_mat.mat[0][0] = 1;
	trans_mat.mat[1][1] = 1;
	trans_mat.mat[2][2] = 1;
	trans_mat.mat[3][3] = 1;
	trans_mat.mat[0][3] = trans_vec->x;
	trans_mat.mat[1][3] = trans_vec->y;
	trans_mat.mat[2][3] = trans_vec->z;
	return (trans_mat);
}

t_mat4	get_scale_mat(t_vec3 *scale_vec)
{
	t_mat4	scale_mat;

	ft_bzero(&scale_mat, sizeof(t_mat4));
	scale_mat.mat[0][0] = scale_vec->x;
	scale_mat.mat[1][1] = scale_vec->y;
	scale_mat.mat[2][2] = scale_vec->z;
	scale_mat.mat[3][3] = 1;
	return (scale_mat);
}

t_mat4	get_ident_mat(void)
{
	t_mat4	ident_mat;

	ft_bzero(&ident_mat, sizeof(t_mat4));
	ident_mat.mat[0][0] = 1;
	ident_mat.mat[1][1] = 1;
	ident_mat.mat[2][2] = 1;
	ident_mat.mat[3][3] = 1;
	return (ident_mat);
}

t_mat4	get_model_mat(t_projection *proj)
{
	t_mat4	rot_mat;
	t_mat4	trans_mat;
	t_mat4	scale_mat;
	t_mat4	model_mat;

	rot_mat = get_rot_mat(&proj->rot_vec);
	trans_mat = get_trans_mat(&proj->trans_vec);
	scale_mat = get_scale_mat(&proj->scale_vec);
	model_mat = get_ident_mat();
	model_mat = ft_mat4_mul(model_mat, trans_mat);
	model_mat = ft_mat4_mul(model_mat, rot_mat);
	model_mat = ft_mat4_mul(model_mat, scale_mat);
	return (model_mat);
}
