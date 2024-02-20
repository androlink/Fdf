/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 01:10:09 by gcros             #+#    #+#             */
/*   Updated: 2024/02/20 21:32:16 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"
#include <stdlib.h>
#include "ft_printf.h"

int	loop(void *fdf)
{
	
	t_img *img = &((t_fdf *)fdf)->window.img;
	t_projection *proj = &((t_fdf *)fdf)->projection;
	t_object *obj = &((t_fdf *)fdf)->object;
	//((t_fdf *)fdf)->projection.rot_vec.x += 0.01f;
	//((t_fdf *)fdf)->projection.rot_vec.y -= 0.2f;
	//((t_fdf *)fdf)->projection.rot_vec.z += 0.1f;
	//((t_fdf *)fdf)->projection.trans_vec.x += 1.f;
	//((t_fdf *)fdf)->projection.trans_vec.x = (int)((t_fdf *)fdf)->projection.trans_vec.x % IMAGE_WIDTH;
	ft_draw(obj, proj, img);
	ft_refresh(fdf);
	return (0);
}

int	main(int ac, char **av)
{
	t_fdf	fdf;

	(void) av;
	if (ac == 1)
	{
		ft_fdf_exit(no_file, NULL);
	}
	if (!ft_fdf_init(&fdf))//164 alloc
		ft_fdf_exit(init_fail, &fdf);
	fdf.files_to_load = av + 1;
	ft_load_file(&fdf, av[1]);
	ft_draw(&fdf.object, &fdf.projection, &fdf.window.img);
	ft_refresh(&fdf);
	mlx_loop_hook(fdf.window.mlx_ptr, loop,	&fdf);
	mlx_loop(fdf.window.mlx_ptr);
	ft_fdf_exit(nothing_append , &fdf);
}

int	ft_fdf_exit(t_fdf_err err_code, t_fdf *fdf)
{
	if (fdf != NULL)
		ft_fdf_destroy(fdf);
	ft_print_error(err_code);
	exit(err_code);
}


int	ft_fdf_stop(t_fdf *fdf)
{
	mlx_loop_end(fdf->window.mlx_ptr);
	return (1);
}
