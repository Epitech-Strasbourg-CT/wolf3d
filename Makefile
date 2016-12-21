##
## Makefile for Makefile in /home/cedric/lib
## 
## Made by Cédric Thomas
## Login   <cedric@epitech.net>
## 
## Started on  Sat Oct 22 10:37:32 2016 Cédric Thomas
## Last update Wed Dec 21 22:20:37 2016 Cédric Thomas
##

SRC	=	main.c			\
		misc.c			\
		type/pixelbuff.c	\
		type/vector.c		\
		type/window.c		\
		src/my_put_pixel.c	\
		src/my_draw_line.c	\
		src/raycast.c		\
		src/trigo.c		\
		src/move_forward.c	\
		draw/draw_square.c	\
		draw/draw_circle.c	\
		disp/disp.c		\
		disp/disp_minimap.c	\
		disp/disp_game.c	\
		parse/parse.c		\
		parse/parse_wolf.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	wolf3d

LIB_F	=	./lib/

LIB	=	-lmy -lc_graph_prog -lm

INCLUDE	=	-I./include/

CFLAGS	+=	 $(INCLUDE) -O3 -g -W -Wall -Wextra


all: $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ) -L$(LIB_F) $(LIB)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re: fclean all

.PHONE: all clean fclean re
