NAME = cub3d

CFLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit -g

LIBFT = make -C libft

SRCS = 	draw_camera.c \
		event.c \
		get_map.c \
		load_texture.c \
		main.c \
		raycasting.c \
		set_camera.c \

OBJS = $(SRCS:.c=.o)

all	:	$(NAME)

$(NAME)	:	$(OBJS)
			$(LIBFT)
			$(CC) $(MLX_FLAGS) $(CFLAGS) -o $(NAME) $(OBJS) libft/libft.a

clean	:
			$(RM) $(OBJS)
			make -C libft clean
fclean	:	clean
			$(RM) cub3d libft/libft.a

re	:	fclean all

.PHONY	:	all clean fclean re