/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 11:20:35 by gcros             #+#    #+#             */
/*   Updated: 2024/02/23 00:33:32 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int	move(t_fdf *fdf)
{
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
		fdf->projection.rot_view.x += 10;
	if (fdf->control.transZ_view.y)
		fdf->projection.rot_view.x -= 10;
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
	return (1);
}

int	loop(void *fdf)
{
	static size_t	i;
	t_img *img = &((t_fdf *)fdf)->window.img;
	t_projection *proj = &((t_fdf *)fdf)->projection;
	t_object *obj = &((t_fdf *)fdf)->object;
	//((t_fdf *)fdf)->projection.rot_model.x += 0.01f;
	//((t_fdf *)fdf)->projection.rot_model.y -= 0.2f;
	//((t_fdf *)fdf)->projection.rot_model.z += 0.1f;
	((t_fdf *)fdf)->projection.trans_model.x += 1.f;
	((t_fdf *)fdf)->projection.trans_model.x = (int)((t_fdf *)fdf)->projection.trans_model.x % IMAGE_WIDTH;
	move(fdf);
	ft_draw(obj, proj, img);
	ft_refresh(fdf);
	//printf("rot %ld : %f, %f, %f\n", i, proj->rot_model.x, proj->rot_model.y, proj->rot_model.z);
	printf("trans view%ld : %f, %f, %f\n", i, proj->trans_view.x, proj->trans_view.y, proj->trans_view.z);
	//if (i % 2)
	//	((t_fdf *)fdf)->projection.rot_model.z += 0.015f;
	//else
	//	((t_fdf *)fdf)->projection.rot_model.z -= 0.015f;
	i = (i + 1) % 2;
	return (0);
}