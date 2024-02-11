/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 01:10:09 by gcros             #+#    #+#             */
/*   Updated: 2024/02/11 01:32:54 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"
#include <stdlib.h>

int	main(int ac, char **av)
{
	t_fdf	fdf;

	(void) ac;
	(void) av;
	if (!ft_fdf_init(&fdf))
		return (-1);
	
	mlx_loop(fdf.window.mlx_ptr);
	ft_fdf_destroy(&fdf);
	return (0);
}

int	ft_fdf_exit(t_fdf *fdf)
{
	mlx_loop_end(fdf->window.mlx_ptr);
	return (1);
}
