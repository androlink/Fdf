/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertex.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 02:46:37 by gcros             #+#    #+#             */
/*   Updated: 2024/02/07 05:06:04 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VERTEX_H
# define VERTEX_H

# include "vector.h"

typedef double	t_vec3[3];
typedef double	t_vec2[2];
typedef double	t_mat4[4][4];

typedef struct s_point
{
	t_vec3			world_point;
	t_vec3			view_point;
	t_vec2			proj_point;
	unsigned char	color[4];
}	t_point;

typedef struct s_face
{
	t_vector	points;
}	t_face;

#endif