/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 03:50:45 by gcros             #+#    #+#             */
/*   Updated: 2024/02/28 05:18:25 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#define XK_MISCELLANY
#define XK_LATIN1
#include <X11/keysymdef.h>

void	key_event(int key, t_fdf *fdf)
{
	if (key == XK_1)
		fdf->projection.mat_proj = get_iso_proj();
	if (key == XK_2)
		fdf->projection.mat_proj = get_pers_proj();
	if (key == XK_KP_Insert)
		fdf->draw_type = 0;
	if (key == XK_KP_End)
		fdf->draw_type = 1;
	if (key == XK_space)
		fdf->control._auto = !fdf->control._auto;
	if (key == XK_Escape)
		fdf_stop(fdf);
	if (key == XK_Tab)
	{
		ft_bzero(&fdf->projection, sizeof(t_projection));
		model_init(&fdf->projection);
		view_init(&fdf->projection);
	}
}

int	key_pressed(int key, t_fdf *fdf)
{
	key_event(key, fdf);
	if (key == XK_s)
		fdf->control.rot_x_view.x = 1;
	if (key == XK_w)
		fdf->control.rot_x_view.y = 1;
	if (key == XK_z)
		fdf->control.zoom_model.x = 1;
	if (key == XK_x)
		fdf->control.zoom_model.y = 1;
	if (key == XK_i)
		fdf->control.trans_z_view.x = 1;
	if (key == XK_k)
		fdf->control.trans_z_view.y = 1;
	if (key == XK_l)
		fdf->control.trans_x_view.x = 1;
	if (key == XK_j)
		fdf->control.trans_x_view.y = 1;
	if (key == XK_o)
		fdf->control.trans_y_view.x = 1;
	if (key == XK_u)
		fdf->control.trans_y_view.y = 1;
	return (1);
}

int	key_released(int key, t_fdf *fdf)
{
	if (key == XK_s)
		fdf->control.rot_x_view.x = 0;
	if (key == XK_w)
		fdf->control.rot_x_view.y = 0;
	if (key == XK_z)
		fdf->control.zoom_model.x = 0;
	if (key == XK_x)
		fdf->control.zoom_model.y = 0;
	if (key == XK_i)
		fdf->control.trans_z_view.x = 0;
	if (key == XK_k)
		fdf->control.trans_z_view.y = 0;
	if (key == XK_l)
		fdf->control.trans_x_view.x = 0;
	if (key == XK_j)
		fdf->control.trans_x_view.y = 0;
	if (key == XK_o)
		fdf->control.trans_y_view.x = 0;
	if (key == XK_u)
		fdf->control.trans_y_view.y = 0;
	return (1);
}
