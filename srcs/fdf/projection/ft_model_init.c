/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_model_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 01:56:43 by gcros             #+#    #+#             */
/*   Updated: 2024/02/23 16:34:36 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_model_init(t_projection *projection)
{
	projection->rot_model = ft_get_default_rot();
	projection->trans_model = ft_get_default_trans();
	projection->scale_model = ft_get_default_scale();
	projection->mat_proj = get_iso_proj();
	return (1);
}

t_vec3	ft_get_default_rot(void)
{
	t_vec3	rot;

	rot.x = 3.6;
	rot.y = -8.9;
	rot.z = -2.4;
	return (rot);
}

t_vec3	ft_get_default_trans(void)
{
	t_vec3	trans;

	trans.x = 0;
	trans.y = 0;
	trans.z = 0;
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
