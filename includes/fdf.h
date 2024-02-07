/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 01:17:23 by gcros             #+#    #+#             */
/*   Updated: 2024/02/07 05:06:58 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "arr.h"
# include "vertex.h"

# ifndef SCREEN_WIDTH
#  define SCREEN_WIDTH 400
# endif

# ifndef SCREEN_HEIGHT
#  define SCREEN_HEIGHT 300
# endif

# ifndef IMAGE_WIDTH
#  define IMAGE_WIDTH 400
# endif

# ifndef IMAGE_HEIGHT
#  define IMAGE_HEIGHT 300
# endif

typedef struct s_window
{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_window;

typedef struct s_object
{
	t_vector	faces;	//t_face array
}	t_object;

typedef struct s_world
{
	t_array	object;		//t_object array
	t_mat4	mat_proj;
}	t_world;

typedef struct s_fdf
{
	t_window	window;
}	t_fdf;

int		ft_fdf_init(t_fdf *fdf);
void	ft_fdf_destroy(t_fdf *fdf);
int		ft_fdf_exit(t_fdf *fdf);

int		ft_key_handler(int key, void *param);

#endif