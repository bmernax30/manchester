PROGRAM_NAME = manchester
CC = gcc
BUILD_DIR = ../build/
INC_DIR = ../includes
OBJ_DIR = objs/
CFLAGS = -Wall -I$(INC_DIR)
OBJS = ${OBJ_DIR}util.o ${OBJ_DIR}encode.o


all: clean objs build

build:
	@mkdir ../build
	@${CC} main.c ${CFLAGS} ${OBJS} -o ${BUILD_DIR}${PROGRAM_NAME}

clean:
	@rm -rf ../build
	@rm -f objs/*.o
	@rm -rf objs

objs:
	@mkdir objs
	@${CC} -c util.c -I${INC_DIR} -o objs/util.o
	@${CC} -c encode.c -I${INC_DIR} -o objs/encode.o
	