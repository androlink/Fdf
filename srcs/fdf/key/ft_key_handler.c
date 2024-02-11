/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 03:50:45 by gcros             #+#    #+#             */
/*   Updated: 2024/02/11 02:19:42 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include <stddef.h>
#include "put.h"

int	ft_key_handler(int key, void *param)
{
	if (key == 65307)
		ft_fdf_stop(param);
	ft_putnbr_fd(key, 2);
	return (0);
}
