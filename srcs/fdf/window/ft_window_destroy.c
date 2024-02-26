/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window_destroy.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 00:53:36 by gcros             #+#    #+#             */
/*   Updated: 2024/02/26 22:55:22 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"

void	window_destroy(t_window *win)
{
	if (win && win->mlx_ptr != NULL)
	{
		if (win->img.img_ptr != NULL)
		{
			mlx_destroy_image(win->mlx_ptr, win->img.img_ptr);
			win->img.img_ptr = NULL;
		}
		if (win->win_ptr != NULL)
		{
			mlx_destroy_window(win->mlx_ptr, win->win_ptr);
			win->win_ptr = NULL;
		}
		mlx_destroy_display(win->mlx_ptr);
		free(win->mlx_ptr);
		win->mlx_ptr = NULL;
	}
}
