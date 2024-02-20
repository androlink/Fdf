NAME = fdf

CC = gcc
RMF = rm -f

DEBUG_FLAGS := -g3
CFLAGS := -Wall -Wextra -Werror
DFLAGS = -MMD -MP

ifdef debug
	CFLAGS += -g3
endif

HDIR	=	includes
SDIR	=	srcs
BDIR	=	.build
DDIR	=	.build


SRCS_FILES := fdf.c
#	fdf files
SRCS_FILES += fdf/ft_fdf_init.c
SRCS_FILES += fdf/ft_fdf_destroy.c
#	error files
SRCS_FILES += fdf/ft_fdf_error.c
#	window files
SRCS_FILES += fdf/window/ft_window_init.c
SRCS_FILES += fdf/window/ft_window_destroy.c
#	key files
SRCS_FILES += fdf/key/ft_key_handler.c
SRCS_FILES += fdf/key/ft_key_init.c
#	projection files
SRCS_FILES += fdf/projection/ft_projection_init.c
#	vector files
SRCS_FILES += vector/ft_vec_append.c
SRCS_FILES += vector/ft_vec_clear.c
SRCS_FILES += vector/ft_vec_init.c
SRCS_FILES += vector/ft_vec_new.c
SRCS_FILES += vector/ft_vec_resize.c
SRCS_FILES += vector/ft_vec_get.c
SRCS_FILES += vector/ft_vec_destroy.c
#	load files
SRCS_FILES += fdf/load/ft_load_file.c
SRCS_FILES += fdf/load/ft_load_object.c
SRCS_FILES += fdf/load/parser/ft_fdf_parser.c
SRCS_FILES += fdf/load/parser/ft_fdf_parser_ext.c
#	utils files
SRCS_FILES += utils/ft_strtok.c
#	draw files
SRCS_FILES += fdf/draw/ft_draw_utils.c
SRCS_FILES += fdf/draw/ft_draw_line.c
SRCS_FILES += fdf/draw/ft_line.c
SRCS_FILES += fdf/draw/ft_point.c
#	matrix files
SRCS_FILES += fdf/matrix/ft_matrix_calc.c
SRCS_FILES += fdf/matrix/ft_matrix.c
SRCS_FILES += fdf/matrix/projection_mat.c

SRCS = ${addprefix $(SDIR)/, $(SRCS_FILES)}

OBJS = $(SRCS_FILES:%.c=$(BDIR)/%.o)

DEPS = $(SRCS_FILES:%.c=$(DDIR)/%.d)

LIB_PATH :=
LIB_DIR :=
LIB_INCLUDE :=
LIB_FLAGS :=

all : $(NAME)

include mlx.mk
include libft.mk
-include $(DEPS)
LIB_FLAGS += -lm

$(NAME) : $(OBJS) $(LIB_PATH)
	$(CC) $(CFLAGS) -o $@ $(OBJS) -I $(HDIR)/ $(LIB_FLAGS)

$(BDIR)/%.o		:	$(SDIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(DFLAGS) -c $< -o $@ -I $(HDIR)/ $(LIB_INCLUDE)

clean	::
	$(RMF) $(OBJS) $(DEPS)

re		:	fclean
	$(MAKE) all

fclean	::	clean
	$(RMF) $(NAME)

force :

.PHONY: clean re fclean force 