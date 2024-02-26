/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 18:02:47 by gcros             #+#    #+#             */
/*   Updated: 2024/02/26 22:39:46 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "num.h"
#include "ft_printf.h"

static t_fdf_err	load_map(t_vector *points, t_array *map);
static t_fdf_err	load_line(char *line, t_vector *points, size_t y);
static t_fdf_err	load_point(char *line, t_point *point);

void	free_points(t_vector *points)
{
	size_t	i;

	i = 0;
	while (i < points->size)
	{
		ft_vec_destroy(&((t_vector *)points->data)[i]);
		i++;
	}
	ft_vec_destroy(points);
}

t_fdf_err	ft_fdf_parser(t_object *obj, t_array *map)
{
	t_vector	points;
	t_fdf_err	err;

	if (ft_vec_init(&points, sizeof(t_vector)) == 0)
		return (look_errno);
	err = load_map(&points, map);
	if (err == nothing_append)
		err = get_obj(obj, &points);
	free_points(&points);
	return (err);
}

static t_fdf_err	load_map(t_vector *points, t_array *map)
{
	size_t		i;
	t_fdf_err	err;
	t_vector	line;

	i = 0;
	while (i < map->size)
	{
		if (ft_vec_init(&line, sizeof(t_point)) == 0)
			return (look_errno);
		err = load_line(map->data[i], &line, i);
		if (err != nothing_append)
		{
			ft_vec_destroy(&line);
			return (err);
		}
		if (ft_vec_append(points, &line) == 0)
		{
			ft_vec_destroy(&line);
			return (look_errno);
		}
		i++;
	}
	return (nothing_append);
}

static t_fdf_err	load_line(char *line, t_vector *points, size_t y)
{
	t_point		point;
	char		*str_point;
	t_fdf_err	err;
	size_t		x;

	str_point = ft_strtok(line, " \n");
	x = 0;
	while (str_point != NULL)
	{
		point = (t_point){{x, y, 0}, 0};
		err = load_point(str_point, &point);
		if (err != nothing_append)
			return (err);
		if (ft_vec_append(points, &point) == 0)
			return (look_errno);
		str_point = ft_strtok(NULL, " \n");
		x++;
	}
	return (nothing_append);
}

static t_fdf_err	load_point(char *str_point, t_point *point)
{
	char	*str_color;

	point->coord.z = ft_atoi(str_point);
	str_color = ft_strchr(str_point, ',');
	if (str_color == NULL)
	{
		point->color = 0XFFFFFF;
		return (nothing_append);
	}
	point->color = 0XFFFFFF;
	return (nothing_append);
}
