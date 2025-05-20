CC= gcc

all: build

build:
	mkdir build
	${CC} -o /build/encode main.c

clean: