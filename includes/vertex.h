/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertex.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 02:46:37 by gcros             #+#    #+#             */
/*   Updated: 2024/02/11 01:07:48 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VERTEX_H
# define VERTEX_H

# include "vector.h"

typedef struct s_mat3
{
	double	mat[3][3];
}	t_mat3;

typedef struct s_mat4
{
	double	mat[4][4];
}	t_mat4;

typedef struct s_vec3
{
	double	x;
	double	y;
	double	z;
}	t_vec3;

typedef struct s_vec2
{
	double	x;
	double	y;
}	t_vec2;

typedef struct s_point
{
	t_vec3			world_point;
	unsigned char	color[4];
}	t_point;

typedef struct s_face
{
	t_vector	points;
}	t_face;

#endif