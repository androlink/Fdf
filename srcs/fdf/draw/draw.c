/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:32:53 by gcros             #+#    #+#             */
/*   Updated: 2024/02/23 22:03:19 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"

t_point	apply_proj(t_point point, t_mat4 *model_mat)
{
	t_point p;

	p.coord = ft_mat4_x_vec3(*model_mat, point.coord);
	p.color = point.color;
	p.coord.x = (p.coord.x + 1.) * .5 * (float)IMAGE_WIDTH + .5;
	p.coord.y = (p.coord.y + 1.) * .5 * (float)IMAGE_HEIGHT + .5;
	return (p);
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
	mvp = get_ident_mat();
	mvp = ft_mat4_mul(get_model_mat(proj), mvp);
	mvp = ft_mat4_mul(get_view_mat(proj), mvp);
	mvp = ft_mat4_mul(proj->mat_proj, mvp);
	i = 0;
	while (i < obj->y * obj->x)
	{
		proj_obj->points[i] = apply_proj(obj->points[i], &mvp);
		i++;
	}
	return (1);
}
	
int	ft_draw(t_object *obj, t_projection *proj, t_img *img, int draw_type)
{
	t_object	proj_obj;
	
	ft_bzero(img->addr,img->size_line * IMAGE_HEIGHT);
	if (get_proj_points(obj, &proj_obj, proj) == 0)
		return (0);
	paint(&proj_obj, img, draw_type);
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