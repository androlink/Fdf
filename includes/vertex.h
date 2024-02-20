/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertex.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 02:46:37 by gcros             #+#    #+#             */
/*   Updated: 2024/02/20 20:39:55 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VERTEX_H
# define VERTEX_H

# include "vector.h"

typedef struct s_mat3
{
	float	mat[3][3];
}	t_mat3;

typedef struct s_mat4
{
	float	mat[4][4];
}	t_mat4;

typedef struct s_vec3
{
	float	x;
	float	y;
	float	z;
}	t_vec3;

typedef struct s_vec2
{
	float	x;
	float	y;
}	t_vec2;

typedef struct s_point
{
	t_vec3			coord;
	int				color;
}	t_point;

typedef struct s_face
{
	t_array	points;
}	t_face;

#endif