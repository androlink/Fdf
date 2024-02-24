/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint_naive_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 02:27:15 by gcros             #+#    #+#             */
/*   Updated: 2024/02/24 02:47:40 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "num.h"

void	naive_high(t_point *p1, t_point *p2, t_img *img)
{
	float	x;
	float	y;
	float	dx;
	float	dy;

	dx = p2->coord.x - p1->coord.x;
	dy = p2->coord.y - p1->coord.y;
	y = ft_maxf(p1->coord.y, 0);
	while (y < ft_minf(p2->coord.y, IMAGE_HEIGHT))
	{
		x = p1->coord.x + dx * (y - p1->coord.y) / dy;
		paint_pixel(&(t_point){(t_vec3){x, y, 0}, 0}, img);
		y++;
	}
}

void	naive_low(t_point *p1, t_point *p2, t_img *img)
{
	float	x;
	float	y;
	float	dx;
	float	dy;

	dx = p2->coord.x - p1->coord.x;
	dy = p2->coord.y - p1->coord.y;
	x = ft_maxf(p1->coord.x, 0);
	while (x < ft_minf(p2->coord.x, IMAGE_WIDTH))
	{
		y = p1->coord.y + dy * (x - p1->coord.x) / dx;
		paint_pixel(&(t_point){(t_vec3){x, y, 0}, 0}, img);
		x++;
	}
}

void	naive_line(t_point *p1, t_point *p2, t_img *img)
{
	if (p1->coord.z > 1 || p2->coord.z > 1)
		return ;
	if (ft_absf(p2->coord.y - p1->coord.y) < ft_absf(p2->coord.x - p1->coord.x))
	{
		if (p1->coord.x > p2->coord.x)
			naive_low(p2, p1, img);
		else
			naive_low(p1, p2, img);
	}
	else{
		if (p1->coord.y > p2->coord.y)
			naive_high(p2, p1, img);
		else
			naive_high(p1, p2, img);
	}
}


int	draw_naive(t_object *obj, t_img *img)
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
				naive_line(&obj->points[y * obj->x + x],
					&obj->points[(y + 1) * obj->x + x],
					img);
			if (x < obj->x - 1)
				naive_line(&obj->points[y * obj->x + x],
				&obj->points[y * obj->x + x + 1],
				img);
			x++;
		}
		y++;
	}
	return (1);
}