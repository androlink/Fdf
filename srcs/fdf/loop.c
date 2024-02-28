/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 11:20:35 by gcros             #+#    #+#             */
/*   Updated: 2024/02/28 01:11:43 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"

int	move(t_fdf *fdf)
{
	int	x;
	int	y;

	if (fdf->control.rot_x_model.x)
		fdf->projection.rot_model.x += .1;
	if (fdf->control.rot_x_model.y)
		fdf->projection.rot_model.x -= .1;
	if (fdf->control.rot_y_model.x)
		fdf->projection.rot_model.y += .1;
	if (fdf->control.rot_y_model.y)
		fdf->projection.rot_model.y -= .1;
	if (fdf->control.rot_z_model.x)
		fdf->projection.rot_model.z += .1;
	if (fdf->control.rot_z_model.y)
		fdf->projection.rot_model.z -= .1;
	if (fdf->control.trans_z_view.x)
		fdf->projection.trans_view.z += 5.;
	if (fdf->control.trans_z_view.y)
		fdf->projection.trans_view.z -= 5.;
	if (fdf->control.trans_x_view.x)
		fdf->projection.trans_view.x += 1;
	if (fdf->control.trans_x_view.y)
		fdf->projection.trans_view.x -= 1;
	if (fdf->control.zoom_model.x)
	{
		fdf->projection.scale_model.x *= 1.1f;
		fdf->projection.scale_model.y *= 1.1f;
		fdf->projection.scale_model.z *= 1.1f;
	}
	if (fdf->control.zoom_model.y)
	{
		fdf->projection.scale_model.x /= 1.1f;
		fdf->projection.scale_model.y /= 1.1f;
		fdf->projection.scale_model.z /= 1.1f;
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

	img = &((t_fdf *)fdf)->window.img;
	obj = &((t_fdf *)fdf)->object;
	proj = &((t_fdf *)fdf)->projection;
	move(fdf);
	if (proj->trans_view.z > 0)
		proj->trans_view.z = 0;
	if (draw(obj, proj, img, fdf->draw_type) == 0)
		mlx_loop_end(fdf->window.mlx_ptr);
	refresh(fdf);
	return (0);
}
