NAME = fractol
CC = cc
CFLAGS = -Wall -Wextra -Werror -O3
RM = rm -rf
SRCS = main.c mandelbrot.c julia.c hooks.c utils.c checks.c \
		libft/ft_atoi.c libft/ft_split.c libft/ft_strjoin.c libft/ft_strlen.c \
		libft/ft_atod.c libft/ft_isdigit.c libft/ft_strncmp.c
OBJ = $(SRCS:.c=.o)
MLX_DIR = minilibx_opengl_20191021/
MLX = $(MLX_DIR)libmlx.a

all: $(MLX) $(NAME)

$(MLX):
	make -C $(MLX_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -I $(MLX_DIR) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) -L $(MLX_DIR) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	make clean -C $(MLX_DIR)
	$(RM) $(SRCS:.c=.o)

fclean: clean
	$(RM) $(NAME)

re: fclean all

git:
	@make fclean
	@git add .
	@git status
	@read -p "Enter commit message: " message; \
	git commit -m "$$message"
	@git push
	@git log

.PHONY = all clean fclean re git