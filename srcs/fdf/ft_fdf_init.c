/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 01:30:32 by gcros             #+#    #+#             */
/*   Updated: 2024/02/11 01:31:39 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include "stddef.h"
#include <stdlib.h>

int	ft_fdf_init(t_fdf *fdf)
{
	ft_bzero(fdf, sizeof(t_fdf));
	if (!ft_projection_init(&fdf->projection))
		return (0);
	if (!window_init(&fdf->window))
		return(0);
	event_key(fdf);
	return (1);
}
