programa: bin/programa
build/main.o: src/main.cpp build
	g++  -Wall -Werror -c src/main.cpp -o build/main.o
build/board.o: src/board.cpp build
	g++ -Wall -Werror -c src/board.cpp -o build/board.o
build/board_print_plain.o: src/board_print_plain.cpp
	g++  -Wall -Werror -c src/board_print_plain.cpp -o build/board_print_plain.o
bin/programa: build/main.o build/board.o build/board_print_plain.o bin
	g++ -Wall -Werror build/main.o build/board.o build/board_print_plain.o -lm -o bin/programa

bin:
	mkdir bin

build:
	mkdir build