/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_view.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 17:49:53 by gcros             #+#    #+#             */
/*   Updated: 2024/02/23 16:39:47 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>
#include <stdio.h>

t_mat4	get_view_mat(t_projection *proj)
{
	t_mat4	view_mat;

	ft_bzero(&view_mat, sizeof(t_mat4));
	view_mat = get_ident_mat();
	view_mat = ft_mat4_mul(get_rot_mat(&proj->rot_view), view_mat);
	view_mat = ft_mat4_mul(get_trans_mat(&proj->trans_view), view_mat);
	return (view_mat);
}