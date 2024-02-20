/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 00:53:39 by gcros             #+#    #+#             */
/*   Updated: 2024/02/19 19:29:48 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"

int	window_init(t_window *win)
{
	win->mlx_ptr = mlx_init();
	if (win->mlx_ptr == NULL)
		return (0);
	win->win_ptr = mlx_new_window(win->mlx_ptr,
			SCREEN_WIDTH, SCREEN_HEIGHT, "fdf");
	if (win->win_ptr == NULL)
		return (0);
	win->img.img_ptr = mlx_new_image(win->mlx_ptr, IMAGE_WIDTH, IMAGE_HEIGHT);
	if (win->img.img_ptr == NULL)
		return (0);
	win->img.addr = mlx_get_data_addr(win->img.img_ptr,
			&win->img.bits_per_pixel,
			&win->img.size_line,
			&win->img.endian);
	if (win->img.addr == NULL)
		return (0);
	return (1);
}
