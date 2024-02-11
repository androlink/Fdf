NAME = fdf

CC = cc
RMF = rm -f

DEBUG_FLAGS := -g3
CFLAGS := -Wall -Wextra -Werror
DFLAGS = -MMD -MP

ifdef debug
	CFLAGS+= -g3
endif

HDIR	=	includes
SDIR	=	srcs
BDIR	=	.build
DDIR	=	.build


SRCS_FILES := fdf.c
#	fdf files
SRCS_FILES += fdf/ft_fdf_init.c
SRCS_FILES += fdf/ft_fdf_destroy.c
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

SRCS = ${addprefix $(SDIR)/, $(SRCS_FILES)}

OBJS = $(SRCS_FILES:%.c=$(DDIR)/%.o)

DEPS = $(SRCS_FILES:%.c=$(DDIR)/%.d)

LIB_PATH :=
LIB_INCLUDE :=
LIB_FLAGS :=

all : $(NAME)

include libft.mk
include mlx.mk

$(NAME) : $(OBJS) | $(LIB_PATH) 
	$(CC) $(CFLAGS) -o $@ $(OBJS) -I $(HDIR)/ $(LIB_FLAGS)

$(BDIR)/%.o		:	$(SDIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(DFLAGS) -c $< -o $@ -I $(HDIR)/ $(LIB_INCLUDE)

clean	::
	$(RMF) $(OBJS) $(DEPS)

$(MLXPATH)	: force
	$(MAKE) -C $(MLXDIR)

re		:	fclean
	$(MAKE) all

fclean	::	clean
	$(RMF) $(NAME)

force :
