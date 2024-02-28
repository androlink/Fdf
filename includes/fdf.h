/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 01:17:23 by gcros             #+#    #+#             */
/*   Updated: 2024/02/28 05:17:19 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "arr.h"
# include "vertex.h"
# include <string.h>
# include <errno.h>

# ifndef SCREEN_WIDTH
#  define SCREEN_WIDTH 1080
# endif

# ifndef SCREEN_HEIGHT
#  define SCREEN_HEIGHT 800
# endif

# ifndef IMAGE_WIDTH
#  define IMAGE_WIDTH 1080
# endif

# ifndef IMAGE_HEIGHT
#  define IMAGE_HEIGHT 800
# endif

# define FDF_PI 3.1416f

typedef enum e_fdf_ext
{
	no_ext,
	fdf_ext,
}	t_fdf_ext;

typedef enum e_fdf_err
{
	nothing_append,
	no_file,
	bad_file_ext,
	bad_file,
	object_parsing,
	init_fail,
	no_parsing_func,
	look_errno,
}	t_fdf_err;

typedef struct s_img
{
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}	t_img;

typedef struct s_window
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
}	t_window;

typedef struct s_object
{
	t_point	*points;
	size_t	x;
	size_t	y;
}	t_object;

typedef struct s_projection
{
	t_vec3	rot_model;
	t_vec3	trans_model;
	t_vec3	scale_model;
	t_mat4	mat_proj;
	t_vec3	rot_view;
	t_vec3	trans_view;
}	t_projection;

typedef struct s_control
{
	t_vec2	rot_x_model;
	t_vec2	rot_y_model;
	t_vec2	rot_z_model;
	t_vec2	zoom_model;
	t_vec2	trans_x_view;
	t_vec2	trans_y_view;
	t_vec2	trans_z_view;
	t_vec2	rot_y_view;
	t_vec2	rot_x_view;
	t_vec3	mouse;
	t_vec2	scale_z;
	int		_auto;
}	t_control;

typedef struct s_fdf
{
	t_window		window;
	t_projection	projection;
	char			**files_to_load;
	t_object		object;
	t_control		control;
	int				draw_type;
	t_vec2			pmouse;
}	t_fdf;

//fdf function
int			fdf_init(t_fdf *fdf);
void		fdf_destroy(t_fdf *fdf);
int			fdf_stop(t_fdf *fdf);
int			fdf_exit(t_fdf_err err_code, t_fdf *fdf);

//error function
int			print_error(t_fdf_err err_code);
const char	*fdf_strerr(t_fdf_err err_code);

//window function
int			window_init(t_window *win);
void		window_destroy(t_window *win);

//projection function
int			model_init(t_projection *projection);
int			view_init(t_projection *projection);
t_vec3		get_default_trans(void);
t_vec3		get_default_scale(void);
t_vec3		get_default_rot(void);

//load function
int			load_file(t_fdf *fdf, char *file);
t_fdf_err	fdf_parser(t_object *obj, t_array *arr);
char		*ft_strtok(char *str, char *charset);

//object function
t_fdf_err	load_object(t_object *obj, t_array *to_parse, char *ext);
t_fdf_err	get_obj(t_object *obj, t_vector *points);

//event function
void		event_key(t_fdf *fdf);
int			key_pressed(int key, t_fdf *fdf);
int			key_released(int key, t_fdf *fdf);
int			loop(t_fdf *fdf);

//draw function
void		refresh(t_fdf *fdf);
void		paint_pixel(t_point *p, t_img *img);
int			paint(t_object *obj, t_img *img, int draw_type);
int			draw_pixel(t_object *obj, t_img *img);
int			draw_line(t_object *obj, t_img *img);
void		paint_line(t_point *p1, t_point *p2, t_img *img);
int			draw_naive(t_object *obj, t_img *img);

//matrix function
// http://www.opengl-tutorial.org/fr/beginners-tutorials/tutorial-3-matrices/
/* http://www.opengl-tutorial.org/intermediate-tutorials/tutorial-17-quaternion\
s/#how-do-i-apply-a-rotation-to-a-point-*/
// https://automaticaddison.com/how-to-describe-the-rotation-of-a-robot-in-3d/
//	http://www.opengl-tutorial.org/assets/faq_quaternions/index.html#Q11

int			draw(t_object *obj, t_projection *proj, t_img *img, int draw_type);
t_mat4		get_model_mat(t_projection *proj);
t_mat4		get_view_mat(t_projection *proj);
t_mat4		get_rot_mat(t_vec3 *rot_vec);
t_mat4		get_scale_mat(t_vec3 *scale_vec);
t_mat4		get_trans_mat(t_vec3 *trans_vec);
t_mat4		get_ident_mat(void);
t_mat4		fdf_mat4_mul(t_mat4 m1, t_mat4 m2);
t_vec3		fdf_mat4_x_vec3(t_mat4 m1, t_vec3 v1);
t_mat4		get_iso_proj(void);
t_mat4		get_pers_proj(void);

#endif