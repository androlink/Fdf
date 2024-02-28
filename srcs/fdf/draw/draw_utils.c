/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 19:21:13 by gcros             #+#    #+#             */
/*   Updated: 2024/02/28 01:11:45 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"

int	paint(t_object *obj, t_img *img, int draw_type)
{
	if (draw_type == 0)
		draw_naive(obj, img);
	if (draw_type == 1)
		draw_pixel(obj, img);
	return (1);
}

int	draw_pixel(t_object *obj, t_img *img)
{
	size_t		i;

	i = 0;
	while (i < obj->x * obj->y)
	{
		if (obj->points[i].coord.z < 1)
			paint_pixel(&obj->points[i], img);
		i++;
	}
	return (1);
}

int	draw_line(t_object *obj, t_img *img)
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
				paint_line(&obj->points[y * obj->x + x],
					&obj->points[(y + 1) * obj->x + x],
					img);
			if (x < obj->x - 1)
				paint_line(&obj->points[y * obj->x + x],
					&obj->points[y * obj->x + x + 1],
					img);
			x++;
		}
		y++;
	}
	return (1);
}
