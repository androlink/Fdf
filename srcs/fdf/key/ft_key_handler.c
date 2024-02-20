/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 03:50:45 by gcros             #+#    #+#             */
/*   Updated: 2024/02/20 23:50:30 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include <stddef.h>
#include "put.h"

static void	rot(int key, void *param);
static void	switch_proj(int key, void *param);
static void	scale(int key, void *param);

int	ft_key_handler(int key, void *param)
{
	if (key == 65307)
		ft_fdf_stop(param);
	if (key == 65289)
		ft_projection_init(&((t_fdf *)param)->projection);
	rot(key, param);
	switch_proj(key, param);
	scale(key, param);
	ft_putnbr_fd(key, 2);
	ft_putstr_fd("\n", 2);
	return (0);
}

static void	scale(int key, void *param)
{
	if (key == 119)
	{
		((t_fdf *)param)->projection.scale_vec.x *= 1.1f;
		((t_fdf *)param)->projection.scale_vec.y *= 1.1f;
		((t_fdf *)param)->projection.scale_vec.z *= 1.1f;
	}
	if (key == 120)
	{
		((t_fdf *)param)->projection.scale_vec.x /= 1.1f;
		((t_fdf *)param)->projection.scale_vec.y /= 1.1f;
		((t_fdf *)param)->projection.scale_vec.z /= 1.1f;
	}
}

static void	rot(int key, void *param)
{
	if (key == 113)
		((t_fdf *)param)->projection.rot_vec.z += .1;
	if (key == 100)
		((t_fdf *)param)->projection.rot_vec.z -= .1;
	if (key == 97)
		((t_fdf *)param)->projection.rot_vec.x += .1;
	if (key == 101)
		((t_fdf *)param)->projection.rot_vec.x -= .1;
	if (key == 122)
		((t_fdf *)param)->projection.rot_vec.y += .1;
	if (key == 115)
		((t_fdf *)param)->projection.rot_vec.y -= .1;
}

static void	switch_proj(int key, void *param)
{
	if (key == 38)
		((t_fdf *)param)->projection.mat_proj = get_iso_proj();
	if (key == 233)
		((t_fdf *)param)->projection.mat_proj = get_pers_proj();
}