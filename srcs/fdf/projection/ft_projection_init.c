/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_projection_init.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 01:56:43 by gcros             #+#    #+#             */
/*   Updated: 2024/02/20 03:45:50 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "arr.h"

int	ft_projection_init(t_projection *projection)
{
	projection->rot_vec = ft_get_default_rot();
	projection->trans_vec = ft_get_default_trans();
	projection->scale_vec = ft_get_default_scale();
	projection->mat_proj = (t_mat4){{
		{1, 0, 0, 0},
		{0, 1, 0, 0},
		{0, 0, 1, 0},
		{0, 0, 0, 0}
	}};
	return (1);
}

t_vec3	ft_get_default_rot(void)
{
	t_vec3	rot;

	rot.x = 0;
	rot.y = 0;
	rot.z = 3.14f / 4;
	return (rot);
	
}

t_vec3	ft_get_default_trans(void)
{
	t_vec3	trans;

	trans.x = 100;
	trans.y = 100;
	trans.z = 100;
	return (trans);
}

t_vec3	ft_get_default_scale(void)
{
	t_vec3	scale;

	scale.x = 10;
	scale.y = 10;
	scale.z = 10;
	return (scale);
}
