/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 01:10:09 by gcros             #+#    #+#             */
/*   Updated: 2024/02/26 23:15:55 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"
#include <stdlib.h>
#include "ft_printf.h"

int	main(int ac, char **av)
{
	t_fdf	fdf;

	(void) av;
	if (ac != 2)
	{
		fdf_exit(no_file, NULL);
	}
	if (!fdf_init(&fdf))
		fdf_exit(init_fail, &fdf);
	fdf.files_to_load = av + 1;
	load_file(&fdf, av[1]);
	mlx_loop_hook(fdf.window.mlx_ptr, loop, &fdf);
	mlx_loop(fdf.window.mlx_ptr);
	fdf_exit(nothing_append, &fdf);
}

int	fdf_exit(t_fdf_err err_code, t_fdf *fdf)
{
	if (fdf != NULL)
		fdf_destroy(fdf);
	print_error(err_code);
	exit(err_code);
}

int	fdf_stop(t_fdf *fdf)
{
	mlx_loop_end(fdf->window.mlx_ptr);
	return (1);
}
