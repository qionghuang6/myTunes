all: main.o linkedlist.o tunelibrary.o
	gcc -o program main.o linkedlist.o tunelibrary.o
main.o: linkedlist.h tunelibrary.h
	gcc -c main.c
linkedlist.o: linkedlist.h
	gcc -c linkedlist.c
tunelibrary.o: tunelibrary.h
	gcc -c tunelibrary.c
