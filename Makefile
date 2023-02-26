#Makefile for my_shell

my_shell: main.o get_line.o parser.o
	gcc -o my_shell main.o get_line.o parser.o

main.o: main.c
	gcc -c main.c

get_line.o: get_line.c
	gcc -c get_line.c

parser.o: parser.c
	gcc -c parser.c 

clean:
	rm -f *.o my_shell