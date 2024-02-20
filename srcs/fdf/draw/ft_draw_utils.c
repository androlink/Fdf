/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 19:21:13 by gcros             #+#    #+#             */
/*   Updated: 2024/02/21 00:00:41 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include <stdio.h>

t_point	apply_proj(t_point point, t_mat4 *model_mat)
{
	t_point proj_point;

	proj_point.coord = ft_mat4_x_vec3(*model_mat, point.coord);
	proj_point.color = point.color;
	return (proj_point);
}

void ft_draw_pixel(int x, int y, int color, t_img *img)
{
	char	*p;
	if (x < 0 || x >= IMAGE_WIDTH || y < 0 || y >= IMAGE_HEIGHT)
		return ;
	p = img->addr + (y * img->size_line + x * (img->bits_per_pixel / 8));
	*(unsigned int*)p = color;
}

int	get_proj_points(t_object *obj, t_object *proj_obj, t_projection *proj)
{
	size_t	i;
	t_mat4	mvp;
	
	proj_obj->points = ft_calloc(obj->x * obj->y, sizeof(t_point));
	if (proj_obj->points == NULL)
		return (0);
	proj_obj->x = obj->x;
	proj_obj->y = obj->y;
	mvp = ft_mat4_mul(proj->mat_proj, get_model_mat(proj));
	i = 0;
	while (i < obj->y * obj->x)
	{
		proj_obj->points[i] = apply_proj(obj->points[i], &mvp);
		i++;
	}
	return (1);
}

	//while (y < proj_obj.y)
	//{
	//	x = 0;
	//	while (x < proj_obj.x)
	//	{
	//		if (y < proj_obj.y - 1)
	//			ft_line(&proj_obj.points[y * proj_obj.x + x], &proj_obj.points[(y + 1) * proj_obj.x + x], proj, img);
	//		if (x < proj_obj.x - 1)
	//			ft_line(&proj_obj.points[y * proj_obj.x + x], &proj_obj.points[y * proj_obj.x + x + 1], proj, img);
	//		x++;
	//	}
	//	y++;
	//}
	
int	ft_draw(t_object *obj, t_projection *proj, t_img *img)
{
	t_object	proj_obj;
	size_t		i;
	
	ft_bzero(img->addr,img->size_line * IMAGE_HEIGHT);
	if (get_proj_points(obj, &proj_obj, proj) == 0)
		return (0);
	i = 0;
	while (i < proj_obj.x * proj_obj.y)
	{
		ft_draw_pixel(proj_obj.points[i].coord.x, proj_obj.points[i].coord.y, 0XFFFFFF, img);
		i++;
	}
	free(proj_obj.points);
	return (1);
}

void ft_refresh(t_fdf *fdf)
{
	mlx_put_image_to_window(fdf->window.mlx_ptr,
		fdf->window.win_ptr,
		fdf->window.img.img_ptr,
		0, 0);
}