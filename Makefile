NAME = fdf

CC = cc
RMF = rm -f

CFLAGS = -Wall -Wextra -Werror
DFLAGS = -MMD -MP

HDIR	=	includes
SDIR	=	srcs
BDIR	=	.build
DDIR	=	.build


SRCS_FILES := fdf.c
#	fdf files
SRCS_FILES += fdf/ft_fdf_init.c
SRCS_FILES += fdf/ft_fdf_destroy.c
#	key files
SRCS_FILES += ft_key_handler.c
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

LIBFTDIR = libft-1.1
LIBFTNAME = ft
LIBFTAR = libft.a
LIBFTPATH = $(LIBFTDIR)/$(LIBFTAR)
LIBFTINCLUDES =  -I $(LIBFTDIR)/includes/
LIBFTFLAGS = -L $(LIBFTDIR)/ -l $(LIBFTNAME) $(LIBFTINCLUDES)

MLXDIR = minilibx-linux
MLXNAME = mlx
MLXAR = minilibx.a
MLXPATH = $(MLXDIR)/$(MLXAR)
MLXINCLUDE = -I $(MLXDIR)/
MLXFTFLAGS = -L $(MLXDIR)/ -l $(MLXNAME) $(MLXINCLUDE) -lXext -lX11

all : $(NAME)

$(NAME) : $(OBJS) | $(MLXPATH) $(LIBFTPATH)
	$(CC) $(CFLAGS) -o $@ $(OBJS) -I $(HDIR)/ $(LIBFTFLAGS) $(MLXFTFLAGS)


$(BDIR)/%.o		:	$(SDIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(DFLAGS) -c $< -o $@ -I $(HDIR)/ $(LIBFTINCLUDES) $(MLXINCLUDE)

clean	:
	$(RMF) $(OBJS) $(DEPS)

$(MLXPATH)	: force
	$(MAKE) -C $(MLXDIR)

$(LIBFTPATH)	: force
	$(MAKE) -C $(LIBFTDIR)

re		:	fclean
	$(MAKE) all

fclean	:	clean
	$(MAKE) clean -C $(MLXDIR)
	$(MAKE) fclean -C $(LIBFTDIR)
	$(RMF) $(NAME)

force :
