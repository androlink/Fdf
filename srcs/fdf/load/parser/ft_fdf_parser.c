/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 18:02:47 by gcros             #+#    #+#             */
/*   Updated: 2024/02/14 04:39:02 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_fdf_err	load_map(t_vector *points, t_array *map);
static t_fdf_err	load_line(char *line, t_vector *points);
static t_fdf_err	load_point(char *line, t_point *point);

t_fdf_err ft_fdf_parser(t_object *obj, t_array *map)
{
	t_vector	points;
	t_fdf_err	err;
	
	if (ft_vec_init(&points, sizeof(t_point)) == 0)
		return (look_errno);
	err = load_map(&points, map);
	if (err != nothing_append)
	{
		ft_vec_destroy(&points);
		return (err);
	}
}

static t_fdf_err	load_map(t_vector *points, t_array *map)
{
	size_t		i;
	t_fdf_err	err;

	i = 0;
	while (i < map->size)
	{
		err = load_line(map->data[i], points);
		if (err != nothing_append)
			return (err);
	}
}

static t_fdf_err	load_line(char *line, t_vector *points)
{


	
}

static t_fdf_err	load_point(char *line, t_point *point)
{
	
}
