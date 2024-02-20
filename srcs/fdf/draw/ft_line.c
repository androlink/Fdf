/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 19:16:18 by gcros             #+#    #+#             */
/*   Updated: 2024/02/20 02:34:24 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "stdio.h"

void ft_line(t_point *p1, t_point *p2, t_projection *proj, t_img *img)
{
	t_point	p3;
	t_point	p4;

	printf("line : p1 %f, %f, %f -> p2 %f, %f, %f\n", p1->coord.x, p1->coord.y, p1->coord.z, p2->coord.x, p2->coord.y, p2->coord.z);
	(void)p4;
	(void)p3;
	(void)proj;
	(void)img;
}

void ft_line_color(t_point *p1, t_point *p2, t_projection *proj, t_img *img)
{
	(void)p1;
	(void)p2;
	(void)proj;
	(void)img;
}