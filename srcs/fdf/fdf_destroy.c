/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_destroy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 02:48:17 by gcros             #+#    #+#             */
/*   Updated: 2024/02/19 19:40:01 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include <stddef.h>
#include <stdlib.h>

void	fdf_destroy(t_fdf *fdf)
{
	window_destroy(&fdf->window);
	free(fdf->object.points);
}
