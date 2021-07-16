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
				error.c
OBJS		= ${SRCS:.c=.o}
CC			= clang
#CFLAGS		= -Wall -Wextra -Werror
CFLAGS		=
INC			= -IminilibX
NAME		= fractol
RM			= rm -f

%.o :		%.c
			${CC} ${CFLAGS} ${INC} -O3 -c -o $@ $<
all :		${NAME}
${NAME} :	${OBJS}
			${CC} -o ${NAME} ${OBJS} minilibX/libmlx.a -lXext -lX11 -lm
clean :
			${RM} ${OBJS}
fclean :	clean
			${RM} ${NAME}
re :		fclean all
.PHONY :
			all ${NAME} clean fclean re
