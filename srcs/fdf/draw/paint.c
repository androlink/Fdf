/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:36:45 by gcros             #+#    #+#             */
/*   Updated: 2024/02/24 02:26:02 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include <stdio.h>
#include "num.h"

void	paint_pixel(t_point *point, t_img *img)
{
	char		*p;
	const int	x = point->coord.x;
	const int	y = point->coord.y;

	if (x < 0 || x >= IMAGE_WIDTH || y < 0 || y >= IMAGE_HEIGHT)
		return ;
	p = img->addr + (y * img->size_line + x * (img->bits_per_pixel / 8));
	*(unsigned int *)p = 0XFFFFFF;
}

void	paint_line(t_point *p1, t_point *p2, t_img *img)
{
	float	x;
	float	y;
	float	dx;
	float	dy;

	dx = p2->coord.x - p1->coord.x;
	dy = p2->coord.y - p1->coord.y;
	x = p1->coord.x;
	while (x < p2->coord.x)
	{
		y = p1->coord.y + dy * (x - p1->coord.x) / dx;
		paint_pixel(&(t_point){(t_vec3){x, y, 0}, 0}, img);
		x++;
	}
}
//=============
//	float	x;
//	float	y;
//	float	dx;
//	float	dy;
//	float d;

//	x = p1->coord.x;
//	y = p1->coord.y;
//	dx = p2->coord.x - x;
//	dy = p2->coord.y - y;
//	d = 2 * dy - dx;
//	x = ft_maxf(x, 0);
//	while (x < ft_minf(p2->coord.x, IMAGE_WIDTH))
//	{
//		paint_pixel(&(t_point){(t_vec3){x, y, 0}, 0}, img);
//		if (d > 0)
//			y = y + 1;
//		if (d > 0)
//			d = d - 2 * dx;
//		d = d + 2 * dy;
//		x++;
//	}
//=============