/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:36:45 by gcros             #+#    #+#             */
/*   Updated: 2024/02/22 16:06:04 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"

void	paint_pixel(t_point *point, t_img *img)
{
	char	*p;
	const int	x = point->coord.x;
	const int	y = point->coord.y;
	
	if (x < 0 || x >= IMAGE_WIDTH || y < 0 || y >= IMAGE_HEIGHT)
		return ;
	p = img->addr + (y * img->size_line + x * (img->bits_per_pixel / 8));
	*(unsigned int*)p = 0XFFFFFF;
}

void	paint_line(t_point *p1, t_point *p2, t_img *img)
{
	(void)p1;
	(void)p2;
	(void)img;
	
}