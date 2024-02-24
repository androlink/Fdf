/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 11:20:35 by gcros             #+#    #+#             */
/*   Updated: 2024/02/23 22:05:49 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include <stdio.h>

int	move(t_fdf *fdf)
{
	int	x;
	int	y;

	if (fdf->control.rotX_model.x)
		fdf->projection.rot_model.x += .1;
	if (fdf->control.rotX_model.y)
		fdf->projection.rot_model.x -= .1;
	if (fdf->control.rotY_model.x)
		fdf->projection.rot_model.y += .1;
	if (fdf->control.rotY_model.y)
		fdf->projection.rot_model.y -= .1;
	if (fdf->control.rotZ_model.x)
		fdf->projection.rot_model.z += .1;
	if (fdf->control.rotZ_model.y)
		fdf->projection.rot_model.z -= .1;
	if (fdf->control.transZ_view.x)
		fdf->projection.trans_view.z += 5.;
	if (fdf->control.transZ_view.y)
		fdf->projection.trans_view.z -= 5.;
	if (fdf->control.rotY_view.x)
		fdf->projection.rot_view.y += .1;
	if (fdf->control.rotY_view.y)
		fdf->projection.rot_view.y -= .1;
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
		//printf("%d, %f, %f\n", x, fdf->pmouse.x, x - fdf->pmouse.x);
		fdf->projection.rot_view.x += -(y - fdf->pmouse.y) / 100.;
		//printf("d %f %f\n", x - fdf->pmouse.x, y - fdf->pmouse.y);
	}
	fdf->pmouse = (t_vec2){x, y};
	return (1);
}

int	loop(t_fdf *fdf)
{
	static size_t	i;
	
	t_img *img = &((t_fdf *)fdf)->window.img;
	t_projection *proj = &((t_fdf *)fdf)->projection;
	t_object *obj = &((t_fdf *)fdf)->object;
	move(fdf);
	if (proj->trans_view.z > 0)
		proj->trans_view.z = 0;
	ft_draw(obj, proj, img, fdf->draw_type);
	ft_refresh(fdf);
	//if (i % 2)
	//	((t_fdf *)fdf)->projection.rot_view.y += 0.015f;
	//else
	//	((t_fdf *)fdf)->projection.rot_view.y -= 0.015f;
	i = (i + 1) % 2;
	return (0);
}
