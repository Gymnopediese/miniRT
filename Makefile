# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: albaud <albaud@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/19 14:57:19 by albaud            #+#    #+#              #
#    Updated: 2023/05/09 16:42:33 by albaud           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= miniRT
MAIN 		= dammier.c shapes/transform.c shapes/rotation.c shapes/inverse.c utils/threading.c disperse.c main.c ray_tracing.c uvmapping.c background/gradient.c gui/gui.c parser/atoi_life.c parser/init_objs.c parser/init_shapes.c parser/init_shapes_2.c parser/parser.c parser/parser_utils.c shapes/cone.c shapes/cylindre.c shapes/hyperboloid.c shapes/hyperboloid2.c shapes/matrix.c shapes/paraboloid.c shapes/paraboloid2.c shapes/plan.c shapes/sphere.c utils/debug.c utils/errors.c utils/inputs.c utils/iterate_objects.c utils/v_utils.c
OBJS		= ${MAIN:.c=.o}
LIB 		= koflibc/libft.a vector3d/vlib.a
CC			= /usr/bin/gcc -g
CFLAGS		= -Wall -Wextra -Werror
FRAMEWORK	= -framework OpenGL -framework AppKit
LIBS		= -Lminilibx_macos -lmlx -Lkoflibc -lft
SANITIZE	= -fsanitize=address -static-libsan

.c.o 	:
		${CC} ${CFLAGS} -Iminilibx_macos -c $< -o ${<:.c=.o}

all		: ${NAME}

$(NAME)	: ${OBJS}
		make -C koflibc
		make -C vector3d
		${CC} ${CFLAGS} ${LIBS} ${FRAMEWORK} -o ${NAME} ${OBJS} ${LIB}

c		:
		find *.c */*.c | grep -v *vectors* | grep -v *minilibx_macos* | tr '\n' ' ' 

recompile :
	make re -C koflibc
	make re -C minilibx_macos
	make re

clean	:
		rm -f ${OBJS}
fclean	:	clean
		rm -f ${NAME} 
re:		fclean all

lclean	: fclean
		rm -f ${LIB}
relib	: lclean all

leak	: fclean ${LIB}
		${CC} ${CFLAGS} ${SANITIZE} ${MINILIBX} -o ${NAME} ${MAIN} ${LIB}

run		: all
		./miniRT rt_files/test.rt