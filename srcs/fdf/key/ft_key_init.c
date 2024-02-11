/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 00:59:05 by gcros             #+#    #+#             */
/*   Updated: 2024/02/08 01:06:52 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"

void	event_key(t_fdf *fdf)
{
	mlx_hook(fdf->window.win_ptr, 17, 1L << 1, ft_fdf_exit, fdf);
	mlx_key_hook(fdf->window.win_ptr, ft_key_handler, fdf);
}