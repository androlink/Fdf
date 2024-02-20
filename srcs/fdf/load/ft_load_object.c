/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_object.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 00:52:14 by gcros             #+#    #+#             */
/*   Updated: 2024/02/19 18:24:35 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "str.h"
#include "mlx.h"

static t_fdf_err (*get_parser(char *ext))(t_object *, t_array *);

t_fdf_err	ft_load_object(t_object *obj, t_array *to_parse, char *ext)
{
	t_fdf_err (*parser_func)(t_object *, t_array *);
	t_fdf_err	err;


	parser_func = get_parser(ext);
	if (parser_func == NULL)
	{
		return (no_parsing_func);
	}
	err = parser_func(obj, to_parse);
	return (err);
}

static t_fdf_err (*get_parser(char *ext))(t_object *, t_array *)
{
	if (ext == NULL)
		return (NULL);
	if (ft_strncmp(ext, ".fdf", 5) == 0)
		return (&ft_fdf_parser);
	return (NULL);
}