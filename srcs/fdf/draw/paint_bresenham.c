/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint_bresenham.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 23:16:58 by gcros             #+#    #+#             */
/*   Updated: 2024/02/26 23:06:31 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "num.h"

void	bresenham_high(t_point *p1, t_point *p2, t_img *img)
{
	const float	dy = p2->coord.y - p1->coord.y;
	float		dx;
	float		xi;
	float		d;
	t_vec2		p;

	dx = p2->coord.x - p1->coord.x;
	xi = 1;
	if (dy < 0)
		xi = -1;
	if (dy < 0)
		dx = -dx;
	d = (2. * dx) - dy;
	p = (t_vec2){p1->coord.x, p1->coord.y};
	while (p.y < p2->coord.y)
	{
		paint_pixel(&(t_point){{p.x, p.y, 0}, 0}, img);
		if (d > 0)
			p.x += xi;
		if (d > 0)
			d = d + (2. * (dx - dy));
		else
			d = d + 2. * dx;
		p.y++;
	}
}

void	bresenham_low(t_point *p1, t_point *p2, t_img *img)
{
	const float	dx = p2->coord.x - p1->coord.x;
	float		dy;
	float		yi;
	float		d;
	t_vec2		p;

	dy = p2->coord.y - p1->coord.y;
	yi = 1;
	if (dy < 0)
		yi = -1;
	if (dy < 0)
		dy = -dy;
	d = (2. * dy) - dx;
	p = (t_vec2){p1->coord.x, p1->coord.y};
	while (p.x < p2->coord.x)
	{
		paint_pixel(&(t_point){{p.x, p.y, 0}, 0}, img);
		if (d > 0)
			p.y += yi;
		if (d > 0)
			d = d + (2. * (dy - dx));
		else
			d = d + 2. * dy;
		p.x++;
	}
}

void	bresenham_line(t_point *p1, t_point *p2, t_img *img)
{
	if (p1->coord.z > 1 || p2->coord.z > 1)
		return ;
	if (ft_absf(p2->coord.y - p1->coord.y) < ft_absf(p2->coord.x - p1->coord.x))
	{
		if (p1->coord.x > p2->coord.x)
			bresenham_low(p2, p1, img);
		else
			bresenham_low(p1, p2, img);
	}
	else
	{
		if (p1->coord.y > p2->coord.y)
			bresenham_high(p2, p1, img);
		else
			bresenham_high(p1, p2, img);
	}
}

void	draw_bresenham(t_object *obj, t_img *img)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < obj->y)
	{
		x = 0;
		while (x < obj->x)
		{
			if (y < obj->y - 1)
				bresenham_line(&obj->points[y * obj->x + x],
					&obj->points[(y + 1) * obj->x + x],
					img);
			if (x < obj->x - 1)
				bresenham_line(&obj->points[y * obj->x + x],
					&obj->points[y * obj->x + x + 1],
					img);
			x++;
		}
		y++;
	}
}
