/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 01:17:23 by gcros             #+#    #+#             */
/*   Updated: 2024/02/11 01:03:50 by gcros            ###   ########.fr       */
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
	t_vector	*faces;
}	t_object;

typedef struct s_projection
{
	t_vec3	rot_vec;
	t_vec3	trans_vec;
	t_mat4	mat_proj;
}	t_projection;

typedef struct s_fdf
{
	t_window		window;
	t_projection	projection;
	t_object		object;
}	t_fdf;

//fdf function
int			ft_fdf_init(t_fdf *fdf);
void		ft_fdf_destroy(t_fdf *fdf);
int			ft_fdf_exit(t_fdf *fdf);

//window function
int			window_init(t_window *win);
void		window_destroy(t_window *win);

//projection function
int			ft_projection_init(t_projection *projection);

//object function
int	ft_load_object(t_object *obj, t_array *to_parse);

//event function
void		event_key(t_fdf *fdf);
int			ft_key_handler(int key, void *param);

#endif