NAME = so_long

LIB = libft/libft.a

MILI = /build/libmlx42.a

BOTH	=	${SRCDIR}ft_init_window.c	\
			${SRCDIR}ft_free_alloc.c	\
			${SRCDIR}ft_scenary.c		\

SRC		=	${SRCDIR}ft_so_long.c		\
			${SRCDIR}ft_loop.c			\

BSRC	=	${SRCDIR}ft_so_long_bonus.c	\
			${SRCDIR}ft_loop_bonus.c	\

BOTHOBJ = ${BOTH:${SRCDIR}%.c=${OBJDIR}%.o}
BOBJ = ${BSRC:${SRCDIR}%.c=${OBJDIR}%.o}
OBJ = ${SRC:${SRCDIR}%.c=${OBJDIR}%.o}


SRCDIR = ./
OBJDIR = obj/

FLAGS = -Wall -Wextra -Werror

all : ${NAME}

${LIB}:
	@make bonus -s -C libft

${MILI}:
	@cmake MLX42 -B MLX42/build && make -C MLX42/build -j4

${OBJDIR}:
	@mkdir -p $@

${OBJDIR}%.o: ${SRCDIR}%.c | ${OBJDIR}
	@cc ${FLAGS} -Wunreachable-code -Ofast -o $@ -c $< -I /usr/include -I MLX42
	@echo "\e[0;34m -$@ created."

${NAME}: ${LIB} ${MILI} ${OBJ} ${BOTHOBJ}
	@cc ${FLAGS} -o ${NAME} ${OBJ} ${BOTHOBJ} ${LIB} MLX42/build/libmlx42.a -Iinclude -ldl -lglfw -pthread -lm
	@echo "\e[0;32m -$@ linked\n."

bonus: ${LIB} ${MILI} ${BOBJ} ${BOTHOBJ}
	@cc ${FLAGS} -o ${NAME} ${BOBJ} ${BOTHOBJ} ${LIB} MLX42/build/libmlx42.a -Iinclude -ldl -lglfw -pthread -lm
	@echo "\e[0;32m -$@ linked\n."

clean:
	@rm -rf ${OBJDIR}
	@rm -rf MLX42/build
	@cd libft && make clean
	@echo "\e[0;32m -$@ Removed objets\n."

fclean: clean
	@rm -rf ${NAME}
	@cd libft && make fclean
	@echo "\e[0;32m -$@ Files removed\n."

re : fclean all
	@echo "\e[0;32m -$@ Files reload\n."

.PHONY: re fclean clean all bonus
