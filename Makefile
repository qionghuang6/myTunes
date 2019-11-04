all: main.o linkedlist.o tunelibrary.o
	gcc -o program main.o linkedlist.o tunelibrary.o
main.o: linkedlist.h tunelibrary.h main.c
	gcc -c main.c
linkedlist.o: linkedlist.h linkedlist.c
	gcc -c linkedlist.c
tunelibrary.o: tunelibrary.h tunelibrary.c
	gcc -c tunelibrary.c
run:
	./program
