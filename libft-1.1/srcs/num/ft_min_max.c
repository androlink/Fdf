/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min_max.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 23:22:01 by gcros             #+#    #+#             */
/*   Updated: 2024/02/24 02:52:50 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

float	ft_minf(float n1, float n2)
{
	if (n1 < n2)
		return (n1);
	return (n2);
}

float	ft_maxf(float n1, float n2)
{
	if (n1 > n2)
		return (n1);
	return (n2);
}
