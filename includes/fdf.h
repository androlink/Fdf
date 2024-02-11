/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 01:17:23 by gcros             #+#    #+#             */
/*   Updated: 2024/02/11 05:47:26 by gcros            ###   ########.fr       */
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

typedef enum e_fdf_err
{
	nothing_append,
	no_file,
	bad_file_format,
	bad_file,
	object_parsing,
	init_fail,
	
}	t_fdf_err;

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
	char			*file_to_load;
	t_object		object;
}	t_fdf;

//fdf function
int			ft_fdf_init(t_fdf *fdf);
void		ft_fdf_destroy(t_fdf *fdf);
int			ft_fdf_stop(t_fdf *fdf);
int			ft_fdf_exit(t_fdf_err err_code, t_fdf *fdf);

//error function
int			ft_print_error(t_fdf_err err_code);
const char	*ft_strerr(t_fdf_err err_code);

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