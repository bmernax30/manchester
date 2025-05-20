CC= gcc

all: clean build

build:
	@mkdir build
	@${CC} main.c -o build/encode

clean:
	@rm -rf build