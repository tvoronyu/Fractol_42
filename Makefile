NAME = fractol

SRC = main.c \
		ft_fractol.c \
		ft_mlx_init_2.c \
		ft_hook.c \
		ft_mandelbrot_1.c \
		ft_threads.c \
		ft_julia_1.c \
		ft_fern.c \
		ft_pixel_color.c \
		ft_trik.c \
		ft_text.c \
		ft_hook_1.c \
		ft_hook_2.c \
		ft_hook_mouse_1.c \
		ft_hook_mouse_2.c \

CC = gcc

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror -I fractol.h

LIBFT = libft/libft.a

IN = -I minilibx_macos

IN_2 = -L minilibx_macos -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) 
	@$(CC) $(IN) $(OBJ) $(FLAGS) $(IN_2) $(LIBFT)  -o $(NAME)
	@printf "\e[32m Fractol finish compile Ok!\n"
	@printf "\e[31m"
	@./fractol

$(OBJ): $(SRC)
	@printf "\e[36m Fractol is creating\n"
	@$(CC) $(FLAGS) -c $(SRC)

$(LIBFT):
	@printf "\e[36m Libft is creating\n"
	@make -C libft/
	@printf "\e[32m Libft is creat Ok!\n"

clean:
	@rm -f $(OBJ)
	@make clean -C libft/
	@printf "\e[33m Clean Ok!\n"

fclean: clean
	@rm -f $(NAME)
	@make fclean -C libft/
	@printf "\e[33m FClean Ok!\n"

re: fclean all
	@printf "\e[32m Make re Ok!\n"