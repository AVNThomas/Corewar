##
## EPITECH PROJECT, 2022
## my_essential
## File description:
## Makefile
##

NAME	=	asm

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

all: asm

asm: ${OBJ}
	${CC} -o ${NAME} ${OBJ} $(LDFLAGS)

clean:
	rm -rf ${OBJ_DIR}
	rm -rf vgcore*

fclean: clean
	rm -rf ${NAME}

re: fclean all

.PHONY: all asm clean fclean re
