/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 11:20:35 by gcros             #+#    #+#             */
/*   Updated: 2024/02/28 05:22:14 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"

void	view_move(t_fdf *fdf)
{
	if (fdf->control.rot_x_view.x)
		fdf->projection.rot_view.x -= .001;
	if (fdf->control.rot_x_view.y)
		fdf->projection.rot_view.x += .001;
	if (fdf->control.trans_z_view.x)
		fdf->projection.trans_view.z += 5.;
	if (fdf->control.trans_z_view.y)
		fdf->projection.trans_view.z -= 5.;
	if (fdf->control.trans_x_view.x)
		fdf->projection.trans_view.x += 1.;
	if (fdf->control.trans_x_view.y)
		fdf->projection.trans_view.x -= 1.;
	if (fdf->control.trans_y_view.x)
		fdf->projection.trans_view.y += 1.;
	if (fdf->control.trans_y_view.y)
		fdf->projection.trans_view.y -= 1.;
	if (fdf->control._auto)
		fdf->projection.rot_view.y -= .001;
}

int	move(t_fdf *fdf)
{
	int	x;
	int	y;

	view_move(fdf);
	if (fdf->control.zoom_model.x)
	{
		fdf->projection.scale_model.x *= 1.01f;
		fdf->projection.scale_model.y *= 1.01f;
		fdf->projection.scale_model.z *= 1.01f;
	}
	if (fdf->control.zoom_model.y)
	{
		fdf->projection.scale_model.x /= 1.01f;
		fdf->projection.scale_model.y /= 1.01f;
		fdf->projection.scale_model.z /= 1.01f;
	}
	mlx_mouse_get_pos(fdf->window.mlx_ptr, fdf->window.win_ptr, &x, &y);
	if (fdf->control.mouse.x)
	{
		fdf->projection.rot_view.y += (float)(x - fdf->pmouse.x) / 100.;
		fdf->projection.rot_view.x += -(y - fdf->pmouse.y) / 100.;
	}
	fdf->pmouse = (t_vec2){x, y};
	return (1);
}

int	loop(t_fdf *fdf)
{
	t_img			*img;
	t_object		*obj;
	t_projection	*proj;

	img = &fdf->window.img;
	obj = &fdf->object;
	proj = &fdf->projection;
	move(fdf);
	if (proj->trans_view.z > 0)
		proj->trans_view.z = 0;
	if (draw(obj, proj, img, fdf->draw_type) == 0)
		mlx_loop_end(fdf->window.mlx_ptr);
	refresh(fdf);
	return (0);
}
