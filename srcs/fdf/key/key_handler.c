/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 03:50:45 by gcros             #+#    #+#             */
/*   Updated: 2024/02/27 23:39:44 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include <stddef.h>
#include "put.h"

void	switch_proj(int key, void *param)
{
	if (key == 38)
		((t_fdf *)param)->projection.mat_proj = get_iso_proj();
	if (key == 233)
		((t_fdf *)param)->projection.mat_proj = get_pers_proj();
}
