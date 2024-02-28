/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 00:59:05 by gcros             #+#    #+#             */
/*   Updated: 2024/02/28 05:19:07 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"

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
