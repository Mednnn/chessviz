programa: bin/programa

test: bin/programa_test



build/programa_test.o: test/main.c build
	gcc -I thirdparty -I src -c test/main.c -o build/programa_test.o
build/main.o: src/main.c build
	gcc  -Wall -Werror -c src/main.c -o build/main.o
build/board.o: src/board.c build
	gcc -Wall -Werror -c src/board.c -o build/board.o
build/board_print_plain.o: src/board_print_plain.c
	gcc  -Wall -Werror -c src/board_print_plain.c -o build/board_print_plain.o
bin/programa: build/main.o build/board.o build/board_print_plain.o bin
	gcc -Wall -Werror build/main.o build/board.o build/board_print_plain.o -lm -o bin/programa

bin/programa_test: build/programa_test.o build/board.o build/board_print_plain.o bin
	gcc -Wall -Werror build/programa_test.o build/board.o build/board_print_plain.o -lm -o bin/programa_test


.PHONY : clean


bin:
	mkdir bin

build:
	mkdir build

clean:
	rm -rf bin/*
	rm -rf build/*.o
