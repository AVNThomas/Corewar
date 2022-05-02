##
## EPITECH PROJECT, 2022
## my_essential
## File description:
## Makefile
##

NAME	=	asm

CC	=	gcc

SRCS	=	src/main.c\

SRCS_TEST	=	tests/tests_asm.c\

CFLAGS	=	-Wall -Werror -Wextra -fanalyzer -Wundef -g

LIB_DIR	=	../lib/
LIB	=	my

LIB_TEST	=	criterion

LDFLAGS	=	-L ${LIB_DIR} -l ${LIB}

OBJ_DIR	=	.obj/
OBJ	=	$(addprefix ${OBJ_DIR}, $(SRCS:.c=.o))

exclude	=	${OBJ}/src/main.o
OBJ_TEST	=	$(addprefix ${OBJ_DIR}, $(SRCS_TEST:.c=.o))
OBJ_TEST	+=	$(filter-out ${exclude}, $(OBJ))

${OBJ_DIR}%.o : %.c
	mkdir -p ${@D}
	$(CC) -c ${CFLAGS} $< -o $@

all: ${NAME}

${NAME}: ${OBJ}
	${CC} -o ${NAME} ${OBJ} $(LDFLAGS)

tests_run: ${OBJ_TEST}
	${CC} -o ${NAME}_test ${OBJ_TEST} ${LDFLAGS}

clean:
	rm -rf ${OBJ_DIR}
	rm -rf vgcore*

fclean: clean
	rm -rf ${NAME}

re: fclean all

.PHONY: all clean fclean re
