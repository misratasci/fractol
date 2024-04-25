NAME = fractol
CC = cc
CFLAGS = -Wall -Wextra -Werror -O3
RM = rm -rf
SRCS = main.c mandelbrot.c julia.c hooks.c mtx.c utils.c
OBJ = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) 

clean:
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

.PHONY = all clean fclean re