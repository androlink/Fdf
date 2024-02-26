/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 00:59:05 by gcros             #+#    #+#             */
/*   Updated: 2024/02/26 22:57:24 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include "put.h"
#include "key.h"

int	key_pressed(int key, t_fdf *fdf)
{
	if (key == 65307)
		fdf_stop(fdf);
	if (key == 65289)
	{
		ft_bzero(&fdf->projection, sizeof(t_projection));
		model_init(&fdf->projection);
		view_init(&fdf->projection);
	}
	switch_proj(key, fdf);
	if (key == 113)
		fdf->control.rot_z_model.x = 1;
	if (key == 100)
		fdf->control.rot_z_model.y = 1;
	if (key == 97)
		fdf->control.rot_x_model.x = 1;
	if (key == 101)
		fdf->control.rot_x_model.y = 1;
	if (key == 122)
		fdf->control.rot_y_model.x = 1;
	if (key == 115)
		fdf->control.rot_y_model.y = 1;
	if (key == 119)
		fdf->control.zoom_model.x = 1;
	if (key == 120)
		fdf->control.zoom_model.y = 1;
	if (key == 105)
		fdf->control.trans_z_view.x = 1;
	if (key == 107)
		fdf->control.trans_z_view.y = 1;
	if (key == 108)
		fdf->control.rot_y_view.x = 1;
	if (key == 106)
		fdf->control.rot_y_view.y = 1;
	if (key == 65438)
		fdf->draw_type = 0;
	if (key == 65436)
		fdf->draw_type = 1;
	if (key == 65433)
		fdf->draw_type = 2;
	return (1);
}

int	key_released(int key, t_fdf *fdf)
{
	if (key == 113)
		fdf->control.rot_z_model.x = 0;
	if (key == 100)
		fdf->control.rot_z_model.y = 0;
	if (key == 97)
		fdf->control.rot_x_model.x = 0;
	if (key == 101)
		fdf->control.rot_x_model.y = 0;
	if (key == 122)
		fdf->control.rot_y_model.x = 0;
	if (key == 115)
		fdf->control.rot_y_model.y = 0;
	if (key == 119)
		fdf->control.zoom_model.x = 0;
	if (key == 120)
		fdf->control.zoom_model.y = 0;
	if (key == 105)
		fdf->control.trans_z_view.x = 0;
	if (key == 107)
		fdf->control.trans_z_view.y = 0;
	if (key == 108)
		fdf->control.rot_y_view.x = 0;
	if (key == 106)
		fdf->control.rot_y_view.y = 0;
	return (1);
}

int	mouse_pressed(int key, int x, int y, t_fdf *fdf)
{
	(void) x; 
	(void) y;
	if (key == 1)
		fdf->control.mouse.x = 1;
	return (1);
}

int	mouse_released(int key, int x, int y, t_fdf *fdf)
{
	(void) x; 
	(void) y;
	if (key == 1)
		fdf->control.mouse.x = 0;
	return (1);
}	

void	event_key(t_fdf *fdf)
{
	mlx_hook(fdf->window.win_ptr, 17, 1L << 1, fdf_stop, fdf);
	mlx_hook(fdf->window.win_ptr, 2, 1L << 0, key_pressed, fdf);
	mlx_hook(fdf->window.win_ptr, 3, 1L << 1, key_released, fdf);
	mlx_hook(fdf->window.win_ptr, 4, 1L << 2, mouse_pressed, fdf);
	mlx_hook(fdf->window.win_ptr, 5, 1L << 3, mouse_released, fdf);
}
