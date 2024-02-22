/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 03:50:45 by gcros             #+#    #+#             */
/*   Updated: 2024/02/22 17:00:39 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include <stddef.h>
#include "put.h"

void	switch_proj(int key, void *param);

int	ft_key_handler(int key, void *param)
{
	if (key == 65307)
		ft_fdf_stop(param);
	if (key == 65289)
		ft_model_init(&((t_fdf *)param)->projection);
	switch_proj(key, param);
	ft_putnbr_fd(key, 2);
	ft_putstr_fd("\n", 2);
	return (0);
}

void	switch_proj(int key, void *param)
{
	if (key == 38)
		((t_fdf *)param)->projection.mat_proj = get_iso_proj();
	if (key == 233)
		((t_fdf *)param)->projection.mat_proj = get_pers_proj();
}