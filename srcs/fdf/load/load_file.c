/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 01:12:12 by gcros             #+#    #+#             */
/*   Updated: 2024/02/26 22:30:14 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "str.h"
#include "fcntl.h"
#include "get_next_line.h"

static int			check_ext(char *file);
static void			error_catch(t_fdf *fdf, t_fdf_err err_code, t_array *arr);
static t_fdf_err	get_file(t_array *arr, int fd);

int	load_file(t_fdf *fdf, char *file)
{
	t_array		*arr;
	t_object	obj;
	int			fd;

	arr = NULL;
	ft_bzero(&obj, sizeof(t_object));
	fd = -1;
	if (check_ext(file) == 0)
		error_catch(fdf, bad_file_ext, arr);
	arr = ft_arr_new(20);
	if (arr == NULL)
		error_catch(fdf, init_fail, arr);
	fd = open(file, O_RDONLY);
	error_catch(fdf, get_file(arr, fd), arr);
	error_catch(fdf, load_object(&obj, arr, ft_strrchr(file, '.')), arr);
	fdf->object = obj;
	ft_arr_free(&arr, free);
	return (1);
}

static t_fdf_err	get_file(t_array *arr, int fd)
{
	char		*line;
	t_fdf_err	err;

	err = nothing_append;
	if (fd == -1)
		return (bad_file);
	errno = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		ft_arr_append(arr, line);
		line = get_next_line(fd);
	}
	if (errno != 0)
		err = look_errno;
	close(fd);
	return (err);
}

static void	error_catch(t_fdf *fdf, t_fdf_err err_code, t_array *arr)
{
	if (err_code == nothing_append)
		return ;
	if (arr != NULL)
		ft_arr_free(&arr, free);
	if (fdf != NULL)
		fdf_exit(err_code, fdf);
}

static int	check_ext(char *file)
{
	char	*ext;

	ext = ft_strrchr(file, '.');
	if (ext == NULL)
		return (0);
	if (ft_strncmp(ext, ".fdf", 5) == 0)
		return (1);
	return (0);
}
