programa: bin/programa

test: bin/programa_test


build/programa_test.o: test/main.cpp build
	g++ -I thirdparty -I src -c test/main.cpp -o build/programa_test.o

build/main.o: src/main.cpp build
	g++  -Wall -Werror -c src/main.cpp -o build/main.o
build/board.o: src/board.cpp build
	g++ -Wall -Werror -c src/board.cpp -o build/board.o
build/board_print_plain.o: src/board_print_plain.cpp
	g++  -Wall -Werror -c src/board_print_plain.cpp -o build/board_print_plain.o
bin/programa: build/main.o build/board.o build/board_print_plain.o bin
	g++ -Wall -Werror build/main.o build/board.o build/board_print_plain.o -lm -o bin/programa

bin/programa_test: build/programa_test.o build/board.o build/board_print_plain.o bin
	g++ -Wall -Werror build/programa_test.o build/board.o build/board_print_plain.o -lm -o bin/programa_test


.PHONY : clean

bin:
	mkdir bin

build:
	mkdir build

clean:
	rm -rf build
	rm -rf bin	