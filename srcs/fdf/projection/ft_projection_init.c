/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_projection_init.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 01:56:43 by gcros             #+#    #+#             */
/*   Updated: 2024/02/20 23:21:19 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "arr.h"

int	ft_projection_init(t_projection *projection)
{
	projection->rot_vec = ft_get_default_rot();
	projection->trans_vec = ft_get_default_trans();
	projection->scale_vec = ft_get_default_scale();
	projection->mat_proj = get_iso_proj();
	return (1);
}

t_vec3	ft_get_default_rot(void)
{
	t_vec3	rot;

	rot.x = 0.523599;
	rot.z = 0.523599;
	rot.y = 0.785398;
	return (rot);
	
}

t_vec3	ft_get_default_trans(void)
{
	t_vec3	trans;

	trans.x = IMAGE_WIDTH / 2;
	trans.y = IMAGE_HEIGHT / 2;
	trans.z = 0;
	return (trans);
}

t_vec3	ft_get_default_scale(void)
{
	t_vec3	scale;

	scale.x = 10;
	scale.y = 10;
	scale.z = 2;
	return (scale);
}
