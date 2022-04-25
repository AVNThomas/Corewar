##
## EPITECH PROJECT, 2022
## my_essential
## File description:
## Makefile
##

NAME	=	corewar

CC	=	gcc

SRCS	=	src/main.c\

CFLAGS	=	-Wall -Werror -Wextra -fanalyzer -Wundef -g

LIB_DIR	=	../lib/
LIB	=	my

LDFLAGS	=	-L ${LIB_DIR} -l ${LIB}

OBJ_DIR	=	.obj/
OBJ = $(addprefix ${OBJ_DIR}, $(SRCS:.c=.o))

${OBJ_DIR}%.o : %.c
	mkdir -p ${@D}
	$(CC) -c ${CFLAGS} $< -o $@

all: corewar

corewar: ${OBJ}
	${CC} -o ${NAME} ${OBJ} $(LDFLAGS)

clean:
	rm -rf ${OBJ_DIRJ}
	rm -rf vgcore*

fclean: clean
	rm -rf ${NAME}

re: fclean all

.PHONY: all corewar clean fclean re
