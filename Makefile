SRC= src/fdf.c \
	src/gamemodes/isometry.c \
	src/parsing_map.c \
	src/graphics/bresenham.c \
	src/main.c \
	src/graphics/draw.c \
	src/debug.c \
	src/controls/rotation.c \
	src/controls/keys.c \
	src/graphics/color.c \
	src/interface/button.c \
	src/interface/button_events.c \
	src/interface/main_menu.c \
	src/interface/animation_menu.c \

OBJ=$(SRC:%.c=%.o)
INCDIR=includes/
INCFILES=fdf.h
INC=$(addprefix $(INCDIR), $(INCFILES))

LIBPATH=library/

LFTDIR=libft/
LFTPATH=$(addprefix $(LIBPATH), $(LFTDIR))
LIBFT=libft.a
FTLK=ft

LMLXDIR=minilibx/
LMLXPATH=$(addprefix $(LIBPATH), $(LMLXDIR))
LIBMLX=libmlx.a
MLXLK=mlx
FRAMEWORKS=-framework OpenGL -framework AppKit

ALLINCS=-I$(LFTPATH) -I$(LMLXPATH) -I$(INCDIR)

NAME=fdf

CC=gcc
CFLAGS=-Wall -Wextra -Werror -O3 -g
MAKE=make

all: $(NAME)

$(NAME): $(LFTPATH)$(LIBFT) $(LMLXPATH)$(LIBMLX) $(OBJ) $(INC)
	$(CC) -o $(NAME) $(ALLINCS) -L$(LFTPATH) -l$(FTLK) -L$(LMLXPATH) -l$(MLXLK) $(FRAMEWORKS) $(OBJ)
	-@echo "FdF ready."

%.o: %.c $(INC)
	$(CC) $(CFLAGS)  -o $@ $(ALLINCS) -c $<

$(LFTPATH)$(LIBFT):
	$(MAKE) -C $(LFTPATH)

$(LMLXPATH)$(LIBMLX):
	$(MAKE) -C $(LMLXPATH)

clean:
	$(MAKE) -C $(LFTPATH) clean
	rm -rf $(INCDIR)/*.h.gch
	rm -rf $(OBJ)

fclean: clean
	$(MAKE) -C $(LFTPATH) fclean
	$(MAKE) -C $(LMLXPATH) clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
