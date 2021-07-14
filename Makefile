SRCS		=	main.c \
				color.c \
				mandelbrot.c
OBJS		= ${SRCS:.c=.o}
CC			= clang
#CFLAGS		= -Wall -Wextra -Werror
CFLAGS		=
INC			= -IminilibX
NAME		= fractol
RM			= rm -f

%.o :		%.c
			${CC} ${CFLAGS} ${INC} -c -o $@ $<
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
