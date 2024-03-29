SRCS		=	main.c \
				color.c \
				color_get.c \
				complex.c \
				fractal.c \
				mandelbrot.c \
				julia.c \
				render.c \
				manipulate_image.c \
				utils.c \
				hook.c \
				error.c \
				ft_strncmp.c \
				ft_strlen.c \
				ft_memcmp.c \
				ft_isdigit.c \
				ft_atold.c
OBJS		= ${SRCS:.c=.o}
CC			= clang
CFLAGS		= -Wall -Wextra -Werror
INC			= -IminilibX
NAME		= fractol
RM			= rm -f

%.o :		%.c
			${CC} ${CFLAGS} ${INC} -O3 -c -o $@ $<
all :
			cd minilibX && make
			make ${NAME}
${NAME} :	${OBJS}
			${CC} -o ${NAME} ${OBJS} minilibX/libmlx.a -lXext -lX11 -lm
clean :
			${RM} ${OBJS}
fclean :	clean
			${RM} ${NAME}
re :		fclean all
.PHONY :
			all ${NAME} clean fclean re
