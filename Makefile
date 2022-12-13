# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: albaud <albaud@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/19 14:57:19 by albaud            #+#    #+#              #
#    Updated: 2022/12/12 15:46:08 by albaud           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= miniRT
MAIN 		= dammier.c disperse.c main.c ray_tracing.c uvmapping.c background/gradient.c parser/atoi_life.c parser/init_objs.c parser/init_shapes.c parser/parser.c parser/parser_utils.c shapes/sphere.c utils/debug.c utils/errors.c utils/inputs.c utils/iterate_objects.c utils/v_utils.c
OBJS		= ${MAIN:.c=.o}
LIB 		= koflibc/libft.a vectors/vlib.a
CC			= /usr/bin/gcc
CFLAGS		= -Wall -Wextra -Werror
MINILIBX	= -I /Library/Developer/CommandLineTools/SDKs/MacOSX12.1.sdk/usr/include -I  /usr/X11/include -g -L /usr/X11/lib -l mlx -framework OpenGL -framework AppKit
SANITIZE	= -fsanitize=address -static-libsan

.c.o 	:
		${CC} ${CFLAGS} -I /usr/X11/include -c $< -o ${<:.c=.o}

all		: ${NAME}

$(NAME)	: ${LIB} ${OBJS}
		${CC} ${CFLAGS} ${MINILIBX} -o ${NAME} ${OBJS} ${LIB}

$(LIB)	: 
		make -C koflibc
		make -C vectors

c		:
		find *.c */*.c | grep -v *vectors*| tr '\n' ' ' 

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