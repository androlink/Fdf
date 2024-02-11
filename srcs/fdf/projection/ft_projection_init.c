/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_projection_init.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 01:56:43 by gcros             #+#    #+#             */
/*   Updated: 2024/02/11 01:06:23 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "arr.h"

int	ft_projection_init(t_projection *projection)
{
	projection->rot_vec = (t_vec3){.2, .2, .2};
	projection->trans_vec = (t_vec3){0, 0, 0};
	return (1);
}