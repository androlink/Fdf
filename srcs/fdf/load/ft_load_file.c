/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 01:12:12 by gcros             #+#    #+#             */
/*   Updated: 2024/02/12 15:08:38 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "str.h"
#include "fcntl.h"
#include "get_next_line.h"
#include "ft_printf.h"

int		check_ext(char *file);
void	error_catch(t_fdf *fdf, t_fdf_err err_code, t_array *arr);
int		get_file(t_array *arr, int fd);

int	ft_load_file(t_fdf *fdf, char *file)
{
	t_array	*arr;
	int	fd;
	
	arr = NULL;
	fd = -1;
	if (check_ext(file) == 0)
		error_catch(fdf, bad_file_ext, arr);
	arr = ft_arr_new(20);
	if (arr == NULL)
		error_catch(fdf, init_fail, arr);
	fd = open(file, O_RDONLY);
	if (get_file(arr, fd) == 0)
		error_catch(fdf, no_file, arr);
	error_catch(NULL, nothing_append, arr);
	return (1);
}

int get_file(t_array *arr, int fd)
{
	char *line;
	
	if (fd == -1)
		return (0);
	line = get_next_line(fd);
	while (line != NULL)
	{
		ft_arr_append(arr, line);
		line = get_next_line(fd);
	}
	close(fd);
	return (1);
}

void	error_catch(t_fdf *fdf, t_fdf_err err_code, t_array *arr)
{
	if (arr != NULL)
		ft_arr_free(&arr, free);
	if (fdf != NULL)
		ft_fdf_exit(err_code, fdf);
}

int	check_ext(char *file)
{
	char	*ext;

	ext = ft_strrchr(file, '.');
	if (ext == NULL)
		return (0);
	ft_printf("%s\n", file);
	if (ft_strncmp(ext, ".fdf", 5) == 0)
		return (1);
	return (0);
}