/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_parser_ext.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 00:47:57 by gcros             #+#    #+#             */
/*   Updated: 2024/02/20 03:11:55 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_fdf_err	check_dim(t_vector *points);
static t_fdf_err	center_map(t_vector *points);
static t_fdf_err	to_obj(t_object *obj, t_vector *points);

t_fdf_err	get_obj(t_object *obj, t_vector *points)
{
	t_fdf_err err;
	
	err = check_dim(points);
	if (err != nothing_append)
		return (err);
	center_map(points);
	err = to_obj(obj, points);
	if (err != nothing_append)
		return (err);
	return (nothing_append);
}

static t_fdf_err	to_obj(t_object *obj, t_vector *points)
{
	size_t	i;
	size_t	j;

	obj->y = points->size;
	obj->x = ((t_vector *)points->data)[0].size;
	obj->points = malloc(obj->x * obj->y * sizeof(t_point));
	
	if (obj->points == NULL)
		return (look_errno);
	j = 0;
	while (j < obj->y)
	{
		i = 0;
		while (i < obj->x)
		{
			obj->points[j * obj->x + i] = ((t_point *)((t_vector *)points->data)[j].data)[i];
			i++;
		}
		j++;
	}
	return (nothing_append);
}

static t_fdf_err	center_map(t_vector *points)
{
	size_t	y;
	size_t	i;
	size_t	j;
	size_t	x;

	j = 0;
	y = points->size;
	x = ((t_vector *)points->data)[0].size;
	while (j < y)
	{
		i = 0;
		while (i < x)
		{
			((t_point *)((t_vector *)points->data)[j].data)[i].coord.x -= (x - 1.f) / 2.0f;
			((t_point *)((t_vector *)points->data)[j].data)[i].coord.y -= (y - 1.f) / 2.0f;
			i++;
		}
		j++;
	}
	return (nothing_append);
}

static t_fdf_err	check_dim(t_vector *points)
{
	size_t	y;
	size_t	i;
	size_t	x;
	
	y = points->size;
	if (y == 0)
		return (object_parsing);
	x = ((t_vector *)points->data)[0].size;
	i = 1;
	while (i < y)
	{
		if (((t_vector *)points->data)[i].size != x)
			return (object_parsing);
		i++;
	}
	if (x == 0 || (x == 1 && y == 1))
		return (object_parsing);
	return (nothing_append);
}
