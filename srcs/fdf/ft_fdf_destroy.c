/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_destroy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 02:48:17 by gcros             #+#    #+#             */
/*   Updated: 2024/02/02 03:07:39 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include <stddef.h>
#include <stdlib.h>

static void	window_destroy(t_window *win);

void	ft_fdf_destroy(t_fdf *fdf)
{
	window_destroy(&fdf->window);
}

static void	window_destroy(t_window *win)
{
	if (win->mlx_ptr != NULL)
	{
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
