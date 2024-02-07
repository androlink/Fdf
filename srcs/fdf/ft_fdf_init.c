/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 01:30:32 by gcros             #+#    #+#             */
/*   Updated: 2024/02/07 05:05:16 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include "stddef.h"
#include <stdlib.h>

static int	window_init(t_window *win);
static void	init_key(t_fdf *fdf);

int	ft_fdf_init(t_fdf *fdf)
{
	if (!window_init(&fdf->window))
		return (0);
	init_key(fdf);
	mlx_hook(fdf->window.win_ptr, 17, 1L << 1, ft_fdf_exit, fdf);
	return (1);
}

static int	window_init(t_window *win)
{
	win->win_ptr = NULL;
	win->mlx_ptr = mlx_init();
	if (win->mlx_ptr == NULL)
		return (0);
	win->win_ptr = mlx_new_window(win->mlx_ptr,
			SCREEN_WIDTH, SCREEN_HEIGHT, "fdf");
	if (win->win_ptr == NULL)
	{
		free(win->mlx_ptr);
		win->mlx_ptr = NULL;
		return (0);
	}
	return (1);
}

static void	init_key(t_fdf *fdf)
{
	mlx_key_hook(fdf->window.win_ptr, ft_key_handler, fdf);
}
